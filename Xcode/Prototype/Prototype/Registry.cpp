//  Copyright (c) by Matthew James Briggs. All rights reserved.

#include "Registry.h"

namespace lyre
{

    Registry::Registry()
    : mMutex{}
    , mID{FirstID}
    , mRegistry{}
    {

    }


    Registry::~Registry()
    {

    }


    Registry::Registry(Registry&& other) noexcept
    : mMutex{}
    , mID{std::move(other.mID)}
    , mRegistry{std::move(other.mRegistry)}
    {

    }


    Registry& Registry::operator=(Registry&& other) noexcept
    {
        mID = std::move(other.mID);
        mRegistry = std::move(other.mRegistry);
        return *this;
    }
    

    RegistryObject Registry::create()
    {
        LYRE_LOCK;
        const auto current = mID++;
        mRegistry[current] = std::make_unique<RegistryObject>( current, *this );
        return *mRegistry[current];
    }


    SharedPtr Registry::getShared(ID inID)
    {
        LYRE_LOCK;
        return SharedPtr{inID, *this};
    }


    RegistryObject* Registry::get(ID inID) const
    {
        LYRE_LOCK;
        return mRegistry.at(inID).get();
    }


    void Registry::destroyShared(ID inID)
    {
        LYRE_LOCK;
    }
}
