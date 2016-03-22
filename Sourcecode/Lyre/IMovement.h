//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMovementSpec.h"
#include "Lyre/IPartSpec.h"
#include "Lyre/IPart.h"
#include "Lyre/IMasterTrack.h"

namespace Lyre
{
    
    FORWARD_DECLARE(IMovement)
    
    class PUBLIC IMovement : public IStreamable
    {
    public:
        virtual ~IMovement() {};
        virtual IMovementUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual const IMovementSpecUPC getSpec() const = 0;
        
        virtual int getPartCount() const = 0;
        virtual IPartH getPart( int partIndex ) = 0;
        virtual const IPartHC getPart( int partIndex ) const = 0;
        virtual const IPartHC getPartConst( int partIndex ) const = 0;
        
    };
}
