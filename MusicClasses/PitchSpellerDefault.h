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
    class PitchSpellerDefault : public PitchSpellerInterface
    {

    public:
        virtual ~PitchSpellerDefault() = default;
        static PitchSpellerPtr make();
        virtual const PitchStepPtr getPitchStep( const PitchSpecies& pitchSpecies ) const;
        virtual const PitchAlterPtr getPitchAlter( const PitchSpecies& pitchSpecies ) const;
    };
}
