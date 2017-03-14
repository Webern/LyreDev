//  Copyright (c) by Matthew James Briggs. All rights reserved.

#pragma once

#include "Lyre.h"
#include <memory>
#include <map>

namespace lyre
{

    class Registry;
    class RegistryObject;

    class SharedPtr
    {
    public:
        SharedPtr(ID inID, const Registry& inRegistry);

    private:
        ID mID;
        std::reference_wrapper<const Registry> mRegistry;
        RegistryObject* mObject;
    };
}
