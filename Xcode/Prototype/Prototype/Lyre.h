//  Copyright (c) by Matthew James Briggs. All rights reserved.

#pragma once

#include "Declarations.h"
#include <cstddef>
#include <limits>
#include <vector>
#include <memory>

namespace lyre
{
    using ID = std::size_t;
    constexpr const ID BadID = std::numeric_limits<ID>::min();
    constexpr const ID FirstID = BadID + 1;

    LYRE_FORWARD_DECLARE(Registry);
    LYRE_FORWARD_DECLARE( RegistryObject );
    LYRE_FORWARD_DECLARE( SharedPtr );
}
