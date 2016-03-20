//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMovement.h"

namespace Lyre
{
    enum class PUBLIC MovementFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IMovementFactory)
    
    PUBLIC IMovementFactoryUP
        createMovementFactory(
            MovementFactoryType t = 
            MovementFactoryType::Standard );

    class PUBLIC IMovementFactory
    {
    public:
        virtual ~IMovementFactory() {}
        virtual IMovementUP create() const = 0;

    };
}
