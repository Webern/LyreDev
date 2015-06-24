#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"
#include "Rational.h"

namespace music
{
    class Duration;
    using DurationPtr = std::shared_ptr<Duration>;
    using DurationUPtr = std::unique_ptr<Duration>;
    using DurationSet = std::vector<DurationPtr>;
    using DurationSetIter = DurationSet::iterator;
    using DurationSetIterConst = DurationSet::const_iterator;
    
    enum class DurationName
    {
        // Name // NumQuarterNotes //
        Longa = 0, // 16
        Breve = 1, // 8
        Whole = 2, // 4
        Half = 3, // 2
        Quarter = 4, // 1
        Eighth = 5, // 1/2
        Sixteenth = 6, // 1/4
        ThirtySecond = 7, // 1/8
        SixtyFourth = 8, // 1/16
        OneTwentyEighth = 9 // 1/32
    };

    class DurationBase
    {
    public:
        virtual ~DurationBase() = default;
        DurationBase();
        explicit DurationBase( const DurationName& value );
        DurationName getDurationName() const;
        void setDurationName( const DurationName& value );
        Rational getRational() const;
    private:
        DurationName myValue;
    };
}