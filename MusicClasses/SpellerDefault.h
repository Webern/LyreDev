#pragma once
#include <iostream>
#include <memory>
#include "SpellerInterface.h"
//#include "PitchStep.h"
//#include "PitchAlter.h"
//#include "PitchSpecies.h"


namespace music
{
    class SpellerDefault;

    using SpellerDefaultPtr = std::shared_ptr<SpellerDefault>;
    using SpellerDefaultUPtr = std::unique_ptr<SpellerDefault>;
    class SpellerDefault : public SpellerInterface
    {

    public:
        virtual ~SpellerDefault() = default;
        static SpellerPtr make();
        virtual const PitchStepPtr getPitchStep( const PitchSpecies& pitchSpecies ) const;
        virtual const PitchAlterPtr getPitchAlter( const PitchSpecies& pitchSpecies ) const;
    };
}
