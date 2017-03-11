//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/Rational.h"

namespace Lyre
{
    FORWARD_DECLARE(ITimeSignature)
    FORWARD_DECLARE(IBeatPattern)
    
    static const int DEFAULT_TIME_SIGNATURE_TOP = 4;
    static const int DEFAULT_TIME_SIGNATURE_BOTTOM = 4;
    
    class PUBLIC ITimeSignature : public IStreamable
    {
    public:
        virtual ~ITimeSignature() {};
        virtual ITimeSignatureUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual IBeatPatternUP getBeatPattern() const = 0;
        virtual int getTop() const = 0;
        virtual int getBottom() const = 0;
        virtual Rational getTotalDuration() = 0;
    };
}
