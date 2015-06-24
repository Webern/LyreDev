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
        
        auto answer = temp ? (a / temp * b) : 0;
        if ( answer < 0 )
        {
            answer *= -1;
        }
        return answer;
    }
    void Rational::lcd( Rational& a, Rational& b )
    {
        if ( a.getDenominator() == b.getDenominator() )
        {
            return;
        }
        else
        {
            auto lcm = Rational::lcm( a.getDenominator(), b.getDenominator() );
            auto a_fact = lcm / a.getDenominator();
            auto b_fact = lcm / b.getDenominator();
            a.setNumerator( a.getNumerator() * a_fact );
            a.setDenominator( lcm );
            b.setNumerator( b.getNumerator() * b_fact );
            b.setDenominator( lcm );
            return;
        }
    }
    Rational Rational::reduce( const music::Rational& r )
    {
        
        Int gcf = Rational::gcd( r.getNumerator(), r.getDenominator() );
        Rational temp{ r.getNumerator()/gcf, r.getDenominator()/gcf };
        if ( temp.getNumerator() < 0 && temp.getDenominator() < 0 )
        {
            temp.setNumerator( ( -1 * temp.getNumerator() ) );
            temp.setDenominator( ( -1 * temp.getDenominator() ) );
        }
        return temp;
    }
    bool operator==( const Rational& left, const Rational& right )
    {
        if ( left.getDenominator() == right.getDenominator() )
        {
            return left.getNumerator() == right.getNumerator();
        }
        else
        {
            auto copy_left = left;
            auto copy_right = right;
            Rational::lcd( copy_left, copy_right );
            return copy_left == copy_right;
        }
    }
    bool operator!=( const Rational& left, const Rational& right )
    {
        return ! ( left == right );
    }
    bool operator<( const Rational& left, const Rational& right )
    {
        if ( left.getDenominator() == right.getDenominator() )
        {
            return left.getNumerator() < right.getNumerator();
        }
        else
        {
            auto copy_left = left;
            auto copy_right = right;
            Rational::lcd( copy_left, copy_right );
            return copy_left < copy_right;
        }
    }
    bool operator>( const Rational& left, const Rational& right )
    {
        return right < left;
    }
    bool operator<=( const Rational& left, const Rational& right )
    {
        return ( left < right ) || ( left == right );
    }
    bool operator>=( const Rational& left, const Rational& right )
    {
        return ( right < left ) || ( left == right );
    }
    std::ostream& operator<<( std::ostream& os, const Rational& right )
    {
        return os << "( " << right.getNumerator() << " / " << right.getDenominator() << " )";
    }
    Rational Rational::getReciprocal() const
    {
        return Rational{ getDenominator(), getNumerator() };
    }
    
    Rational& Rational::operator*=( const Rational& right )
    {
        auto result = *this * right;
        *this = result;
        return *this;
    }
    Rational operator/( const Rational& r, const Rational& l )
    {
        auto l_recip = l.getReciprocal();
        auto value = r * l_recip;
        value = Rational::reduce( value );
        return value;
    }
    Rational operator*( const Rational& r, const Rational& l )
    {
        return Rational::reduce( Rational{ r.getNumerator() * l.getNumerator(), r.getDenominator() * l.getDenominator() } );
    }
}