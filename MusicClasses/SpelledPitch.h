#pragma once
#include <iostream>
#include "Definitions.h"
#include "PitchSpecies.h"
#include "PitchStep.h"
#include "PitchAlter.h"
#include "SpellerInterface.h"
#include "SpellerDefault.h"

namespace music
{
    class SpelledPitch;
    using SpelledPitchPtr = std::shared_ptr<SpelledPitch>;
    using SpelledPitchUPtr = std::unique_ptr<SpelledPitch>;
    class SpelledPitch : public PitchSpecies
    {
        
    public:
        SpelledPitch();
        explicit SpelledPitch( const Integer value );
        explicit SpelledPitch( const SpellerPtr& speller, const Integer value );
        explicit SpelledPitch( const SpellerPtr& speller );
        virtual ~SpelledPitch() = default;
        static SpelledPitchPtr make();
        const PitchStepPtr getPitchStep() const;
        const PitchAlterPtr getPitchAlter() const;
        const SpellerPtr getSpeller() const;
        void setSpeller( const SpellerPtr& speller );
    private:
        SpellerPtr mySpeller;
    };
}