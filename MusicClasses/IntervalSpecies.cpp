#include "IntervalSpecies.h"
#include "Mod.h"
#include <cmath>
#include "PitchAlter.h"
#include "PitchStep.h"
#include "SpellerInterface.h"
#include "DefaultSpeller.h"

namespace music
{
    /* Construction */
    
    IntervalSpecies::IntervalSpecies()
    :myValue( 0 )
    ,mySpeller( new DefaultSpeller{} )
    {}
    
    IntervalSpecies::IntervalSpecies( const Integer value )
    :myValue( value )
    ,mySpeller( new DefaultSpeller{} )
    {}
    
    IntervalSpecies::IntervalSpecies( const SpellerPtr& speller, const Integer value )
    :myValue( value )
    ,mySpeller( speller->uclone() )
    {}
    
    
    IntervalSpecies::~IntervalSpecies() {}
    
    IntervalSpeciesPtr IntervalSpecies::make()
    {
        return std::make_shared<IntervalSpecies>();
    }
    
    IntervalSpeciesPtr IntervalSpecies::make(const Integer value )
    {
        return std::make_shared<IntervalSpecies>( value );
    }
    IntervalSpeciesPtr IntervalSpecies::make( const IntervalSpeciesPtr& other )
    {
        return std::make_shared<IntervalSpecies>( *other );
    }
    
    /* Copy */
    
    IntervalSpecies::IntervalSpecies( const IntervalSpecies& other )
    :myValue( other.myValue )
    ,mySpeller( other.mySpeller->uclone() )
    {}
    
    IntervalSpecies::IntervalSpecies( IntervalSpecies&& other )
    :myValue( std::move( other.myValue ) )
    ,mySpeller( std::move( other.mySpeller ) )
    {}
    
    IntervalSpecies& IntervalSpecies::operator=( const IntervalSpecies& other )
    {
        myValue = other.myValue;
        mySpeller = other.mySpeller->uclone();
        return *this;
    }
    IntervalSpecies& IntervalSpecies::operator=( IntervalSpecies&& other )
    {
        myValue = std::move( other.myValue );
        mySpeller = std::move( other.mySpeller );
        return *this;
    }
    
    /* Get Set */
    
    Integer IntervalSpecies::getValue() const
    {
        return myValue.getValue();
    }
    
    void IntervalSpecies::setValue( const Integer value )
    {
        myValue.setValue( value );
    }
    
    /* Math */
    
    IntervalSpecies& IntervalSpecies::add( const Integer value )
    {
        myValue.add( value );
        return *this;
    }
    IntervalSpecies& IntervalSpecies::subtract( const Integer value )
    {
        myValue.subtract( value );
        return *this;
    }
    
    /* Increment */
    
    IntervalSpecies& IntervalSpecies::operator++()
    {
        ++myValue;
        return *this;
    }
    IntervalSpecies IntervalSpecies::operator++(int)
    {
        IntervalSpecies temp = *this;
        myValue++;
        return temp;
    }
    IntervalSpecies& IntervalSpecies::operator--()
    {
        --myValue;
        return *this;
    }
    IntervalSpecies IntervalSpecies::operator--(int)
    {
        IntervalSpecies temp = *this;
        myValue--;
        return temp;
    }
    
    
}