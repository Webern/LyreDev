#include "PitchSpecies.h"
#include "Mod.h"
#include <cmath>
#include "PitchAlter.h"
#include "PitchStep.h"
#include "SpellerInterface.h"
#include "DefaultSpeller.h"

namespace music
{
    /* Construction */
    
    PitchSpecies::PitchSpecies()
    :myValue( 0 )
    ,mySpeller( new DefaultSpeller{} )
    {}
    
    PitchSpecies::PitchSpecies( const Integer value )
    :myValue( value )
    ,mySpeller( new DefaultSpeller{} )
    {}
    
    PitchSpecies::PitchSpecies( const SpellerPtr& speller, const Integer value )
    :myValue( value )
    ,mySpeller( speller->uclone() )
    {}
    
    
    PitchSpecies::~PitchSpecies() {}
    
    PitchSpeciesPtr PitchSpecies::make()
    {
        return std::make_shared<PitchSpecies>();
    }
    
    PitchSpeciesPtr PitchSpecies::make(const Integer value )
    {
        return std::make_shared<PitchSpecies>( value );
    }
    PitchSpeciesPtr PitchSpecies::make( const PitchSpeciesPtr& other )
    {
        return std::make_shared<PitchSpecies>( *other );
    }
    
    /* Copy */
    
    PitchSpecies::PitchSpecies( const PitchSpecies& other )
    :myValue( other.myValue )
    ,mySpeller( other.mySpeller->uclone() )
    {}
    
    PitchSpecies::PitchSpecies( PitchSpecies&& other )
    :myValue( std::move( other.myValue ) )
    ,mySpeller( std::move( other.mySpeller ) )
    {}
    
    PitchSpecies& PitchSpecies::operator=( const PitchSpecies& other )
    {
        myValue = other.myValue;
        mySpeller = other.mySpeller->uclone();
        return *this;
    }
    PitchSpecies& PitchSpecies::operator=( PitchSpecies&& other )
    {
        myValue = std::move( other.myValue );
        mySpeller = std::move( other.mySpeller );
        return *this;
    }
    
    /* Get Set */
    
    Integer PitchSpecies::getValue() const
    {
        return myValue.getValue();
    }
    
    void PitchSpecies::setValue( const Integer value )
    {
        myValue.setValue( value );
    }
    
    /* Math */
    
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
    
    /* Increment */
    
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
    
    /* Spelling */
    const PitchStepPtr PitchSpecies::getPitchStep() const
    {
        return mySpeller->getPitchStep( *this );
    }
    const PitchAlterPtr PitchSpecies::getPitchAlter() const
    {
        return mySpeller->getPitchAlter( *this );
    }
    const SpellerUPtr& PitchSpecies::getSpeller() const
    {
        return mySpeller;
    }
    void PitchSpecies::setSpeller( const SpellerUPtr& speller )
    {
        mySpeller = speller->uclone();
    }
    void PitchSpecies::setSpeller( SpellerUPtr&& speller )
    {
        mySpeller = std::move( speller );
    }
}