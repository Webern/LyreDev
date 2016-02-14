//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ITimeSignature.h"
#if 1==0
namespace Lyre
{
    FORWARD_DECLARE(TimeSignature)
    
    class TimeSignature : public ITimeSignature
    {
    public:
        TimeSignature( int top, int bottom );
        TimeSignature();
        virtual ~TimeSignature();
        virtual ITimeSignatureUP clone() const;
        virtual std::ostream& toStream( std::ostream& os ) const;
    private:
        int myTop;
        int myBottom;
    };
}
#endif
