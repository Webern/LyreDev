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
        SharedPtr(ID inID, Registry& registry);
        ~SharedPtr();

    private:
        friend class Registry;


    private:
        ID mID;
        Registry* mRegistry;
        RegistryObject* mObject;
    };
}
