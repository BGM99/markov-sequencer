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

#include "Serializable.h"
#include "SerializationKeys.h"

class ApiModel : public Serializable
{
public:

    ApiModel(const SerializedData &tree) noexcept : data(tree) {}

    template<typename T>
    Array<T> getChildren(const Identifier &id) const
    {
        Array<T> result;
        forEachChildWithType(this->data, child, id)
        {
            result.add({ child });
        }
        return result;
    }

    bool isValid() const noexcept
    {
        return this->data.isValid();
    }

    SerializedData serialize() const override
    {
        return this->data;
    }

    void deserialize(const SerializedData &data) override
    {
        this->data = data;
    }

    void reset() override
    {
        this->data = {};
    }

protected:

    SerializedData data;
};

#define DTO_PROPERTY(x) this->data.getProperty(Serialization::Api::V1::x)
#define DTO_CHILDREN(c, x) this->getChildren<c>(Serialization::Api::V1::x);
#define DTO_CHILD(x) this->data.getChildWithName(Serialization::Api::V1::x);

#endif
