#include "Lyre/IDurDot.h"
#include <sstream>

namespace Lyre
{
    IDurDot::~IDurDot() {}
 
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
