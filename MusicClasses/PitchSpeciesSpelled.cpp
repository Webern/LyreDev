#include "PitchSpeciesSpelled.h"
#include "PitchSpellerDefault.h"

namespace music
{
    PitchSpeciesSpelled::PitchSpeciesSpelled()
    :PitchSpecies( 0 )
    ,mySpeller( PitchSpellerDefault::make() )
    {}
    
    PitchSpeciesSpelled::PitchSpeciesSpelled( const Integer value )
    :PitchSpecies( value )
    ,mySpeller( PitchSpellerDefault::make() )
    {}
    
    PitchSpeciesSpelled::PitchSpeciesSpelled( const PitchSpellerPtr& speller, const Integer value )
    :PitchSpecies( value )
    ,mySpeller( speller )
    {}
    
    PitchSpeciesSpelled::PitchSpeciesSpelled( const PitchSpellerPtr& speller )
    :PitchSpecies( 0 )
    ,mySpeller( speller )
    {}

    PitchSpeciesSpelledPtr PitchSpeciesSpelled::make()
    {
        return std::make_shared<PitchSpeciesSpelled>();
    }
    
    const PitchStepPtr PitchSpeciesSpelled::getPitchStep() const
    {
        return mySpeller->getPitchStep( *this );
    }
    
    const PitchAlterPtr PitchSpeciesSpelled::getPitchAlter() const
    {
        return mySpeller->getPitchAlter( *this );
    }
    void setPitchSpeller( const PitchSpellerPtr& speller )
    {
        
    }
}