//  Copyright (c) by Matthew James Briggs. All rights reserved.

#pragma once

#include <limits>
#include <functional>

namespace lyre
{
    using ID = std::size_t;
    constexpr const ID BadID = std::numeric_limits<ID>::min();
    constexpr const ID FirstID = BadID + 1;

    class Registry;

    class RegistryObject
    {
    public:
        RegistryObject(const ID inID, const Registry& inRegistry);
        RegistryObject(const RegistryObject& inOther) = default;
        RegistryObject(RegistryObject&& inOther) = default;
        RegistryObject& operator=(const RegistryObject& inOther) = default;
        RegistryObject& operator=(RegistryObject&& inOther) = default;

        ID getID() const;
        
    private:
        ID mID;
        std::reference_wrapper<const Registry> mRegistry;
    };
}
