//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMovementSpec.h"

namespace Lyre
{
    enum class PUBLIC MovementSpecFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IMovementSpecFactory)
    
    PUBLIC IMovementSpecFactoryUP
        createMovementSpecFactory(
            MovementSpecFactoryType t = 
            MovementSpecFactoryType::Standard );

    class PUBLIC IMovementSpecFactory
    {
    public:
        virtual ~IMovementSpecFactory() {}
        virtual IMovementSpecUP create( int number ) const = 0;

    };
}
