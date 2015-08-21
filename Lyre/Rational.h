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
             for a and b.  if both a and b are zero,
             gcd returns zero. if a OR b is zero, the
             absolute value of the non-zero term is
             returned */
            static Integer gcd( Integer a, Integer b );
            
            /* return the greatest common divisor for
             all of the integers in the list.  you should
             only use this for lists of 2 or more non-
             zero numbers.  otherwise... if zero is
             encountered more than once, a std::runtime_error
             is thrown. if zero is encountered once, it does
             not affect the outcome.  if the list has a
             single non-zero term, the absolute value of the
             single term is returned.  if the list has a
             single term which is a zero, 1 is returned */
            static Integer gcd( std::initializer_list<Integer> integers );
            
            /* return the least common multiple
             for a and b. if either a or b is
             zero, returns zero. */
            static Integer lcm( Integer a, Integer b );
            
            /* don't give this any zeros, if you do
             it will throw a std::runtime_error. If
             you give it an empty list, returns zero.
             if you give it 1 term, it will return the
             absolute value of the term you gave it. */
            static Integer lcm( std::initializer_list<Integer> integers );
            
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
