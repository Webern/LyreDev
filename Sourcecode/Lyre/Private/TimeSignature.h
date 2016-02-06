//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ITimeSignature.h"

namespace Lyre
{
    FORWARD_DECLARE(TimeSignature)
    
    class TimeSignature : public ITimeSignature
    {
    public:
        TimeSignature( Integer top, Integer bottom );
        TimeSignature();
        virtual ~TimeSignature();
        virtual ITimeSignatureUP clone() const;
        virtual std::ostream& toStream( std::ostream& os ) const;
    private:
        Integer myTop;
        Integer myBottom;
    };
}
