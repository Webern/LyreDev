#include "TimeSignature.h"

namespace music
{
    TimeSignature::TimeSignature()
    :myBeatCount( 4 )
    ,myBeatDuration( Duration( DurationBase( DurationName::Quarter ) ) )
    {}
    
    TimeSignature::TimeSignature( Int beatCount, const Duration& beatDuration )
    :myBeatCount( beatCount )
    ,myBeatDuration( Duration( DurationBase( DurationName::Quarter ) ) )
    {
        setBeatCount( beatCount );
    }
    Int TimeSignature::getBeatCount() const
    {
        return myBeatCount;
    }
    Duration TimeSignature::getBeatDuration() const
    {
        return myBeatDuration;
    }
    Rational TimeSignature::getMeasureDuration() const
    {
        return myBeatDuration.getRational() * Rational{ myBeatCount, 1 };
    }
    void TimeSignature::setBeatCount( const Int value )
    {
        if ( value < 1 )
        {
            myBeatCount = 1;
        }
        else
        {
            myBeatCount = value;
        }
    }
    void TimeSignature::setBeatDuration( const Duration& value )
    {
        myBeatDuration = value;
    }
    Int TimeSignature::getDenominator() const
    {
        Rational r = myBeatDuration.getRational();
        Rational denominator = r.getReciprocal();
        denominator *= Rational{ 4, 1 };
        denominator = Rational::reduce( denominator );
        if ( denominator.getDenominator() == 1 )
        {
            return denominator.getNumerator();
        }
        throw std::runtime_error( "Impossible time signature" );
    }
}