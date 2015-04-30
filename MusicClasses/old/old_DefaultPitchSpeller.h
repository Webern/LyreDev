#pragma once
#include <iostream>
#include <memory>
#include "Definitions.h"
#include "PitchSpeller.h"


namespace music
{
    class DefaultPitchSpeller;
    using DefaultPitchSpellerPtr = std::shared_ptr<DefaultPitchSpeller>;
    
    class DefaultPitchSpeller : public PitchSpeller
    {

    public:
        virtual ~DefaultPitchSpeller() = default;
        static PitchSpellerPtr make();
        virtual const PitchStepPtr getPitchStep( const PitchSpecies& pitchSpecies ) const;
        virtual const PitchAlterPtr getPitchAlter( const PitchSpecies& pitchSpecies ) const;
        virtual PitchSpellerUPtr uclone() const;
    };
}
