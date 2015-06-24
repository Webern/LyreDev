#include "TupletRatio.h"

namespace music
{
    TupletRatio::TupletRatio()
    :myNumerator{ DurationCount{ DurationBase{ DurationName::Quarter }, 1 } }
    ,myDenominator{ DurationCount{ DurationBase{ DurationName::Quarter }, 1 } }
    {}
    TupletRatio::TupletRatio( const DurationCount& numerator, const DurationCount& denominator )
    :myNumerator{ DurationCount{ DurationBase{ DurationName::Quarter }, 1 } }
    ,myDenominator{ DurationCount{ DurationBase{ DurationName::Quarter }, 1 } }
    {}
    DurationCount TupletRatio::getNumerator() const
    {
        return myNumerator;
    }
    void TupletRatio::setNumerator( const DurationCount& value )
    {
        myNumerator = value;
    }
    DurationCount TupletRatio::getDenominator() const
    {
        return myDenominator;
    }
    void TupletRatio::setDenominator( const DurationCount& value )
    {
        myDenominator = value;
    }
    Rational TupletRatio::getRational() const
    {
        Rational numerator = myNumerator.getDurationBase().getRational();
        numerator *= Rational{ myNumerator.getCount(), 1 };
        Rational denominator = myDenominator.getDurationBase().getRational();
        denominator *= Rational{ myDenominator.getCount(), 1 };
        return ( numerator / denominator );
    }
}