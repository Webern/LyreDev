#pragma once
#include <iostream>
#include <memory>
#include "PitchSpecies.h"
#include "Definitions.h"

namespace music
{
    class SpellerInterface;
    using SpellerPtr = std::shared_ptr<SpellerInterface>;
    using SpellerUPtr = std::unique_ptr<SpellerInterface>;
    class SpellerInterface
    {
    public:
        virtual ~SpellerInterface() = default;
        virtual const PitchStepPtr getPitchStep( const PitchSpecies& ) const =0;
        virtual const PitchAlterPtr getPitchAlter( const PitchSpecies& ) const =0;
        
        /* Deep Copy */
        virtual SpellerUPtr uclone() const = 0;
    };
}