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
    
    bool operator==( const IDuration& l, const IDuration& r )
    {
        return l.isEqualTo( r );
    }
    
    bool operator!=( const IDuration& l, const IDuration& r )
    {
        return ! l.isEqualTo( r );
    }
    
    bool operator>=( const IDuration& l, const IDuration& r )
    {
        return l.isGreaterThan( r ) || l.isEqualTo( r );
    }
    
    bool operator<=( const IDuration& l, const IDuration& r )
    {
        return l.isLessThan( r ) || l.isEqualTo( r );
    }
    
    bool operator>( const IDuration& l, const IDuration& r )
    {
        return l.isGreaterThan( r );
    }
    
    bool operator<( const IDuration& l, const IDuration& r )
    {
        return l.isLessThan( r );
    }
    
    std::ostream& operator<<( std::ostream& os, const IDuration& object )
    {
        return object.toStream( os );
    }
}
