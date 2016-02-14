#include "Lyre/Private/TimeSignature.h"
#if 1==0
namespace Lyre
{
    TimeSignature::~TimeSignature() {}
    
    TimeSignature::TimeSignature( int top, int bottom )
    :myTop( top )
    ,myBottom( bottom )
    {}
    
    TimeSignature::TimeSignature()
    :myTop( DEFAULT_TOP )
    ,myBottom( DEFAULT_BOTTOM )
    {}
    
    ITimeSignatureUP TimeSignature::clone() const
    {
        return ITimeSignatureUP{ new TimeSignature{ *this } };
    }
    
    std::ostream& TimeSignature::toStream( std::ostream& os ) const
    {
        return os;
    }
}
#endif
