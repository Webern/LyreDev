#pragma once
#include <iostream>
#include "TypeDefs.h"

/* I need rational numbers for music and I don't want to include boost */

namespace music
{
    class Rational
    {
    public:
        Rational();
        Rational( const Int numerator, const Int denominator );
        
        /* return the decimal approximation of the rational
         number as a calculator would. i.e. 1/3 -> 0.33333... */
        Float getFloat() const;
        
        Int getNumerator() const;
        void setNumerator( const Int value );
        
        Int getDenominator() const;
        void setDenominator( const Int value );
        
        /* return the greatest common divisor
         for a and b */
        static Int gcd( Int a, Int b );
        
        /* return the least common multiple
         for a and b */
        static Int lcm( Int a, Int b );
        
        /* convert a and b so that they have
         the same (least common) denominator */
        static void lcd( Rational& a, Rational& b );
        
        /* return the equivalent Rational number
         with the smallest possible denominator.
         also, if both numerator and denominator
         are negative, they will be replaced by
         positive numebrs. */
        static Rational reduce( const Rational& r );
        
        /* return the reciprocal as a Rational */
        Rational getReciprocal() const;
        
        /* */
        Rational& operator*=( const Rational& right );
        Rational& operator/=( const Rational& right );
    private:
        Int myNumerator;
        Int myDenominator;
    };
    
    /* Comparisons in the mathematical sense, i.e. 1/3 == 4/12 */
    bool operator==( const Rational& left, const Rational& right );
    bool operator!=( const Rational& left, const Rational& right );
    bool operator<( const Rational& left, const Rational& right );
    bool operator>( const Rational& left, const Rational& right );
    bool operator<=( const Rational& left, const Rational& right );
    bool operator>=( const Rational& left, const Rational& right );
    
    Rational operator/( const Rational& r, const Rational& l );
    Rational operator*( const Rational& r, const Rational& l );
    Rational operator+( const Rational& r, const Rational& l );
    Rational operator-( const Rational& r, const Rational& l );
    
    /* stream a textual representation of the Rational number */
    std::ostream& operator<<( std::ostream& os, const Rational& right );
    
}