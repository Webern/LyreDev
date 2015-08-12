#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"
#include "Rational.h"
#include "DurationBase.h"
#include "TupletRatio.h"

namespace music
{
    class Duration;
    using DurationPtr = std::shared_ptr<Duration>;
    using DurationUPtr = std::unique_ptr<Duration>;
    using DurationSet = std::vector<DurationPtr>;
    using DurationSetIter = DurationSet::iterator;
    using DurationSetIterConst = DurationSet::const_iterator;

    
    class Duration
    {
    public:
        virtual ~Duration() = default;
        Duration();
        explicit Duration( const DurationBase& base );
        explicit Duration( const DurationBase& base, const Int dotCount );
        explicit Duration( const DurationBase& base, const Int dotCount, const TupletRatio& tuplet );
        explicit Duration( const DurationBase& base, const TupletRatio& tuplet );
        DurationBase getDurationBase() const;
        void setDurationBase( const DurationBase& value );
        TupletRatio getTupletRatio() const;
        void setTupletRatio( const TupletRatio& value );
        Int getDotCount() const;
        void setDotCount( const Int value );
        Rational getRational() const;
    private:
        DurationBase myDurationBase;
        TupletRatio myTupletRatio;
        Int myDotCount;
    };
}