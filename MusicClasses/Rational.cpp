#include "Rational.h"

namespace music
{

    Rational::Rational( const Int numerator, const Int denominator )
    :myNumerator( numerator )
    ,myDenominator( denominator )
    {
        setDenominator( denominator );
    }
    
    Rational::Rational()
    :myNumerator( 0 )
    ,myDenominator( 1 )
    {}
    
    Float Rational::getFloat() const
    {
        return ((Float)myNumerator)/((Float)myDenominator);
    }
    
    void Rational::setNumerator( const Int value )
    {
        myNumerator = value;
    }
    void Rational::setDenominator( const Int value )
    {
        if ( value == 0 )
        {
            myDenominator = 1;
        }
        else
        {
            myDenominator = value;
        }
    }
    
    Int Rational::getDenominator() const
    {
        return myDenominator;
    }
    Int Rational::getNumerator() const
    {
        return myNumerator;
    }
    Int Rational::gcd( Int a, Int b )
    {
        // http://stackoverflow.com/a/4229930/2779792
        for (;;)
        {
            if ( a == 0 ) return b;
            b %= a;
            if ( b == 0 ) return a;
            a %= b;
        }
    }
    Int Rational::lcm( Int a, Int b )
    {
        // http://stackoverflow.com/a/4229930/2779792
        auto temp = gcd(a, b);
        
        return temp ? (a / temp * b) : 0;
    }
    Rational Rational::simplify( const music::Rational& input )
    {
        Int gcf = Rational::gcd( input.getNumerator(), input.getDenominator() );
        return Rational{ input.getNumerator()/gcf, input.getDenominator()/gcf };
    }
    bool operator==( const Rational& left, const Rational& right )
    {
        if ( left.getDenominator() == right.getDenominator() )
        {
            return left.getNumerator() == right.getNumerator();
        }
        else
        {
            
        }
        throw "oops";
    }
}