#include "PitchSpecies.h"
#include "Mod.h"
#include <cmath>

namespace music
{

    PitchSpecies::PitchSpecies()
    :myValue( 0 )
    {}
    
    PitchSpecies::PitchSpecies( const Integer value )
    :myValue( value )
    {}
    
    PitchSpecies::~PitchSpecies() {}
    
    Integer PitchSpecies::getValue() const
    {
        return myValue.getValue();
    }
    
    void PitchSpecies::setValue( const Integer value )
    {
        myValue.setValue( value );
    }
    PitchSpecies& PitchSpecies::add( const Integer value )
    {
        myValue.add( value );
        return *this;
    }
    PitchSpecies& PitchSpecies::subtract( const Integer value )
    {
        myValue.subtract( value );
        return *this;
    }
    PitchSpecies& PitchSpecies::operator++()
    {
        ++myValue;
        return *this;
    }
    PitchSpecies PitchSpecies::operator++(int)
    {
        PitchSpecies temp = *this;
        myValue++;
        return temp;
    }
    PitchSpecies& PitchSpecies::operator--()
    {
        --myValue;
        return *this;
    }
    PitchSpecies PitchSpecies::operator--(int)
    {
        PitchSpecies temp = *this;
        myValue--;
        return temp;
    }
    bool PitchSpecies::operator==( const PitchSpecies& rhs ) const
    {
        return this->myValue == rhs.myValue;
    }
    bool PitchSpecies::operator!=( const PitchSpecies& rhs ) const
    {
        return this->myValue != rhs.myValue;
    }
    bool PitchSpecies::operator>=( const PitchSpecies& rhs ) const
    {
        return this->myValue >= rhs.myValue;
    }
    bool PitchSpecies::operator<=( const PitchSpecies& rhs ) const
    {
        return this->myValue <= rhs.myValue;
    }
    bool PitchSpecies::operator>( const PitchSpecies& rhs ) const
    {
        return this->myValue > rhs.myValue;
    }
    bool PitchSpecies::operator<( const PitchSpecies& rhs ) const
    {
        return this->myValue < rhs.myValue;
    }
}