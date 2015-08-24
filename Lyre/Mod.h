#pragma once
#include <cmath>

/* The Mod class restrics values of an integral
 to be between x=zero and MODULUS-1 by using the
 % operator. It probably only works for integral
 types (int, long, short, char, etc) */

namespace lyre
{
    template <typename TYPE, TYPE MODULUS>
    class Mod
    {
    public:
        Mod()
        :myValue( 0 )
        {}
        explicit Mod( const TYPE value )
        :myValue( value )
        {
            setValue( value );
        }
        TYPE getValue() const
        {
            return myValue;
        }
        void setValue( const TYPE value )
        {
            if ( value >= 0 )
            {
                myValue = value % MODULUS;
            }
            else
            {
                myValue = ( MODULUS - ( std::abs( value ) % MODULUS ) ) % MODULUS;
            }
        }
        Mod& add( const TYPE value )
        {
            setValue( myValue + value );
            return *this;
        }
        Mod& subtract( const TYPE value )
        {
            setValue( myValue - value );
            return *this;
        }
        Mod& operator++()
        {
            setValue( ( ++myValue ) );
            return *this;
        }
        Mod operator++(int)
        {
            Mod temp = *this;
            setValue( ( ++myValue ) );
            return temp;
        }
        Mod& operator--()
        {
            setValue( ( --myValue ) );
            return *this;
        }
        Mod operator--(int)
        {
            Mod temp = *this;
            setValue( ( --myValue ) );
            return temp;
        }
        bool operator==( const Mod& rhs ) const
        {
            return this->getValue() == rhs.getValue();
        }
        bool operator!=( const Mod& rhs ) const
        {
            return ! ( *this == rhs );
        }
        bool operator>=( const Mod& rhs ) const
        {
            return ( *this > rhs ) || ( *this == rhs );
        }
        bool operator<=( const Mod& rhs ) const
        {
            return ( *this < rhs ) || ( *this == rhs );
        }
        bool operator>( const Mod& rhs ) const
        {
            return rhs < *this;
        }
        bool operator<( const Mod& rhs ) const
        {
            return this->getValue() < rhs.getValue();
        }
    private:
        TYPE myValue;
    };
}
