#include "Lyre/IDurDot.h"
#include "Lyre/Private/copyTo.h"
#include <sstream>

namespace Lyre
{
    IDurDot::~IDurDot() {}
    
//    void IDurDot::copyTo( IDurDotUP& output ) const
//    {
//        auto tempP = static_cast<const IDurDot*>( this );
//        Private::copyTo<IDurDot>( tempP, output );
//    }
//    
    bool operator==( const IDurDot& l, const IDurDot& r )
    {
        return l.isEqualTo( r );
    }
    
    bool operator!=( const IDurDot& l, const IDurDot& r )
    {
        return ! l.isEqualTo( r );
    }
    
    bool operator>=( const IDurDot& l, const IDurDot& r )
    {
        return l.isGreaterThan( r ) || l.isEqualTo( r );
    }
    
    bool operator<=( const IDurDot& l, const IDurDot& r )
    {
        return l.isLessThan( r ) || l.isEqualTo( r );
    }
    
    bool operator>( const IDurDot& l, const IDurDot& r )
    {
        return l.isGreaterThan( r );
    }
    
    bool operator<( const IDurDot& l, const IDurDot& r )
    {
        return l.isLessThan( r );
    }
    
    std::ostream& operator<<( std::ostream& os, const IDurDot& object )
    {
        return object.toStream( os );
    }
}
