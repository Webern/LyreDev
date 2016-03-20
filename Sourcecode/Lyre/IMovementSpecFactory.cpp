#include "Lyre/IMovementSpecFactory.h"
#include "Lyre/Private/MovementSpecFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IMovementSpecFactoryUP
    createMovementSpecFactory( MovementSpecFactoryType t )
    {
        switch ( t )
        {
            case MovementSpecFactoryType::Standard:
                return IMovementSpecFactoryUP{ new Private::MovementSpecFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized MovementSpecFactoryType" )
    }
}
