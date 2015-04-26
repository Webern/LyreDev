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
    
    PitchStepPtr PitchStep::make( const Integer value )
    {
        return std::make_shared<PitchStep>( value );
    }
    Integer PitchStep::getValue() const
    {
        return myValue.getValue();
    }
    
    void PitchStep::setValue( const Integer value )
    {
        myValue.setValue( value );
    }
    
    Integer PitchStep::getPitchSpeciesEquivalent() const
    {
        switch ( myValue.getValue() )
        {
            case 0:
                return 0;
                break;
            case 1:
                return 2;
                break;
            case 2:
                return 4;
                break;
            case 3:
                return 5;
                break;
            case 4:
                return 7;
                break;
            case 5:
                return 9;
                break;
            case 6:
                return 11;
                break;
            default:
                throw std::runtime_error( "PitchStep::getPitchSpeciesEquivalent() unknown PitchStep value" );
                break;
        }
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