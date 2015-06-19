#pragma once
#include "TypeDefs.h"

namespace music
{
    class Rational
    {
    public:
        Rational();
        Rational( const Int numerator, const Int denominator );
        Float getFloat() const;
        
        Int getNumerator() const;
        void setNumerator( const Int value );
        Int getDenominator() const;
        void setDenominator( const Int value );
        static Int gcd( Int a, Int b );
        static Int lcm( Int a, Int b );
        static Rational simplify( const Rational& input );
    private:
        Int myNumerator;
        Int myDenominator;
    };
    
    bool operator==( const Rational& left, const Rational& right );
}