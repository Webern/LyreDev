//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include <iostream>

namespace Lyre
{
    FORWARD_DECLARE(IStreamable)
    
    class PUBLIC IStreamable
    {
    public:
        virtual ~IStreamable() {}
        virtual std::ostream& toStream( std::ostream& os ) = 0;
        virtual String toString() const { std::stringstream ss; toStream( ss ); return ss.str(); }
    };
    
    PUBLIC std::ostream& operator<<( std::ostream& os, const IStreamable& object )
    {
        return object.toStream( os );
    }
}
