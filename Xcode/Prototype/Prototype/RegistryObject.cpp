//  Copyright (c) by Matthew James Briggs. All rights reserved.

#include "RegistryObject.h"
#include "Registry.h"

namespace lyre
{
    RegistryObject::RegistryObject(const ID inID, const Registry& inRegistry)
    : mID{inID}
    , mRegistry{inRegistry}
    {

    }

    ID RegistryObject::getID() const
    {
        return mID;
    }

}
