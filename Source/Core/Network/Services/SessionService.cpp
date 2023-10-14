/*
    This file is part of Helio music sequencer.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Common.h"
#include "SessionService.h"
#include "JsonSerializer.h"
#include "MainLayout.h"
#include "ProgressTooltip.h"

#if !NO_NETWORK

// Try to update our sliding session after 5 seconds
#define UPDATE_SESSION_TIMEOUT_MS (1000 * 5)

class JsonWebToken final
{
public:

    JsonWebToken(const String &token)
    {
        if (token.isNotEmpty())
        {
            StringArray blocks;
            blocks.addTokens(token, ".", "");
            if (blocks.size() == 3)
            {
                MemoryBlock block;
                {
                    MemoryOutputStream outStream(block, false);
                    Base64::convertFromBase64(outStream, blocks[1]);
                }

                static const JsonSerializer decoder;
                this->jwt = decoder.loadFromString(block.toString());
            }
        }
    }

    const bool isValid() const noexcept
    {
        return this->jwt.isValid();
    }

    const Time getExpiry() const
    {
        if (this->jwt.isValid())
        {
            using namespace Serialization;
            return Time(int64(this->jwt.getProperty(JWT::expiry)) * 1000);
        }

        return {};
    }

    const String getIssuer() const
    {
        if (this->jwt.isValid())
        {
            using namespace Serialization;
            return this->jwt.getProperty(JWT::issuer);
        }

        return {};
    }

private:

    SerializedData jwt;
};

SessionService::SessionService(UserProfile &userProfile) : userProfile(userProfile)
{
    const auto token = this->userProfile.getApiToken();
    if (token.isNotEmpty())
    {
        // Assuming we're using JWT, try to get token expiry:
        const JsonWebToken jwt(token);
        if (jwt.isValid())
        {
            const Time now = Time::getCurrentTime();
            const Time expiry = jwt.getExpiry();
            DBG("Found token expiring at " + expiry.toString(true, true));

            if (expiry < now)
            {
                DBG("Token seems to be expired, removing");
                this->userProfile.clearProfileAndSession();
            }
            else if ((expiry - now).inDays() <= 5)
            {
                DBG("Attempting to re-issue auth token");
                this->prepareTokenUpdateThread()->updateToken(UPDATE_SESSION_TIMEOUT_MS);
            }
            else
            {
                DBG("Token seems to be ok, skipping session update step");
                this->prepareProfileRequestThread()->doRequest(this->userProfile.needsAvatarImage());
            }

            return;
        }

        DBG("Warning: auth token seems to be invalid, removing");
        this->userProfile.clearProfileAndSession();
    }
}

//===----------------------------------------------------------------------===//
// Sign in / sign out
//===----------------------------------------------------------------------===//

void SessionService::signIn(const String &provider)
{
    if (auto *thread = this->getRunningThreadFor<AuthThread>())
    {
        jassertfalse;
        DBG("Auth is already in progress");
        return;
    }

    App::showModalComponent(ProgressTooltip::cancellable([this]
    {
        this->cancelSignInProcess();
    }));

    this->prepareAuthThread()->requestWebAuth(provider);
}

void SessionService::cancelSignInProcess()
{
    if (auto *thread = this->getRunningThreadFor<AuthThread>())
    {
        thread->signalThreadShouldExit();
        // TODO call authCallback with errors=[TRANS(I18n::Popup::cancelled)]?
    }
}

void SessionService::signOut()
{
    // TODO: need to erase token on server, and then:
    this->userProfile.clearProfileAndSession();
}

//===----------------------------------------------------------------------===//
// Updating session
//===----------------------------------------------------------------------===//

AuthThread *SessionService::prepareAuthThread()
{
    auto *thread = this->getNewThreadFor<AuthThread>();

    thread->onAuthSessionInitiated = [](const AuthSessionDto session, const String &redirect)
    {
        jassert(redirect.isNotEmpty());
        URL(Routes::Web::baseURL + redirect).launchInDefaultBrowser();
    };

    thread->onAuthSessionFinished = [this](const AuthSessionDto session)
    {
        App::Layout().showTooltip({}, MainLayout::TooltipIcon::Success);

        this->userProfile.setApiToken(session.getToken());
        // don't call authCallback right now, instead request a user profile and callback when ready;
        // (true) == force request avatar data, as now it might have changed:
        this->prepareProfileRequestThread()->doRequest(true);
    };

    thread->onAuthSessionFailed = [this](const Array<String> &errors)
    {
        App::Layout().showTooltip(errors.getFirst(), MainLayout::TooltipIcon::Failure);
        DBG("Login failed: " + errors.getFirst());
    };

    return thread;
}

TokenUpdateThread *SessionService::prepareTokenUpdateThread()
{
    auto *thread = this->getNewThreadFor<TokenUpdateThread>();

    thread->onTokenUpdateOk = [this](const String &newToken)
    {
        this->userProfile.setApiToken(newToken);
        // (true) == force request avatar data, as now it might have changed:
        this->prepareProfileRequestThread()->doRequest(true);
    };

    thread->onTokenUpdateFailed = [this](const Array<String> &errors)
    {
        // This might be the case of connection error,
        // so we should not reset the token and profile
        if (!errors.isEmpty())
        {
            this->userProfile.clearProfileAndSession();
        }
    };

    return thread;
}

RequestUserProfileThread *SessionService::prepareProfileRequestThread()
{
    auto *thread = this->getNewThreadFor<RequestUserProfileThread>();

    thread->onRequestProfileOk = [this](const UserProfileDto profile)
    {
        this->userProfile.updateProfile(profile);
    };

    return thread;
}

#endif
