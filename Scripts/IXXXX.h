//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(IXXXX)
    
    class PUBLIC IXXXX : public IStreamable
    {
    public:
        virtual ~IXXXX() {};
        virtual IXXXXUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
    };
}
