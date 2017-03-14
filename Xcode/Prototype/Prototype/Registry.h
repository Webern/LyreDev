//  Copyright (c) by Matthew James Briggs. All rights reserved.

#pragma once

#include "SharedPtr.h"
#include "RegistryObject.h"
#include <memory>
#include <map>

namespace lyre
{
    class Registry
    {
    public:

        RegistryObject create();
        SharedPtr getShared(ID inID);

    private:
        friend class SharedPtr;
        friend class WeakPtr;

    private:
        RegistryObject* get(ID inID) const;
        void destroyShared(ID inID);

    private:
        ID mID;
        std::map<ID, std::unique_ptr<RegistryObject>> mRegistry;
    };
}
