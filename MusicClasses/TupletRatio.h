#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"
#include "Rational.h"
#include "DurationCount.h"

namespace music
{
    
    class TupletRatio
    {
    public:
        
        TupletRatio();
        explicit TupletRatio( const DurationCount& numerator, const DurationCount& denominator );
        DurationCount getNumerator() const;
        void setNumerator( const DurationCount& value );
        DurationCount getDenominator() const;
        void setDenominator( const DurationCount& value );
        Rational getRational() const;
    private:
        DurationCount myNumerator;
        DurationCount myDenominator;
    };
}