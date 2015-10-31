#include "Lyre/IPitch.h"
#include <sstream>

namespace lyre
{
    String IPitch::toString() const
    {
        std::stringstream ss;
        toStream( ss );
        return ss.str();
    }
    bool IPitch::isLessThan( const IPitch& other ) const
    {
        return getValue() < other.getValue();
    }
    bool IPitch::isGreaterThan( const IPitch& other ) const
    {
        return getValue() > other.getValue();
    }
    bool IPitch::isEqualTo( const IPitch& other ) const
    {
        return getValue() == other.getValue();
    }
    std::ostream& operator<<( std::ostream& os, const IPitch& object )
    {
        return object.toStream( os );
    }
}