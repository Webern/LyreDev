#pragma once
#include <iostream>
#include <memory>
#include "PitchSpecies.h"
#include "PitchStep.h"
#include "PitchAlter.h"

namespace music
{
    class PitchSpellerInterface;
    using PitchSpellerPtr = std::shared_ptr<PitchSpellerInterface>;
    using PitchSpellerUPtr = std::unique_ptr<PitchSpellerInterface>;
    class PitchSpellerInterface
    {
    public:
        virtual ~PitchSpellerInterface() = default;
        virtual const PitchStepPtr getPitchStep( const PitchSpecies& ) const =0;
        virtual const PitchAlterPtr getPitchAlter( const PitchSpecies& ) const =0;
    };
}