//  Copyright (c) by Matthew James Briggs. All rights reserved.

#pragma once

#include <limits>
#include <memory>

namespace lyre
{
    using ID = std::size_t;
    constexpr const ID BadID = std::numeric_limits<ID>::min();
    constexpr const ID FirstID = BadID + 1;

    class Registry;

    class RegistryObject
    {
    public:
        ID getID() const;
        
    private:
        ID mID;
        std::weak_ptr<Registry> mRegistryWPtr;
    };
}
