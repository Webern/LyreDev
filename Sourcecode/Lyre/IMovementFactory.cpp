#include "Lyre/IMovementFactory.h"
#include "Lyre/Private/MovementFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IMovementFactoryUP
    createMovementFactory( MovementFactoryType t )
    {
        switch ( t )
        {
            case MovementFactoryType::Standard:
                return IMovementFactoryUP{ new Private::MovementFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized MovementFactoryType" )
    }
}
