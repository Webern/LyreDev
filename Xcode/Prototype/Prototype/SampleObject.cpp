//  Copyright (c) by Matthew James Briggs. All rights reserved.

#include "SampleObject.h"
#include "Registry.h"

namespace lyre
{
    SampleObject::SampleObject(Registry& inRegistry)
    : RegistryObject(inRegistry.create())
    {

    }
}
