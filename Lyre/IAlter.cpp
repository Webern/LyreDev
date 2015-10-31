#include "Lyre/IAlter.h"

#include <sstream>

namespace lyre
{
    String IAlter::toString() const
    {
        std::stringstream ss;
        this->toStream( ss );
        return String{ ss.str() };
    }
    std::ostream& operator<<( std::ostream& os, const IAlter& AlterName )
    {
        return AlterName.toStream( os );
    }
    bool IAlter::isLessThan( const IAlter& other ) const
    {
        return getValue() < other.getValue();
    }
    bool IAlter::isGreaterThan( const IAlter& other ) const
    {
        return getValue() > other.getValue();
    }
    bool IAlter::isEqualTo( const IAlter& other ) const
    {
        return getValue() == other.getValue();
    }
    void IAlter::increment()
    {
        if ( getValue() == getMax() )
        {
            setValue( getMin() );
        }
        else
        {
            setValue( getValue() + 1 );
        }
    }
    void IAlter::decrement()
    {
        if ( getValue() == getMin() )
        {
            setValue( getMax() );
        }
        else
        {
            setValue( getValue() - 1 );
        }
    }
}