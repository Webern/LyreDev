#include "Lyre/IEnum.h"
#include <sstream>

namespace lyre
{
    String IEnum::toString() const
    {
        std::stringstream ss;
        this->toStream( ss );
        return String{ ss.str() };
    }
    std::ostream& operator<<( std::ostream& os, const IEnum& EnumName )
    {
        return EnumName.toStream( os );
    }
    bool IEnum::isLessThan( const IEnum& other ) const
    {
        return getValue() < other.getValue();
    }
    bool IEnum::isGreaterThan( const IEnum& other ) const
    {
        return getValue() > other.getValue();
    }
    bool IEnum::isEqualTo( const IEnum& other ) const
    {
        return getValue() == other.getValue();
    }
    void IEnum::increment()
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
    void IEnum::decrement()
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