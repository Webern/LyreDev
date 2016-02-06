#include "Lyre/IPitchName.h"
#include <sstream>

namespace Lyre
{
    String IPitchName::toString() const
    {
        std::stringstream ss;
        toStream( ss );
        return ss.str();
    }
    bool IPitchName::isLessThan( const IPitchName& other ) const
    {
        return getValue() < other.getValue();
    }
    bool IPitchName::isGreaterThan( const IPitchName& other ) const
    {
        return getValue() > other.getValue();
    }
    bool IPitchName::isEqualTo( const IPitchName& other ) const
    {
        return getValue() == other.getValue();
    }
    PUBLIC std::ostream& operator<<( std::ostream& os, const IPitchName& object )
    {
        return object.toStream( os );
    }
}
