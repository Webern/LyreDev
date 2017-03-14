//  Copyright (c) by Matthew James Briggs. All rights reserved.

#include "SharedPtr.h"
#include "Registry.h"
#include "SharedPtr.h"

namespace lyre
{
    SharedPtr::SharedPtr(ID inID, Registry& registry)
    : mID{inID}
    , mRegistry{&registry}
    , mObject{registry.get(inID)}
    {

    }

    SharedPtr::~SharedPtr()
    {
        mRegistry->destroyShared(mID);
    }
    

}
