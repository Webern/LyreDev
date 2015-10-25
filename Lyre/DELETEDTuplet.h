//PRIVATE
#pragma once
#include "TypeDefs.h"
#include "DurDot.h"

namespace lyre
{
    
    class Tuplet
    {
    public:
        
        Tuplet(); /* defaults to 1Q/1Q, i.e. not a tuplet */
        explicit Tuplet( const Integer numeratorCount, const Dur numeratorDur,
                              const Integer denomintorCount, const Dur denominatorDur );
        explicit Tuplet( const Dur durNumeratorAndDenominator,
                              const Integer numerator,
                              const Integer denominator );

        /* positive Integer input is required, if
         you pass a zero or negative Integer,
         these functions will set the value to 1
         instead */
        void setNumerator( const Integer value);
        void setDenominator( const Integer value );
        void setNumeratorDur( const DurDot& value );
        void setDenominatorDur( const DurDot& value );
        
        Integer getNumerator() const;
        Integer getDenominator() const;
        DurDot getNumeratorDur() const;
        DurDot getDenominatorDur() const;
        
    private:
        DurDot myNumeratorDur;
        Integer myNumerator;
        DurDot myDenominatorDur;
        Integer myDenominator;
        Integer positiveInt( const Integer input ) const;
    };
}