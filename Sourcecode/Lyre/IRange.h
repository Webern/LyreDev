//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPitch.h"

namespace Lyre
{
    FORWARD_DECLARE(IRange)
    
    static const int DEFAULT_RANGE_LOW = 21;   // A-1
    static const int DEFAULT_RANGE_HIGH = 108; // C8
    
    class PUBLIC IRange : public IStreamable
    {
    public:
        virtual ~IRange() {};
        virtual IRangeUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual IPitchUP getLow() const = 0;
        virtual IPitchUP getHigh() const = 0;
        
    };
}
