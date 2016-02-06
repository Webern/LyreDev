#include "Lyre/IDurBase.h"
#include <sstream>

namespace Lyre
{
    IDurBase::~IDurBase() {}
    
    String IDurBase::toString() const
    {
        std::stringstream ss;
        toStream( ss );
        return ss.str();
    }
    
    bool IDurBase::isEqualTo( const IDurBase& other ) const
    {
        return this->getValue() == other.getValue();
    }
    
    bool IDurBase::isGreaterThan( const IDurBase& other ) const
    {
        return this->getValue() > other.getValue();
    }
    
    bool IDurBase::isLessThan( const IDurBase& other ) const
    {
        return this->getValue() < other.getValue();
    }
    
    bool IDurBase::isIdenticalTo( const IDurBase& other ) const
    {
        if ( ! isEqualTo( other ) )
        {
            return false;
        }
        if ( this->toString() != other.toString() )
        {
            return false;
        }
        return true;
    }
    
    bool operator==( const IDurBase& l, const IDurBase& r )
    {
        return l.isEqualTo( r );
    }
    
    bool operator!=( const IDurBase& l, const IDurBase& r )
    {
        return ! l.isEqualTo( r );
    }
    
    bool operator>=( const IDurBase& l, const IDurBase& r )
    {
        return l.isGreaterThan( r ) || l.isEqualTo( r );
    }
    
    bool operator<=( const IDurBase& l, const IDurBase& r )
    {
        return l.isLessThan( r ) || l.isEqualTo( r );
    }
    
    bool operator>( const IDurBase& l, const IDurBase& r )
    {
        return l.isGreaterThan( r );
    }
    
    bool operator<( const IDurBase& l, const IDurBase& r )
    {
        return l.isLessThan( r );
    }
    
    PUBLIC std::ostream& operator<<( std::ostream& os, const IDurBase& object )
    {
        return object.toStream( os );
    }
}
