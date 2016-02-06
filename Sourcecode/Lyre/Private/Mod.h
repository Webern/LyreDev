//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"

/* The Mod class restrics values of an integral
 to be between zero and MODULUS-1 by using the
 % operator. It probably only works for integral
 types (int, long, short, char, etc) */

namespace Lyre
{
    namespace Private
    {
        template <typename TYPE, TYPE MODULUS>
        class EXPORT_FOR_TESTS Mod
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
                    TYPE absval = value * -1;
                    myValue = ( MODULUS - ( absval % MODULUS ) ) % MODULUS;
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
}
