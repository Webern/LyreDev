#pragma once
#include <iostream>
#include <memory>
#include "PitchSpellerInterface.h"
//#include "PitchStep.h"
//#include "PitchAlter.h"
//#include "PitchSpecies.h"

namespace music
{
    class PitchSpellerDefault;
    using PitchSpellerDefaultPtr = std::shared_ptr<PitchSpellerDefault>;
    using PitchSpellerDefaultUPtr = std::unique_ptr<PitchSpellerDefault>;
    class PitchSpellerDefault
    {
    public:
        virtual ~PitchSpellerDefault() = default;
        const PitchStepPtr getPitchStep( const PitchSpecies& pitchSpecies ) const;
        const PitchAlterPtr getPitchAlter( const PitchSpecies& pitchSpecies ) const;
        static PitchSpellerPtr make();
    };
}