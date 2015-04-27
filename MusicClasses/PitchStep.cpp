#include "PitchStep.h"
#include "Mod.h"
#include <cmath>
#include "PitchSpecies.h"

namespace music
{
    
    PitchStep::PitchStep()
    :myValue( 0 )
    {}
    
    PitchStep::PitchStep( const Integer value )
    :myValue( value )
    {}
    
    PitchStep::PitchStep( const PitchStepName value )
    :myValue( 0 )
    {
        setValue( value );
    }
    
    PitchStep::~PitchStep() {}
    
    PitchStepPtr PitchStep::make( const Integer value )
    {
        return std::make_shared<PitchStep>( value );
    }
    
    PitchStepPtr PitchStep::make( const PitchStepName value )
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
    void PitchStep::setValue( const PitchStepName value )
    {
        switch ( value )
        {
            case PitchStepName::c:
                myValue.setValue( 0 );
                break;
            case PitchStepName::d:
                myValue.setValue( 1 );
                break;
            case PitchStepName::e:
                myValue.setValue( 2 );
                break;
            case PitchStepName::f:
                myValue.setValue( 3 );
                break;
            case PitchStepName::g:
                myValue.setValue( 4 );
                break;
            case PitchStepName::a:
                myValue.setValue( 5 );
                break;
            case PitchStepName::b:
                myValue.setValue( 6 );
                break;
            default:
                throw std::runtime_error( "PitchStep::setValue( const PitchStepName value ) unknown PitchStep value" );
                break;
        }
    }
    PitchStep::operator PitchStepName() const
    {
        switch ( myValue.getValue() )
        {
            case 0:
                return PitchStepName::c;
                break;
            case 1:
                return PitchStepName::d;
                break;
            case 2:
                return PitchStepName::e;
                break;
            case 3:
                return PitchStepName::f;
                break;
            case 4:
                return PitchStepName::g;
                break;
            case 5:
                return PitchStepName::a;
                break;
            case 6:
                return PitchStepName::b;
                break;
            default:
                throw std::runtime_error( "PitchStep::operator PitchStepName() unknown PitchStep value" );
                break;
        }
    }
    PitchSpeciesPtr PitchStep::getPitchSpeciesEquivalent() const
    {
        switch ( myValue.getValue() )
        {
            case 0:
                return PitchSpecies::make( 0 );
                break;
            case 1:
                return PitchSpecies::make( 2 );
                break;
            case 2:
                return PitchSpecies::make( 4 );
                break;
            case 3:
                return PitchSpecies::make( 5 );
                break;
            case 4:
                return PitchSpecies::make( 7 );
                break;
            case 5:
                return PitchSpecies::make( 9 );
                break;
            case 6:
                return PitchSpecies::make( 11 );
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