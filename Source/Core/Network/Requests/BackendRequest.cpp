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
#include "BackendRequest.h"
#include "Workspace.h"
#include "NetworkServices.h"

#if !NO_NETWORK

BackendRequest::Response::Response() {}

bool BackendRequest::Response::hasValidBody() const noexcept
{
    return this->body.isValid();
}

bool BackendRequest::Response::is2xx() const noexcept
{
    return (this->statusCode / 100) == 2;
}

bool BackendRequest::Response::is200() const noexcept
{
    return this->statusCode == 200;
}

bool BackendRequest::Response::is(int code) const noexcept
{
    return this->statusCode == code;
}

bool BackendRequest::Response::hasProperty(const Identifier &name) const noexcept
{
    return this->body.hasProperty(name);
}

var BackendRequest::Response::getProperty(const Identifier &name) const noexcept
{
    return this->body.getProperty(name);
}

SerializedData BackendRequest::Response::getChild(const Identifier &name) const noexcept
{
    return this->body.getChildWithName(name);
}

const Array<String> &BackendRequest::Response::getErrors() const noexcept
{
    return this->errors;
}

const SerializedData BackendRequest::Response::getBody() const noexcept
{
    return this->body;
}

const String BackendRequest::Response::getRedirect() const noexcept
{
    //if (this->statusCode == 301 || this->statusCode == 302)
    return this->headers.getValue("location", {});
}

BackendRequest::BackendRequest(const String &apiEndpoint) :
    apiEndpoint(apiEndpoint),
    serializer(true) {}

static String getHeaders()
{
    static const String apiVersion1 = "application/helio.fm.v1+json";
    static const String userAgent = "Helio " + App::getAppReadableVersion() +
        (SystemStats::isOperatingSystem64Bit() ? " 64-bit on " : " 32-bit on ") +
        SystemStats::getOperatingSystemName();

    String extraHeaders;
    extraHeaders
        << "Accept: " << apiVersion1
        << "\r\n"
        << "Content-Type: " << apiVersion1
        << "\r\n"
        << "User-Agent: " << userAgent
        << "\r\n";

    const auto &profile = App::Workspace().getUserProfile();
    if (profile.isLoggedIn())
    {
        extraHeaders
            << "Authorization: Bearer " << profile.getApiToken()
            << "\r\n";
    }

    return extraHeaders;
}

void BackendRequest::processResponse(BackendRequest::Response &response, InputStream *const stream) const
{
    if (stream == nullptr)
    {
        return;
    }

    // Try to parse response as JSON object wrapping all properties
    const String responseBody = stream->readEntireStreamAsString();
    if (responseBody.isNotEmpty())
    {
        DBG("<< Received " << response.statusCode << " " // << responseBody);
            << responseBody.substring(0, 128) << (responseBody.length() > 128 ? ".." : ""));

        response.body = this->serializer.loadFromString(responseBody);
        if (!response.body.isValid())
        {
            response.errors.add(TRANS(I18n::Common::networkError));
            return;
        }

        // Try to parse errors
        if (response.statusCode < 200 || response.statusCode >= 400)
        {
            using namespace Serialization;
            for (int i = 0; i < response.body.getNumProperties(); ++i)
            {
                const auto key = response.body.getPropertyName(i);
                const auto value = response.body.getProperty(key).toString();
                if (key == Api::V1::status || key == Api::V1::message)
                {
                    response.errors.add(value);
                }
                else
                {
                    response.errors.add(key.toString() + ": " + value);
                }
            }
        }
    }
}

BackendRequest::Response BackendRequest::put(const SerializedData &payload) const
{
    return this->doRequest(payload, "PUT");
}

BackendRequest::Response BackendRequest::post(const SerializedData &payload) const
{
    return this->doRequest(payload, "POST");
}

BackendRequest::Response BackendRequest::get() const
{
    return this->doRequest("GET");
}

BackendRequest::Response BackendRequest::del() const
{
    return this->doRequest("DELETE");
}

BackendRequest::Response BackendRequest::doRequest(const String &verb) const
{
    Response response;
    UniquePointer<InputStream> stream;
    
    const auto url = URL(Routes::Api::baseURL + this->apiEndpoint);

    int i = 0;
    do
    {
        DBG(">> " << verb << " " << this->apiEndpoint);
        stream = url.createInputStream(
            URL::InputStreamOptions(URL::ParameterHandling::inAddress)
                .withHttpRequestCmd(verb)
                .withExtraHeaders(getHeaders())
                .withConnectionTimeoutMs(BackendRequest::connectionTimeoutMs)
                .withNumRedirectsToFollow(5)
                .withResponseHeaders(&response.headers)
                .withStatusCode(&response.statusCode));
    } while (stream == nullptr && ++i < BackendRequest::numConnectAttempts);

    processResponse(response, stream.get());
    return response;
}

BackendRequest::Response BackendRequest::doRequest(const SerializedData &payload, const String &verb) const
{
    Response response;
    UniquePointer<InputStream> stream;

    String jsonPayload;
    if (this->serializer.saveToString(jsonPayload, payload).failed())
    {
        return response;
    }

    const auto url = URL(Routes::Api::baseURL + this->apiEndpoint)
        .withPOSTData(MemoryBlock(jsonPayload.toRawUTF8(), jsonPayload.getNumBytesAsUTF8()));

    int i = 0;
    do
    {
        DBG(">> " << verb << " " << this->apiEndpoint << " " 
            << jsonPayload.substring(0, 128) + (jsonPayload.length() > 128 ? ".." : ""));

        stream = url.createInputStream(
            URL::InputStreamOptions(URL::ParameterHandling::inPostData)
                .withHttpRequestCmd(verb)
                .withExtraHeaders(getHeaders())
                .withConnectionTimeoutMs(BackendRequest::connectionTimeoutMs)
                .withNumRedirectsToFollow(5)
                .withResponseHeaders(&response.headers)
                .withStatusCode(&response.statusCode));
    } while (stream == nullptr && ++i < BackendRequest::numConnectAttempts);

    processResponse(response, stream.get());
    return response;
}

#endif
