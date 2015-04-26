/* matthew james briggs */

#include "PitchSpecies.h"
#include <cmath>

namespace music
{

    PitchSpecies::PitchSpecies()
    :myValue( 0 )
    {}
    
    PitchSpecies::PitchSpecies( const Integer value )
    :myValue( 0 )
    {
        setValue( value );
    }
    
    PitchSpecies::~PitchSpecies() {}
    
    Integer PitchSpecies::getValue() const
    {
        return myValue;
    }
    
    void PitchSpecies::setValue( const Integer value )
    {
        if ( value >= 0 )
        {
            myValue = value % 12;
        }
        else
        {
            myValue = ( 12 - ( std::abs( value ) % 12 ) ) % 12;
        }
    }
    
    PitchSpecies::operator Integer() const
    {
        return myValue;
    }
    
    PitchSpecies& PitchSpecies::operator++()
    {
        setValue( ( ++myValue ) );
        return *this;
    }
    PitchSpecies PitchSpecies::operator++(int)
    {
        PitchSpecies temp = *this;
        setValue( ( ++myValue ) );
        return temp;
    }
    PitchSpecies& PitchSpecies::operator--()
    {
        setValue( ( --myValue ) );
        return *this;
    }
    PitchSpecies PitchSpecies::operator--(int)
    {
        PitchSpecies temp = *this;
        setValue( ( --myValue ) );
        return temp;
    }
    
    bool operator==( const PitchSpecies& lhs, const PitchSpecies& rhs )
    {
        return lhs.getValue() == rhs.getValue();
    }
    bool operator!=( const PitchSpecies& lhs, const PitchSpecies& rhs )
    {
        return ! ( lhs == rhs );
    }
    bool operator>=( const PitchSpecies& lhs, const PitchSpecies& rhs )
    {
        return ( lhs > rhs ) || ( lhs == rhs );
    }
    bool operator<=( const PitchSpecies& lhs, const PitchSpecies& rhs )
    {
        return ( lhs < rhs ) || ( lhs == rhs );
    }
    bool operator>( const PitchSpecies& lhs, const PitchSpecies& rhs )
    {
        return rhs < lhs;
    }
    bool operator<( const PitchSpecies& lhs, const PitchSpecies& rhs )
    {
        return lhs.getValue() < rhs.getValue();
    }
    PitchSpecies operator+( const PitchSpecies& lhs, const PitchSpecies& rhs )
    {
        return PitchSpecies{ lhs.getValue() + rhs.getValue() };
    }
    PitchSpecies operator-( const PitchSpecies& lhs, const PitchSpecies& rhs )
    {
        return PitchSpecies{ lhs.getValue() - rhs.getValue() };
    }
}