#include "Lyre/Private/MovementFactory.h"
#include "Lyre/IMovement.h"
#include "Lyre/Private/Movement.h"


namespace Lyre
{
    namespace Private
    {
        MovementFactory::~MovementFactory() {}
        
        IMovementUP MovementFactory::create() const
        {
            return IMovementUP{ new Movement{} };
        }
    }
}
