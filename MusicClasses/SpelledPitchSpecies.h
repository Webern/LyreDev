#pragma once
#include <iostream>
#include "Definitions.h"
#include "PitchSpecies.h"
#include "PitchStep.h"
#include "PitchAlter.h"

namespace music
{
    class SpelledPitchSpecies
    {
        
    public:
        SpelledPitchSpecies();
        explicit SpelledPitchSpecies( const Integer value );
        virtual ~SpelledPitchSpecies();
        const PitchStep getPitchStep() const;
        const PitchAlter getPitchAlter() const;
        
    private:
        
    };
}