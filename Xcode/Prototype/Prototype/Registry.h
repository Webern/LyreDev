//  Copyright (c) by Matthew James Briggs. All rights reserved.

#pragma once

#include "SharedPtr.h"
#include "RegistryObject.h"
#include <memory>
#include <map>
#include <mutex>

namespace lyre
{
    class Registry
    {
    public:
        Registry();
        ~Registry();
        Registry(const Registry& other) = delete;
        Registry(Registry&& other) noexcept;
        Registry& operator=(const Registry& other);
        Registry& operator=(Registry&& other) noexcept;

        RegistryObject create();
        SharedPtr getShared(ID inID);

    private:
        friend class SharedPtr;
        friend class WeakPtr;

    private:
        RegistryObject* get(ID inID) const;
        void destroyShared(ID inID);

    private:
        LYRE_MUTEX;
        ID mID;
        std::map<ID, std::unique_ptr<RegistryObject>> mRegistry;
    };
}
