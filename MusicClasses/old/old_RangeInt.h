#pragma once
#include "Definitions.h"

namespace music
{
    /*
     T is the type, for example int, long, etc
     
     MIN and MAX define the boundries of the range
     
     MIN/MAX EPSILON defines how close (distance) the contained
     value may approach the range.  For example an EPSILON of Zero
     defines an "open" range.  A non-zero EPSILON defines a closed
     range.  EPSILON must be positive or the template will
     throw.
     */
    
    template <typename T, T MIN, T MAX>
    class RangeInt
    {
    public:
        explicit RangeInt( const T value )
        :myValue( value )
        {
            setValue( value );
        }
        RangeInt()
        :myValue( 0 )
        {
            setValue( 0 );
        }
        T getValue() const
        {
            return myValue;
        }
        void setValue( const T value )
        {
            if ( value < MIN )
            {
                myValue = MIN;
            }
            else if ( value > MAX )
            {
                myValue = MAX;
            }
            else
            {
                myValue = value;
            }
        }
        RangeInt& add( const T value )
        {
            this->setValue( myValue + value );
            return *this;
        }
        RangeInt& subtract( const T value )
        {
            this->setValue( myValue - value );
            return *this;
        }
    private:
        T myValue;
    };
}