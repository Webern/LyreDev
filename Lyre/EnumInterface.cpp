#include "EnumInterface.h"
#include <sstream>

namespace lyre
{
    String EnumInterface::toString() const
    {
        std::stringstream ss;
        this->toStream( ss );
        return String{ ss.str() };
    }
    std::ostream& operator<<( std::ostream& os, const EnumInterface& EnumName )
    {
        return EnumName.toStream( os );
    }
    bool EnumInterface::lessThan( const EnumInterface& other ) const
    {
        return getValue() < other.getValue();
    }
    bool EnumInterface::greaterThan( const EnumInterface& other ) const
    {
        return getValue() > other.getValue();
    }
    bool EnumInterface::equals( const EnumInterface& other ) const
    {
        return getValue() == other.getValue();
    }
    void EnumInterface::increment()
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
    void EnumInterface::decrement()
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