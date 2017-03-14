//  Copyright (c) by Matthew James Briggs. All rights reserved.

#include "SharedPtr.h"
#include "Registry.h"
#include "SharedPtr.h"

namespace lyre
{
    SharedPtr::SharedPtr(ID inID, const Registry& inRegistry)
    : mID{inID}
    , mRegistry{inRegistry}
    , mObject{inRegistry.get(inID)}
    {

    }
}
