//  Copyright (c) by Matthew James Briggs. All rights reserved.

#pragma once

#include "RegistryObject.h"
#include <memory>
#include <map>

namespace lyre
{
    class Registry
    {
    public:

        RegistryObject create();

    private:
        ID mID;
        std::map<ID, std::unique_ptr<RegistryObject>> mRegistry;
    };
}
