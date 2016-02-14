#include "Lyre/Private/Enum.h"

namespace Lyre
{
    namespace Private
    {
        Enum::Enum( const int value, const std::shared_ptr<Strings> strs, const int offset )
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
        
        int Enum::getValue() const
        {
            return myValue + myOffset;
        }
        
        void Enum::setValue( const int val )
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
        
        int Enum::getMin() const
        {
            return myOffset;
        }
        
        int Enum::getMax() const
        {
            if ( myStrings )
            {
                return ( ( (int)myStrings->size() ) - 1 ) + myOffset;
            }
            return 0;
        }
        
        bool Enum::parse( const String& str )
        {
            int i = 0;
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
            if ( myValue < 0 || myValue >= static_cast<int>( myStrings->size() ) )
            {
                return ( os << String{ "error" } );
            }
            return ( os << (*myStrings)[ static_cast<size_t>( myValue ) ] );
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
}
