#include "Lyre/IDuration.h"
#include "Lyre/Private/copyTo.h"
#include <sstream>

namespace Lyre
{
    IDuration::~IDuration() {}
    
    void IDuration::copyTo( IDurationUP& output ) const
    {
        auto tempP = static_cast<const IDuration*>( this );
        Private::copyTo<IDuration>( tempP, output );
    }
}
