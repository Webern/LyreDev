#pragma once
#include <cmath>

namespace lyre
{
    namespace p
    {
        template <typename T, T M>
        class Mod
        {
        public:
            Mod()
            :myValue( 0 )
            {}
            explicit Mod( const T value )
            :myValue( value )
            {
                setValue( value );
            }
            T getValue() const
            {
                return myValue;
            }
            void setValue( const T value )
            {
                if ( value >= 0 )
                {
                    myValue = value % M;
                }
                else
                {
                    myValue = ( M - ( std::abs( value ) % M ) ) % M;
                }
            }
            Mod& add( const T value )
            {
                setValue( myValue + value );
                return *this;
            }
            Mod& subtract( const T value )
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
            T myValue;
        };
    }
}
