//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include <iostream>
#include <sstream>

namespace Lyre
{
    FORWARD_DECLARE(IStreamable)
    
    class PUBLIC IStreamable
    {
    public:
        virtual ~IStreamable() {}
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual String toString() const { std::stringstream ss; toStream( ss ); return ss.str(); }
    };

    PUBLIC inline std::ostream& operator<<(
        std::ostream& os, const IStreamable& object )
    {
        return object.toStream( os );
    }
}
