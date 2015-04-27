#pragma once
#include <iostream>
#include <memory>
#include "Forward.h"
#include "SpellerInterface.h"


namespace music
{
    class DefaultSpeller;
    using DefaultSpellerPtr = std::shared_ptr<DefaultSpeller>;
    
    class DefaultSpeller : public SpellerInterface
    {

    public:
        virtual ~DefaultSpeller() = default;
        static SpellerPtr make();
        virtual const PitchStepPtr getPitchStep( const PitchSpeciesPtr& pitchSpecies ) const;
        virtual const PitchAlterPtr getPitchAlter( const PitchSpeciesPtr& pitchSpecies ) const;
    };
}
