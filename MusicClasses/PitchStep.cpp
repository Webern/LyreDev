#include "PitchStep.h"
#include "Mod.h"
#include <cmath>

namespace music
{
    
    PitchStep::PitchStep()
    :myValue( 0 )
    {}
    
    PitchStep::PitchStep( const Integer value )
    :myValue( value )
    {}
    
    PitchStep::~PitchStep() {}
    
    Integer PitchStep::getValue() const
    {
        return myValue.getValue();
    }
    
    void PitchStep::setValue( const Integer value )
    {
        myValue.setValue( value );
    }
    PitchStep& PitchStep::add( const Integer value )
    {
        myValue.add( value );
        return *this;
    }
    PitchStep& PitchStep::subtract( const Integer value )
    {
        myValue.subtract( value );
        return *this;
    }
    PitchStep& PitchStep::operator++()
    {
        ++myValue;
        return *this;
    }
    PitchStep PitchStep::operator++(int)
    {
        PitchStep temp = *this;
        myValue++;
        return temp;
    }
    PitchStep& PitchStep::operator--()
    {
        --myValue;
        return *this;
    }
    PitchStep PitchStep::operator--(int)
    {
        PitchStep temp = *this;
        myValue--;
        return temp;
    }
    bool PitchStep::operator==( const PitchStep& rhs ) const
    {
        return this->myValue == rhs.myValue;
    }
    bool PitchStep::operator!=( const PitchStep& rhs ) const
    {
        return this->myValue != rhs.myValue;
    }
    bool PitchStep::operator>=( const PitchStep& rhs ) const
    {
        return this->myValue >= rhs.myValue;
    }
    bool PitchStep::operator<=( const PitchStep& rhs ) const
    {
        return this->myValue <= rhs.myValue;
    }
    bool PitchStep::operator>( const PitchStep& rhs ) const
    {
        return this->myValue > rhs.myValue;
    }
    bool PitchStep::operator<( const PitchStep& rhs ) const
    {
        return this->myValue < rhs.myValue;
    }
}