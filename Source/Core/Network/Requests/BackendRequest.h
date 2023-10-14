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

#pragma once

#if !NO_NETWORK

#include "JsonSerializer.h"

class BackendRequest final
{
public:

    BackendRequest(const String &apiEndpoint);

    struct Response final
    {
        Response();

        bool is2xx() const noexcept;
        bool is200() const noexcept;
        bool is(int code) const noexcept;
        bool hasValidBody() const noexcept;

        // SerializedData wrappers
        bool hasProperty(const Identifier &name) const noexcept;
        var getProperty(const Identifier &name) const noexcept;
        SerializedData getChild(const Identifier &name) const noexcept;

        const Array<String> &getErrors() const noexcept;
        const SerializedData getBody() const noexcept;
        const String getRedirect() const noexcept;

    private:

        SerializedData body;

        // optional detailed errors descriptions
        Array<String> errors;

        int statusCode = 0;
        StringPairArray headers;

        friend class BackendRequest;
    };

    Response get() const;
    Response post(const SerializedData &payload) const;
    Response put(const SerializedData &payload) const;
    Response del() const;

private:

    // Meaning the OS will set the default timeout:
    static constexpr auto connectionTimeoutMs = 0;

    static constexpr auto numConnectAttempts = 3;

    String apiEndpoint;
    JsonSerializer serializer;

    Response doRequest(const String &verb) const;
    Response doRequest(const SerializedData &payload, const String &verb) const;
    void processResponse(Response &response, InputStream *const stream) const;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BackendRequest)
};

#endif
