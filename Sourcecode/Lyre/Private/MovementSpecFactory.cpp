#include "Lyre/Private/MovementSpecFactory.h"
#include "Lyre/IMovementSpec.h"
#include "Lyre/Private/MovementSpec.h"


namespace Lyre
{
    namespace Private
    {
        MovementSpecFactory::~MovementSpecFactory() {}
        
        IMovementSpecUP MovementSpecFactory::create( int number ) const
        {
            return IMovementSpecUP{ new MovementSpec{ number } };
        }
    }
}
