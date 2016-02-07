//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(IBeatPattern)
    
    static const Integer DEFAULT_TOP = 4;
    static const Integer DEFAULT_BOTTOM = 4;
    
    class PUBLIC IBeatPattern : public IStreamable
    {
    public:
        virtual ~IBeatPattern() {};
        virtual IBeatPatternUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
    };
}
