//  Copyright (c) by Matthew James Briggs. All rights reserved.

#include "Registry.h"

namespace lyre
{

    RegistryObject Registry::create()
    {
        const auto current = mID++;
        mRegistry[current] = std::make_unique<RegistryObject>( current, *this );
        return *mRegistry[current];
    }
}
