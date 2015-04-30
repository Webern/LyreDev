#pragma once
#include <iostream>
#include <memory>
#include "PitchSpecies.h"
#include "Definitions.h"

namespace music
{
    class IntervalSpeller;
    using IntervalSpellerPtr = std::shared_ptr<IntervalSpeller>;
    using IntervalSpellerUPtr = std::unique_ptr<IntervalSpeller>;
    
    class IntervalSpeller
    {
    public:
        virtual ~IntervalSpeller() = default;
        virtual Integer getDiatonicSteps( const IntervalSpecies& ) const =0;
        virtual Integer getAlter( const IntervalSpecies& ) const =0;
        
        /* Deep Copy */
        virtual IntervalSpellerUPtr uclone() const = 0;
    };
}