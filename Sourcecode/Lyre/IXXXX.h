//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(IXXXX)
    
    static const int DEFAULT_TOP = 4;
    static const int DEFAULT_BOTTOM = 4;
    
    class PUBLIC IXXXX : public IStreamable
    {
    public:
        virtual ~IXXXX() {};
        virtual IXXXXUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;

    };
}
