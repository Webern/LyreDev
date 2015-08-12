#pragma once
#include <iostream>
#include <memory>
#include "Definitions.h"
#include "IntervalSpecies.h"

namespace music
{
    enum class DefaultIntervalName
    {
        unison = 0,
        minorSecond = 1,
        majorSecond = 2,
        minorThird = 3,
        majorThird = 4,
        fourth = 5,
        tritone = 6,
        fifth = 7,
        minorSixth = 8,
        majorSixth = 9,
        minorSeventh = 10,
        majorSeventh = 11
    };
    class DefaultIntervalSpeller;
    using DefaultIntervalSpellerPtr = std::shared_ptr<DefaultIntervalSpeller>;
    using DefaultIntervalSpellerUPtr = std::unique_ptr<DefaultIntervalSpeller>;
    
    class DefaultIntervalSpeller
    {
    public:
        virtual ~DefaultIntervalSpeller() = default;
        virtual Integer getDiatonicSteps( const IntervalSpecies& ) const;
        virtual Integer getAlter( const IntervalSpecies& ) const;
        DefaultIntervalName getName() const;
        
        /* Deep Copy */
        virtual DefaultIntervalSpellerUPtr uclone() const;
    };
}