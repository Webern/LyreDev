//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(IMovement)
    
    class PUBLIC IMovement : public IStreamable
    {
    public:
        virtual ~IMovement() {};
        virtual IMovementUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
    };
}
