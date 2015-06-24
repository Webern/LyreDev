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
TEST( reduce01, Rational )
{
    Int a = 10397;
    Int b = 108706;
    Rational r{ a, b };
    auto reduced = Rational::reduce( r );
    CHECK_EQUAL( 281, reduced.getNumerator() );
    CHECK_EQUAL( 2938, reduced.getDenominator() );
}
TEST( reduce02, Rational )
{
    Int a = -10397;
    Int b = -108706;
    Rational r{ a, b };
    auto reduced = Rational::reduce( r );
    CHECK_EQUAL( 281, reduced.getNumerator() );
    CHECK_EQUAL( 2938, reduced.getDenominator() );
}
TEST( lcm01, Rational )
{
    Int a = 12;
    Int b = 42;
    Int expected = 84;
    auto actual = Rational::lcm( a, b );
    CHECK_EQUAL( expected, actual )
}
TEST( lcm02, Rational )
{
    Int a = -362;
    Int b = 42;
    Int expected = 7602;
    auto actual = Rational::lcm( a, b );
    CHECK_EQUAL( expected, actual )
}
TEST( lcd01, Rational )
{
    Rational a{ 12, 42 };
    Rational b{ 1, -362 };
    Rational::lcd( a, b );
    CHECK_EQUAL( 2172, a.getNumerator() )
    CHECK_EQUAL( 7602, a.getDenominator() )
    CHECK_EQUAL( -21, b.getNumerator() )
    CHECK_EQUAL( 7602, b.getDenominator() )
    
}
TEST( lcd02, Rational )
{
    Rational a{ 1, 12 };
    Rational b{ 1, 15 };
    Rational::lcd( a, b );
    CHECK_EQUAL( 5, a.getNumerator() )
    CHECK_EQUAL( 60, a.getDenominator() )
    CHECK_EQUAL( 4, b.getNumerator() )
    CHECK_EQUAL( 60, b.getDenominator() )
}
TEST( comparisons01, Rational )
{
    Rational a{ 1, 12 };
    Rational b{ 1, 15 };
    CHECK( ! ( a == b ) )
    CHECK(   ( a != b ) )
    CHECK( ! ( a <  b ) )
    CHECK(   ( a >  b ) )
    CHECK( ! ( a <= b ) )
    CHECK(   ( a >= b ) )
}
TEST( comparisons02, Rational )
{
    Rational a{ -1, 32 };
    Rational b{ 1, 15 };
    CHECK( ! ( a == b ) )
    CHECK(   ( a != b ) )
    CHECK(   ( a <  b ) )
    CHECK( ! ( a >  b ) )
    CHECK(   ( a <= b ) )
    CHECK( ! ( a >= b ) )
}
TEST( comparisons03, Rational )
{
    Rational a{ 10, 32 };
    Rational b{ 10, 32 };
    CHECK(   ( a == b ) )
    CHECK( ! ( a != b ) )
    CHECK( ! ( a <  b ) )
    CHECK( ! ( a >  b ) )
    CHECK(   ( a <= b ) )
    CHECK(   ( a >= b ) )
}
TEST( comparisons04, Rational )
{
    Rational a{ 10, 32 };
    Rational b{ 10, 31 };
    CHECK( ! ( a == b ) )
    CHECK(   ( a != b ) )
    CHECK(   ( a <  b ) )
    CHECK( ! ( a >  b ) )
    CHECK(   ( a <= b ) )
    CHECK( ! ( a >= b ) )
}
TEST( comparisons05, Rational )
{
    Rational a{ 10, 1  };
    Rational b{ 10, 32 };
    CHECK( ! ( a == b ) )
    CHECK(   ( a != b ) )
    CHECK( ! ( a <  b ) )
    CHECK(   ( a >  b ) )
    CHECK( ! ( a <= b ) )
    CHECK(   ( a >= b ) )
}