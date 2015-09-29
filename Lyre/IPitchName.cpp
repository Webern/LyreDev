#include "IPitchName.h"
#include <sstream>

namespace lyre
{
    String IPitchName::toString() const
    {
        std::stringstream ss;
        toStream( ss );
        return ss.str();
    }
    bool IPitchName::lessThan( const IPitchName& other ) const
    {
        return getValue() < other.getValue();
    }
    bool IPitchName::greaterThan( const IPitchName& other ) const
    {
        return getValue() > other.getValue();
    }
    bool IPitchName::equals( const IPitchName& other ) const
    {
        return getValue() == other.getValue();
    }
    std::ostream& operator<<( std::ostream& os, const IPitchName& object )
    {
        return object.toStream( os );
    }
}