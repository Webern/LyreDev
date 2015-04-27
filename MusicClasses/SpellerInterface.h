#pragma once
#include <iostream>
#include <memory>
#include "PitchSpecies.h"
#include "Forward.h"

namespace music
{
    class SpellerInterface;
    using SpellerPtr = std::shared_ptr<SpellerInterface>;
    using SpellerUPtr = std::unique_ptr<SpellerInterface>;
    class SpellerInterface
    {
    public:
        virtual ~SpellerInterface() = default;
        virtual const PitchStepPtr getPitchStep( const PitchSpeciesPtr& ) const =0;
        virtual const PitchAlterPtr getPitchAlter( const PitchSpeciesPtr& ) const =0;
    };
}