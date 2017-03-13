//  Copyright (c) by Matthew James Briggs. All rights reserved.

#pragma once

#include "Registry.h"
#include <memory>
#include <map>

namespace lyre
{
    class RegistryObject;

    class SharedPtr
    {
    public:
        SharedPtr(ID inID, Registry& inRegistry);

    private:
        ID mID;
        std::reference_wrapper<Registry> mRegistry;
        RegistryObject* mObject;
    };
}
