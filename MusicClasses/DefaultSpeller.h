#pragma once
#include <iostream>
#include <memory>
#include "Definitions.h"
#include "PitchSpeller.h"


namespace music
{
    class DefaultSpeller;
    using DefaultPitchSpellerPtr = std::shared_ptr<DefaultSpeller>;
    
    class DefaultSpeller : public PitchSpeller
    {

    public:
        virtual ~DefaultSpeller() = default;
        static PitchSpellerPtr make();
        virtual const PitchStepPtr getPitchStep( const PitchSpecies& pitchSpecies ) const;
        virtual const PitchAlterPtr getPitchAlter( const PitchSpecies& pitchSpecies ) const;
        virtual SpellerUPtr uclone() const;
    };
}
