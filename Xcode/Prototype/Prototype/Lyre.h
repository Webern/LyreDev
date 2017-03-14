//  Copyright (c) by Matthew James Briggs. All rights reserved.

#pragma once

#include "Declarations.h"
#include <cstddef>
#include <limits>
#include <vector>
#include <memory>
#include <mutex>

namespace lyre
{
    using ID = std::size_t;
    constexpr const ID BadID = std::numeric_limits<ID>::min();
    constexpr const ID FirstID = BadID + 1;

    using Lock = std::lock_guard<std::mutex>;
    #define LYRE_MUTEX mutable std::mutex mMutex;
    #define LYRE_LOCK Lock LYRE_LOCK_GAURD_STD_MUTEX{mMutex};

    LYRE_FORWARD_DECLARE(Registry);
    LYRE_FORWARD_DECLARE( RegistryObject );
    LYRE_FORWARD_DECLARE( SharedPtr );
}
