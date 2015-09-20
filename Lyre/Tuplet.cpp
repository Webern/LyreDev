#include "Tuplet.h"

namespace lyre
{
    Tuplet::Tuplet()
    :myNumeratorDur{ Dur::Quarter, 0 }
    ,myNumerator( 1 )
    ,myDenominatorDur( Dur::Quarter )
    ,myDenominator( 1 )
    {}
    
    Tuplet::Tuplet( const Integer numerator, const Dur numeratorDur,
                    const Integer denominator, const Dur denominatorDur )
    :myNumeratorDur{ numeratorDur, 0 }
    ,myNumerator( 1 )
    ,myDenominatorDur( denominatorDur, 0 )
    ,myDenominator( 1 )
    {
        setNumerator( numerator );
        setDenominator( denominator );
    }
    Tuplet::Tuplet( const Dur durNumeratorAndDenominator,
                    const Integer numerator,
                   const Integer denominator )
    :myNumeratorDur{ durNumeratorAndDenominator, 0 }
    ,myNumerator( 1 )
    ,myDenominatorDur{ durNumeratorAndDenominator, 0 }
    ,myDenominator( 1 )
    {
        setNumerator( numerator );
        setDenominator( denominator );
    }
    Integer Tuplet::positiveInt( const Integer input ) const
    {
        if ( input > 0 )
        {
            return input;
        }
        return 1;
    }
    void Tuplet::setNumerator( const Integer value)
    {
        myNumerator = positiveInt( value );
    }
    void Tuplet::setDenominator( const Integer value )
    {
        myDenominator = positiveInt( value );
    }
    void Tuplet::setNumeratorDur( const DurDot& value )
    {
        myNumeratorDur = value;
    }
    void Tuplet::setDenominatorDur( const DurDot& value )
    {
        myDenominatorDur = value;
    }
    Integer Tuplet::getNumerator() const
    {
        return myNumerator;
    }
    Integer Tuplet::getDenominator() const
    {
        return myDenominator;
    }
    DurDot Tuplet::getNumeratorDur() const
    {
        return myNumeratorDur;
    }
    DurDot Tuplet::getDenominatorDur() const
    {
        return myDenominatorDur;
    }
}