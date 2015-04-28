#pragma once
#include <iostream>
#include <memory>
#include "PitchSpecies.h"
#include "Definitions.h"

namespace music
{
    class PitchSpeller;
    using PitchSpellerPtr = std::shared_ptr<PitchSpeller>;
    using SpellerUPtr = std::unique_ptr<PitchSpeller>;
    class PitchSpeller
    {
    public:
        virtual ~PitchSpeller() = default;
        virtual const PitchStepPtr getPitchStep( const PitchSpecies& ) const =0;
        virtual const PitchAlterPtr getPitchAlter( const PitchSpecies& ) const =0;
        
        /* Deep Copy */
        virtual SpellerUPtr uclone() const = 0;
    };
}