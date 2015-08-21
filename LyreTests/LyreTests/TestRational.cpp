#include "cpulTestHarness.h"
#include "Rational.h"
#include "TypeDefs.h"

using namespace lyre::p;

TEST( Constructor01, Rational )
{
    Rational r;
	CHECK_EQUAL( 0, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( Constructor02, Rational )
{
    Rational r{ 13, 15 };
	CHECK_EQUAL( 13 , r.getNumerator() );
    CHECK_EQUAL( 15, r.getDenominator() );
}
TEST( Constructor03, Rational )
{
    Rational r{ INT_MAX, 0 };
	CHECK_EQUAL( INT_MAX , r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( Constructor04, Rational )
{
    Rational r{ -1, 0 };
	CHECK_EQUAL( -1 , r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( Constructor05, Rational )
{
    Rational r{ -100, -1000 };
	CHECK_EQUAL( -100 , r.getNumerator() );
    CHECK_EQUAL( -1000, r.getDenominator() );
}
TEST( setNumerator01, Rational )
{
    Rational r{ -100, -1000 };
    r.setNumerator( 13 );
	CHECK_EQUAL( 13 , r.getNumerator() );
    CHECK_EQUAL( -1000, r.getDenominator() );
}
TEST( setNumerator02, Rational )
{
    Rational r{ 1, 1 };
    r.setNumerator( -913 );
	CHECK_EQUAL( -913 , r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( setNumerator03, Rational )
{
    Rational r{ INT_MAX, INT_MIN };
    r.setNumerator( INT_MIN );
	CHECK_EQUAL( INT_MIN , r.getNumerator() );
    CHECK_EQUAL( INT_MIN, r.getDenominator() );
}
TEST( setDenominator01, Rational )
{
    Rational r{ INT_MAX, INT_MIN };
    r.setDenominator( INT_MAX );
	CHECK_EQUAL( INT_MAX , r.getNumerator() );
    CHECK_EQUAL( INT_MAX, r.getDenominator() );
}
TEST( setDenominator02, Rational )
{
    Rational r{ 10, 11 };
    r.setDenominator( 0 );
	CHECK_EQUAL( 10 , r.getNumerator() );
    CHECK_EQUAL( 11, r.getDenominator() );
}
TEST( setDenominator03, Rational )
{
    Rational r{ 10, 11 };
    r.setDenominator( -11 );
	CHECK_EQUAL( 10 , r.getNumerator() );
    CHECK_EQUAL( -11, r.getDenominator() );
}
TEST( gcd01, Rational )
{
    Integer a = 21;
    Integer b = 7;
    Integer expected = 7;
    Integer actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd02, Rational )
{
    Integer a = 9;
    Integer b = -3;
    Integer expected = 3;
    Integer actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd03, Rational )
{
    Integer a = 0;
    Integer b = 0;
    Integer expected = 0;
    Integer actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd04, Rational )
{
    Integer a = 0;
    Integer b = 13;
    Integer expected = 13;
    Integer actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd05, Rational )
{
    Integer a = 31;
    Integer b = 0;
    Integer expected = 31;
    Integer actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd06, Rational )
{
    Integer a = -31;
    Integer b = 0;
    Integer expected = 31;
    Integer actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd07, Rational )
{
    Integer a = 0;
    Integer b = -99;
    Integer expected = 99;
    Integer actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd08, Rational )
{
    Integer a = 96096;
    Integer b = 7148449;
    Integer expected = 77;
    Integer actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd09, Rational )
{
    Integer a = 0;
    Integer b = 0;
    Integer expected = 0;
    Integer actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd_list01, Rational )
{
    Integer expected = 77;
    Integer actual = Rational::gcd( { 96096, 7148449 } );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd_list02, Rational )
{
    Integer expected = 1;
    Integer actual = Rational::gcd( { } );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd_list03, Rational )
{
    Integer expected = 55;
    Integer actual = Rational::gcd( { 55 } );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd_list04, Rational )
{
    Integer expected = 1;
    Integer actual = Rational::gcd( { 0 } );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd_list05, Rational )
{
    Integer expected = 1;
    Integer actual = Rational::gcd( { -1 } );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd_list06, Rational )
{
    Integer expected = 102945;
    Integer actual = Rational::gcd( { -102945 } );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd_list07, Rational )
{
    Integer expected = 3;
    Integer actual = Rational::gcd( { 9, -3, 33, -99, 0 } );
    CHECK_EQUAL( expected, actual );
}
TEST( gcd_list08, Rational )
{
    std::string expected = "initializer list for gcd function may contain no more than a single 0";
    std::string actual = "no exception was thrown";
    try
    {
        Rational::gcd( { 9, -3, 33, -99, 0, 0 } );
    }
    catch ( const std::exception& e )
    {
        actual = e.what();
    }
    catch ( ... )
    {
        actual = "the wrong type of exception was caught";
    }
    CHECK_EQUAL( expected, actual )
}
TEST( lcm01, Rational )
{
    CHECK_EQUAL( 6932583, Rational::lcm( 110041, 1071 ) )
}
TEST( lcm02, Rational )
{
    CHECK_EQUAL( 10710, Rational::lcm( 10710, -1071 ) )
}
TEST( lcm03, Rational )
{
    CHECK_EQUAL( 0, Rational::lcm( 10710, 0 ) )
}
TEST( lcm04, Rational )
{
    CHECK_EQUAL( 0, Rational::lcm( 0, 10 ) )
}
TEST( lcm05, Rational )
{
    CHECK_EQUAL( 100, Rational::lcm( -100, 10 ) )
}
TEST( lcm_list01, Rational )
{
    Integer actual = Rational::lcm( { -100, 10 } );
    CHECK_EQUAL( 100, actual )
}
TEST( lcm_list02, Rational )
{
    Integer actual = Rational::lcm( { -100, 10, 5 } );
    CHECK_EQUAL( 100, actual )
}
TEST( lcm_list03, Rational )
{
    Integer actual = Rational::lcm( { -297, -231, -198, -66 } );
    CHECK_EQUAL( 4158, actual )
}
TEST( lcm_list04, Rational )
{
    Integer actual = Rational::lcm( { } );
    CHECK_EQUAL( 0, actual )
}
TEST( lcm_list05, Rational )
{
    Integer actual = Rational::lcm( { -2130 } );
    CHECK_EQUAL( 2130, actual )
}
TEST( lcm_list06, Rational )
{
    Integer actual = Rational::lcm( { 9 } );
    CHECK_EQUAL( 9, actual )
}
TEST( lcm_list07, Rational )
{
    std::string expected = "zeros not allowed";
    std::string actual = "no exception was thrown";
    try
    {
        Rational::lcm( { 9, -3, 33, -99, 0 } );
    }
    catch ( const std::exception& e )
    {
        actual = e.what();
    }
    catch ( ... )
    {
        actual = "the wrong type of exception was caught";
    }
    CHECK_EQUAL( expected, actual )
}
TEST( lcm_list08, Rational )
{
    std::string expected = "zeros not allowed";
    std::string actual = "no exception was thrown";
    try
    {
        Rational::lcm( { 0 } );
    }
    catch ( const std::exception& e )
    {
        actual = e.what();
    }
    catch ( ... )
    {
        actual = "the wrong type of exception was caught";
    }
    CHECK_EQUAL( expected, actual )
}
TEST( lcd01, Rational )
{
    Rational a{ 12, 16 };
    Rational b{ 1, 20 };
    Rational::lcd( a, b );
    Integer expectedDenominator = 20;
    Integer expectedNumeratorA = 15;
    Integer expectedNumeratorB = 1;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( 99, b.getDenominator() )
}