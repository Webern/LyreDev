//PUBLIC
#pragma once
#include <iostream>
#include "Lyre/Lyre.h"
#include <vector>

/* I need rational numbers for music and I don't
 want to include boost.  This would be a good
 candidate for template generalization, but I
 don't anticipate needing it for anything other
 than int. */

namespace Lyre
{
    class Rational;
    using Rationals = std::vector<Rational>;
    using RationalsIter = Rationals::iterator;
    using RationalsIterConst = Rationals::const_iterator;
    
    class PUBLIC Rational
    {
    public:
        /* Default constructor sets value to 0/1.
         If you use the value constructor and try
         to set the denominator to 0, the denominator
         will be set to 1 instead. */
        Rational();
        Rational( const int numerator, const int denominator );
        
        /* return the decimal approximation of the rational
         number as a calculator would. i.e. 1/3 -> 0.33333... */
        Float getFloat() const;
        
        int getNumerator() const;
        void setNumerator( const int value );
        
        /* Denominator cannot be zero,
         attempting to set the denominator
         to zero is a no-op. */
        int getDenominator() const;
        void setDenominator( const int value );
        
        /* change the fraction to the smallest
         possible denominator.  if both numerator
         and denominator are negative, they
         replace both with positive numbers.
         if numerator is positive and denominator
         is negative, switch these so the numer-
         ator is negative and denominator is pos-
         itive. return true if 'this' was changed
         return false if 'this' was already red-
         uced */
        bool reduce();
        
        /* flip the fraction, numerator
         becomes denominator and vice
         versa. if numerator is zero
         then no-op */
        void reciprocal();
        
        /* returns true/false if the fraction
         represents a number less/greater than zero */
        bool getIsNegative() const;
        bool getIsPositive() const;
        
        /* if the fraction were written as a mixed
         number (i.e.  1 1/2 instead of 3/2), get
         the whole number part (i.e. 1) and the
         fractional part (i.e. 1/2) */
        int getMixedWholePart() const;
        Rational getMixedFractionalPart() const;
        
        /* returns true of both numerators are equal
         and both denominators are equal.  Note this
         is different than the behavior of == */
        bool getIsIdenticalTo( const Rational& other ) const;
        
        /* These will automatically reduce
         the fraction after the mathematical
         operation.  Note attempting to div-
         ide by zero (i.e. 0/x) is a no-op */
        Rational& operator/=( const Rational& right );
        Rational& operator*=( const Rational& right );
        Rational& operator+=( const Rational& right );
        Rational& operator-=( const Rational& right );
        
        /* return the greatest common divisor
         for a and b.  if both a and b are zero,
         gcd returns zero. if a OR b is zero, the
         absolute value of the non-zero term is
         returned */
        static int gcd( int a, int b );
        
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
        static int gcd( std::initializer_list<int> integers );
        
        /* return the least common multiple
         for a and b. if either a or b is
         zero, returns zero. */
        static int lcm( int a, int b );
        
        /* don't give this any zeros, if you do
         it will throw a std::runtime_error. If
         you give it an empty list, returns zero.
         if you give it 1 term, it will return the
         absolute value of the term you gave it. */
        static int lcm( std::initializer_list<int> integers );
        static int lcm( const ints& integers );
        
        /* convert a and b so that they have
         the same (least common) denominator.
         when firstReduce is true, the funtion
         will reduce a and b before finding
         the common denominator */
        static void lcd( Rational& a, Rational& b, const bool firstReduce = true );
        
        /* convert each fraction to have the
         lowest common denominator.  When
         firstReduce is true, each fraction
         will first be sPrivateified to its
         lowest possible positve denominator
         before finding the lowest commond
         denominator. */
        static void lcd( Rationals& rationals, const bool firstReduce = true );
        
    private:
        int myNumerator;
        int myDenominator;
    };
    
    /* Comparisons in the mathematical sense, i.e. 1/3 == 4/12,
     to see if to fractions are identical use left.getIsIdenticalTo( right ) */
	PUBLIC bool operator==( const Rational& left, const Rational& right );
	PUBLIC bool operator!=( const Rational& left, const Rational& right );
	PUBLIC bool operator<( const Rational& left, const Rational& right );
	PUBLIC bool operator>( const Rational& left, const Rational& right );
	PUBLIC bool operator<=( const Rational& left, const Rational& right );
	PUBLIC bool operator>=( const Rational& left, const Rational& right );
    
    /* divide by zero (i.e. 0/x) returns 0/1 (i.e. instead of throwing) */
	PUBLIC Rational operator/( const Rational& r, const Rational& l );
	PUBLIC Rational operator*( const Rational& r, const Rational& l );
	PUBLIC Rational operator+( const Rational& r, const Rational& l );
	PUBLIC Rational operator-( const Rational& r, const Rational& l );
    
    /* stream a textual representation of the Rational number */
    PUBLIC std::ostream& operator<<( std::ostream& os, const Rational& right );    
}
