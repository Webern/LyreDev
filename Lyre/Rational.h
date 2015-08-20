#pragma once
#include <iostream>
#include "TypeDefs.h"

/* I need rational numbers for music and I don't
 want to include boost.  This would be a good
 candidate for template generalization, but I
 don't anticipate needing it for anything other
 than int. */

namespace lyre
{
    namespace p
    {
        class Rational
        {
        public:
            /* Default constructor sets value to 0/1.
             If you use the value constructor and try
             to set the denominator to 0, the denominator
             will be set to 1 instead. */
            Rational();
            Rational( const Integer numerator, const Integer denominator );
            
            /* return the decimal approximation of the rational
             number as a calculator would. i.e. 1/3 -> 0.33333... */
            Float getFloat() const;
            
            Integer getNumerator() const;
            void setNumerator( const Integer value );
            
            /* Denominator cannot be zero,
             attempting to set the denominator
             to zero is a no-op. */
            Integer getDenominator() const;
            void setDenominator( const Integer value );
            
            /* return the greatest common divisor
             for a and b */
            static Integer gcd( Integer a, Integer b );
            static Integer gcd( std::initializer_list<int> integers );
            
            /* return the least common multiple
             for a and b */
            static Integer lcm( Integer a, Integer b );
            
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
            Rational& operator/=( const Rational& right );
            Rational& operator*=( const Rational& right );
            Rational& operator+=( const Rational& right ); /* not implemented */
            Rational& operator-=( const Rational& right ); /* not implemented */
        private:
            Integer myNumerator;
            Integer myDenominator;
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
}
