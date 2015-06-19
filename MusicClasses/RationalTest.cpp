#include "TestHarness.h"
#include "Rational.h"

using namespace music;

TEST( Constructor01, Rational )
{
    Rational r( 1, 2 );
    CHECK_DOUBLES_EQUAL( 0.5, r.getFloat(), 0.00001 )
}
TEST( Constructor02, Rational )
{
    Rational r( -1, 10 );
    CHECK_DOUBLES_EQUAL( -0.1, r.getFloat(), 0.00001 )
}
TEST( Constructor03, Rational )
{
    Rational r( -35, -36 );
    CHECK_DOUBLES_EQUAL( 0.97222222222222, r.getFloat(), 0.00001 )
}
TEST( Constructor04, Rational )
{
    Rational r( -35, 0 );
    CHECK_DOUBLES_EQUAL( -35, r.getFloat(), 0.00001 )
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( Constructor05, Rational )
{
    Rational r;
    CHECK_DOUBLES_EQUAL( 0, r.getFloat(), 0.00001 )
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( getsetNumerator, Rational )
{
    Rational r;
    CHECK_EQUAL( 0, r.getNumerator() )
    r.setNumerator( 5 );
    CHECK_EQUAL( 5, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
TEST( getsetDenominator, Rational )
{
    Rational r;
    CHECK_EQUAL( 1, r.getDenominator() )
    r.setDenominator( 5 );
    CHECK_EQUAL( 5, r.getDenominator() )
    CHECK_EQUAL( 0, r.getNumerator() )
}
TEST( gcd01, Rational )
{
    Int a = 8;
    Int b = 12;
    Int actual = Rational::gcd( a, b );
    Int expected = 4;
    CHECK_EQUAL( expected, actual );
}

TEST( gcd02, Rational )
{
    Int a = 2;
    Int b = 1;
    Int actual = Rational::gcd( a, b );
    Int expected = 1;
    CHECK_EQUAL( expected, actual );
}
TEST( gcd03, Rational )
{
    Int a = 10397;
    Int b = 108706;
    Int actual = Rational::gcd( a, b );
    Int expected = 37;
    CHECK_EQUAL( expected, actual );
}
TEST( simplify01, Rational )
{
    Int a = 10397;
    Int b = 108706;
    Rational r{ a, b };
    auto simplified = Rational::simplify( r );
    CHECK_EQUAL( 281, simplified.getNumerator() );
    CHECK_EQUAL( 2938, simplified.getDenominator() );
}