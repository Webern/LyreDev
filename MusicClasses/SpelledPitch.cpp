#include "SpelledPitch.h"
#include "SpellerDefault.h"

namespace music
{
    SpelledPitch::SpelledPitch()
    :PitchSpecies( 0 )
    ,mySpeller( SpellerDefault::make() )
    {}
    
    SpelledPitch::SpelledPitch( const Integer value )
    :PitchSpecies( value )
    ,mySpeller( SpellerDefault::make() )
    {}
    
    SpelledPitch::SpelledPitch( const SpellerPtr& speller, const Integer value )
    :PitchSpecies( value )
    ,mySpeller( speller )
    {}
    
    SpelledPitch::SpelledPitch( const SpellerPtr& speller )
    :PitchSpecies( 0 )
    ,mySpeller( speller )
    {}

    SpelledPitchPtr SpelledPitch::make()
    {
        return std::make_shared<SpelledPitch>();
    }
    
    const PitchStepPtr SpelledPitch::getPitchStep() const
    {
        return mySpeller->getPitchStep( *this );
    }
    
    const PitchAlterPtr SpelledPitch::getPitchAlter() const
    {
        return mySpeller->getPitchAlter( *this );
    }
    void setSpeller( const SpellerPtr& speller )
    {
        
    }
}