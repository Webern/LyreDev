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
    class PitchSpeciesSpelled;
    using PitchSpeciesSpelledPtr = std::shared_ptr<PitchSpeciesSpelled>;
    using PitchSpeciesSpelledUPtr = std::unique_ptr<PitchSpeciesSpelled>;
    class PitchSpeciesSpelled : public PitchSpecies
    {
        
    public:
        PitchSpeciesSpelled();
        explicit PitchSpeciesSpelled( const Integer value );
        explicit PitchSpeciesSpelled( const PitchSpellerPtr& speller, const Integer value );
        explicit PitchSpeciesSpelled( const PitchSpellerPtr& speller );
        virtual ~PitchSpeciesSpelled() = default;
        static PitchSpeciesSpelledPtr make();
        const PitchStepPtr getPitchStep() const;
        const PitchAlterPtr getPitchAlter() const;
        const PitchSpellerPtr getPitchSpeller() const;
        void setPitchSpeller( const PitchSpellerPtr& speller );
    private:
        PitchSpellerPtr mySpeller;
    };
}