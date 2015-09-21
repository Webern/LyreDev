#include "EnumSimple.h"

namespace lyre
{
    EnumSimple::EnumSimple( const Integer value, const std::shared_ptr<Strings> strs, const Integer offset )
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
    
    EnumPtr EnumSimple::clone() const
    {
        return std::make_shared<EnumSimple>( *this );
    }
    
    Integer EnumSimple::getValue() const
    {
        return myValue + myOffset;
    }
    
    void EnumSimple::setValue( const Integer val )
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
    
    Integer EnumSimple::getMin() const
    {
        return myOffset;
    }
    
    Integer EnumSimple::getMax() const
    {
        if ( myStrings )
        {
            return ( ( (Integer)myStrings->size() ) - 1 ) + myOffset;
        }
        return 0;
    }
    
    bool EnumSimple::parse( const String& str )
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
    
    std::ostream& EnumSimple::toStream( std::ostream& os ) const
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
    
    void EnumSimple::increment()
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
    void EnumSimple::decrement()
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