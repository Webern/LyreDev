#include "Enum.h"

namespace lyre
{
    Enum::Enum( const Integer value, const std::shared_ptr<Strings> strs, const Integer offset )
    :myStrings( strs )
    ,myOffset( offset )
    ,myValue( 0 )
    {
        if ( (!strs) || (strs->size()==0) )
        {
            myStrings = std::make_shared<Strings>( Strings{ "error" } );
            myOffset = 0;
        }
        setValue( value );
    }
    
    IEnumUP Enum::clone() const
    {
        IEnumUP value{ new Enum{ *this } };
        return value;
    }
    
    Integer Enum::getValue() const
    {
        return myValue + myOffset;
    }
    
    void Enum::setValue( const Integer val )
    {
        if ( val > getMax() )
        {
            setValue( getMax() );
        }
        else if ( val < getMin() )
        {
            setValue( getMin() );
        }
        else
        {
            myValue = val - myOffset;
        }
    }
    
    Integer Enum::getMin() const
    {
        return myOffset;
    }
    
    Integer Enum::getMax() const
    {
        if ( myStrings )
        {
            return ( ( (Integer)myStrings->size() ) - 1 ) + myOffset;
        }
        return 0;
    }
    
    bool Enum::parse( const String& str )
    {
        Integer i = 0;
        for ( auto s : *myStrings )
        {
            if ( str == s )
            {
                myValue = i;
                return true;
            }
            ++i;
        }
        return false;
    }
    
    std::ostream& Enum::toStream( std::ostream& os ) const
    {
        if ( ! myStrings )
        {
            return ( os << String{ "error" } );
        }
        if ( myValue < 0 || myValue >= myStrings->size() )
        {
            return ( os << String{ "error" } );
        }
        return ( os << (*myStrings)[ myValue ] );
    }
    
    void Enum::increment()
    {
        if ( myValue == getMax() - myOffset )
        {
            myValue = getMin() - myOffset;
        }
        else
        {
            myValue++;
        }
    }
    void Enum::decrement()
    {
        if ( myValue == getMin() - myOffset )
        {
            myValue = getMax() - myOffset;
        }
        else
        {
            myValue--;
        }
    }
}