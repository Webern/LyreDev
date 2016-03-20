//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMovementSpec.h"
#include "Lyre/IPart.h"
#include "Lyre/IMasterTrack.h"

namespace Lyre
{
    
    struct MovementMetadata
    {
        char* title;
    };
    
    FORWARD_DECLARE(IMovement)
    
    class PUBLIC IMovement : public IStreamable
    {
    public:
        virtual ~IMovement() {};
        virtual IMovementUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual const IMovementSpecUPC getInfo() const = 0;
        
    };
}
