//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(IMovementSpec)
    
    class PUBLIC IMovementSpec : public IStreamable
    {
    public:
        virtual ~IMovementSpec() {};
        virtual IMovementSpecUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual int getNumber() const = 0;
        virtual String getTitle() const = 0;
        virtual String getDisplayTitle() const = 0;
        
        virtual void setTitle( const String& title ) = 0;
        virtual void setDisplayTitle( const String& dispTitle ) = 0;
    };
}
