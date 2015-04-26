#pragma once
#include <iostream>
#include "Definitions.h"
#include "PitchSpecies.h"
#include "PitchStep.h"
#include "PitchAlter.h"
#include "PitchSpellerInterface.h"
#include "PitchSpellerDefault.h"

namespace music
{
    class PitchSpeciesSpelled : public PitchSpecies
    {
        
    public:
        PitchSpeciesSpelled();
        explicit PitchSpeciesSpelled( const Integer value );
        explicit PitchSpeciesSpelled( const PitchSpellerPtr& speller, const Integer value );
        virtual ~PitchSpeciesSpelled();
        const PitchStep getPitchStep() const;
        const PitchAlter getPitchAlter() const;
        
    private:
        PitchSpellerPtr mySpeller;
    };
}