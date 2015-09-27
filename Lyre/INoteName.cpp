#include "INoteName.h"
#include <sstream>

namespace lyre
{
    String INoteName::toString() const
    {
        std::stringstream ss;
        toStream( ss );
        return ss.str();
    }
    bool INoteName::lessThan( const INoteName& other ) const
    {
        return getValue() < other.getValue();
    }
    bool INoteName::greaterThan( const INoteName& other ) const
    {
        return getValue() > other.getValue();
    }
    bool INoteName::equals( const INoteName& other ) const
    {
        return getValue() == other.getValue();
    }
    std::ostream& operator<<( std::ostream& os, const INoteName& object )
    {
        return object.toStream( os );
    }
}