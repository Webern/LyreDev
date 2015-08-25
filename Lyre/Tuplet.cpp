#include "Tuplet.h"

namespace lyre
{
    Tuplet::Tuplet()
    :myNumeratorDur( Dur::Quarter )
    ,myNumerator( 1 )
    ,myDenominatorDur( Dur::Quarter )
    ,myDenominator( 1 )
    {}
    
    Tuplet::Tuplet( const Integer numerator, const Dur numeratorDur,
                    const Integer denominator, const Dur denominatorDur )
    :myNumeratorDur( numeratorDur )
    ,myNumerator( 1 )
    ,myDenominatorDur( denominatorDur )
    ,myDenominator( 1 )
    {
        setNumerator( numerator );
        setDenominator( denominator );
    }
    Tuplet::Tuplet( const Dur durNumeratorAndDenominator,
                    const Integer numerator,
                   const Integer denominator )
    :myNumeratorDur( durNumeratorAndDenominator )
    ,myNumerator( 1 )
    ,myDenominatorDur( durNumeratorAndDenominator )
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
    Integer Tuplet::getNumerator() const
    {
        return myNumerator;
    }
    Integer Tuplet::getDenominator() const
    {
        return myDenominator;
    }
    Dur Tuplet::getNumeratorDur() const
    {
        return myNumeratorDur;
    }
    Dur Tuplet::getDenominatorDur() const
    {
        return myDenominatorDur;
    }
}