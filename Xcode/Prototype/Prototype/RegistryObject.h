//  Copyright (c) by Matthew James Briggs. All rights reserved.

#pragma once

#include "Lyre.h"
#include <limits>
#include <functional>

namespace lyre
{
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
