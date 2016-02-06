//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(ITimeSignature)
    
    static const Integer DEFAULT_TOP = 4;
    static const Integer DEFAULT_BOTTOM = 4;
    
    class PUBLIC ITimeSignature : public IStreamable
    {
    public:
        virtual ~ITimeSignature() {};
        virtual ITimeSignatureUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
    };
}
