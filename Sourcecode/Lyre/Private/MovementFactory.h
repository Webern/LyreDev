//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMovementFactory.h"
#include "Lyre/IMovement.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(MovementFactory)
        
        class MovementFactory : public IMovementFactory
        {
        public:
            virtual ~MovementFactory();
            
            virtual IMovementUP create() const;
        };
    }
}
