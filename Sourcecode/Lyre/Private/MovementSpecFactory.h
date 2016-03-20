//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMovementSpecFactory.h"
#include "Lyre/IMovementSpec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(MovementSpecFactory)
        
        class MovementSpecFactory : public IMovementSpecFactory
        {
        public:
            virtual ~MovementSpecFactory();
            
            virtual IMovementSpecUP create( int number ) const;
        };
    }
}
