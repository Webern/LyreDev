//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Rational.h"
#include "Lyre/Lyre.h"

using namespace Lyre;

TEST( Constructor01, Rational )
{
    Rational r;
	CHECK_EQUAL( 0, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
T_END

TEST( Constructor02, Rational )
{
    Rational r{ 13, 15 };
	CHECK_EQUAL( 13 , r.getNumerator() );
    CHECK_EQUAL( 15, r.getDenominator() );
}
T_END

TEST( Constructor03, Rational )
{
    Rational r{ INT_MAX, 0 };
	CHECK_EQUAL( INT_MAX , r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
T_END

TEST( Constructor04, Rational )
{
    Rational r{ -1, 0 };
	CHECK_EQUAL( -1 , r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
T_END

TEST( Constructor05, Rational )
{
    Rational r{ -100, -1000 };
	CHECK_EQUAL( -100 , r.getNumerator() );
    CHECK_EQUAL( -1000, r.getDenominator() );
}
T_END

TEST( setNumerator01, Rational )
{
    Rational r{ -100, -1000 };
    r.setNumerator( 13 );
	CHECK_EQUAL( 13 , r.getNumerator() );
    CHECK_EQUAL( -1000, r.getDenominator() );
}
T_END

TEST( setNumerator02, Rational )
{
    Rational r{ 1, 1 };
    r.setNumerator( -913 );
	CHECK_EQUAL( -913 , r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
T_END

TEST( setNumerator03, Rational )
{
    Rational r{ INT_MAX, INT_MIN };
    r.setNumerator( INT_MIN );
	CHECK_EQUAL( INT_MIN , r.getNumerator() );
    CHECK_EQUAL( INT_MIN, r.getDenominator() );
}
T_END

TEST( setDenominator01, Rational )
{
    Rational r{ INT_MAX, INT_MIN };
    r.setDenominator( INT_MAX );
	CHECK_EQUAL( INT_MAX , r.getNumerator() );
    CHECK_EQUAL( INT_MAX, r.getDenominator() );
}
T_END

TEST( setDenominator02, Rational )
{
    Rational r{ 10, 11 };
    r.setDenominator( 0 );
	CHECK_EQUAL( 10 , r.getNumerator() );
    CHECK_EQUAL( 11, r.getDenominator() );
}
T_END

TEST( setDenominator03, Rational )
{
    Rational r{ 10, 11 };
    r.setDenominator( -11 );
	CHECK_EQUAL( 10 , r.getNumerator() );
    CHECK_EQUAL( -11, r.getDenominator() );
}
T_END

TEST( gcd01, Rational )
{
    int a = 21;
    int b = 7;
    int expected = 7;
    int actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd02, Rational )
{
    int a = 9;
    int b = -3;
    int expected = 3;
    int actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd03, Rational )
{
    int a = 0;
    int b = 0;
    int expected = 0;
    int actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd04, Rational )
{
    int a = 0;
    int b = 13;
    int expected = 13;
    int actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd05, Rational )
{
    int a = 31;
    int b = 0;
    int expected = 31;
    int actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd06, Rational )
{
    int a = -31;
    int b = 0;
    int expected = 31;
    int actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd07, Rational )
{
    int a = 0;
    int b = -99;
    int expected = 99;
    int actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd08, Rational )
{
    int a = 96096;
    int b = 7148449;
    int expected = 77;
    int actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd09, Rational )
{
    int a = 0;
    int b = 0;
    int expected = 0;
    int actual = Rational::gcd( a, b );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd_list01, Rational )
{
    int expected = 77;
    int actual = Rational::gcd( { 96096, 7148449 } );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd_list02, Rational )
{
    int expected = 1;
    int actual = Rational::gcd( { } );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd_list03, Rational )
{
    int expected = 55;
    int actual = Rational::gcd( { 55 } );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd_list04, Rational )
{
    int expected = 1;
    int actual = Rational::gcd( { 0 } );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd_list05, Rational )
{
    int expected = 1;
    int actual = Rational::gcd( { -1 } );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd_list06, Rational )
{
    int expected = 102945;
    int actual = Rational::gcd( { -102945 } );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd_list07, Rational )
{
    int expected = 3;
    int actual = Rational::gcd( { 9, -3, 33, -99, 0 } );
    CHECK_EQUAL( expected, actual );
}
T_END

TEST( gcd_list08, Rational )
{
    String expected = "initializer list for gcd function may contain no more than a single 0";
    String actual = "no exception was thrown";
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
    auto foundPosition = actual.find( expected );
    bool success = ( foundPosition != String::npos );
    CHECK( success )
}
T_END

TEST( lcm01, Rational )
{
    CHECK_EQUAL( 6932583, Rational::lcm( 110041, 1071 ) )
}
T_END

TEST( lcm02, Rational )
{
    CHECK_EQUAL( 10710, Rational::lcm( 10710, -1071 ) )
}
T_END

TEST( lcm03, Rational )
{
    CHECK_EQUAL( 0, Rational::lcm( 10710, 0 ) )
}
T_END

TEST( lcm04, Rational )
{
    CHECK_EQUAL( 0, Rational::lcm( 0, 10 ) )
}
T_END

TEST( lcm05, Rational )
{
    CHECK_EQUAL( 100, Rational::lcm( -100, 10 ) )
}
T_END

TEST( lcm_list01, Rational )
{
    int actual = Rational::lcm( { -100, 10 } );
    CHECK_EQUAL( 100, actual )
}
T_END

TEST( lcm_list02, Rational )
{
    int actual = Rational::lcm( { -100, 10, 5 } );
    CHECK_EQUAL( 100, actual )
}
T_END

TEST( lcm_list03, Rational )
{
    int actual = Rational::lcm( { -297, -231, -198, -66 } );
    CHECK_EQUAL( 4158, actual )
}
T_END

TEST( lcm_list04, Rational )
{
    std::initializer_list<int> integers;
    int actual = Rational::lcm( integers );
    CHECK_EQUAL( 0, actual )
}
T_END

TEST( lcm_list05, Rational )
{
    int actual = Rational::lcm( { -2130 } );
    CHECK_EQUAL( 2130, actual )
}
T_END

TEST( lcm_list06, Rational )
{
    int actual = Rational::lcm( { 9 } );
    CHECK_EQUAL( 9, actual )
}
T_END

TEST( lcm_list07, Rational )
{
    String expected = "zeros not allowed";
    String actual = "no exception was thrown";
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
    auto foundPosition = actual.find( expected );
    bool success = ( foundPosition != String::npos );
    CHECK( success )
}
T_END

TEST( lcm_list08, Rational )
{
    String expected = "zeros not allowed";
    String actual = "no exception was thrown";
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
    auto foundPosition = actual.find( expected );
    bool success = ( foundPosition != String::npos );
    CHECK( success )
}
T_END

TEST( lcm_vec01, Rational )
{
    ints vec = { -100, 10 };
    int actual = Rational::lcm( vec );
    CHECK_EQUAL( 100, actual )
}
T_END

TEST( lcm_vec02, Rational )
{
    ints vec = { -100, 10, 5 };
    int actual = Rational::lcm( vec );
    CHECK_EQUAL( 100, actual )
}
T_END

TEST( lcm_vec03, Rational )
{
    ints vec = { -297, -231, -198, -66 };
    int actual = Rational::lcm( vec );
    CHECK_EQUAL( 4158, actual )
}
T_END

TEST( lcm_vec04, Rational )
{
    ints vec;
    int actual = Rational::lcm( vec );
    CHECK_EQUAL( 0, actual )
}
T_END

TEST( lcm_vec05, Rational )
{
    ints vec = { -2130 };
    int actual = Rational::lcm( vec );
    CHECK_EQUAL( 2130, actual )
}
T_END

TEST( lcm_vec06, Rational )
{
    ints vec = { 9 };
    int actual = Rational::lcm( vec );
    CHECK_EQUAL( 9, actual )
}
T_END

TEST( lcm_vec07, Rational )
{
    ints vec = { 9, -3, 33, -99, 0 };
    String expected = "zeros not allowed";
    String actual = "no exception was thrown";
    try
    {
        Rational::lcm( vec );
    }
    catch ( const std::exception& e )
    {
        actual = e.what();
    }
    catch ( ... )
    {
        actual = "the wrong type of exception was caught";
    }
    auto foundPosition = actual.find( expected );
    bool success = ( foundPosition != String::npos );
    CHECK( success )
}
T_END

TEST( lcm_vec08, Rational )
{
    ints vec = { 0 };
    String expected = "zeros not allowed";
    String actual = "no exception was thrown";
    try
    {
        Rational::lcm( vec );
    }
    catch ( const std::exception& e )
    {
        actual = e.what();
    }
    catch ( ... )
    {
        actual = "the wrong type of exception was caught";
    }
    auto foundPosition = actual.find( expected );
    bool success = ( foundPosition != String::npos );
    CHECK( success )
}
T_END

TEST( lcd01, Rational )
{
    Rational a{ 2, 4 };
    Rational b{ 1, 2 };
    Rational::lcd( a, b );
    int expectedDenominator = 2;
    int expectedNumeratorA = 1;
    int expectedNumeratorB = 1;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
T_END

TEST( lcd02, Rational )
{
    Rational a{ 3, 12 };
    Rational b{ 6, 48 };
    Rational::lcd( a, b );
    //std::cout << a << " " << b << std::endl;
    int expectedDenominator = 8;
    int expectedNumeratorA = 2;
    int expectedNumeratorB = 1;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
T_END

TEST( lcd03, Rational )
{
    Rational a{ 12, 16 };
    Rational b{ 1, 20 };
    Rational::lcd( a, b );
    //std::cout << a << " " << b << std::endl;
    int expectedDenominator = 20;
    int expectedNumeratorA = 15;
    int expectedNumeratorB = 1;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
T_END

TEST( lcd04, Rational )
{
    Rational a{ 7, 1582 };
    Rational b{ 654, 12769 };
    Rational::lcd( a, b );
    //std::cout << a << " " << b << std::endl;
    int expectedDenominator = 25538;
    int expectedNumeratorA = 113;
    int expectedNumeratorB = 1308;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
T_END

TEST( lcd05, Rational )
{
    Rational a{ 0, 10 };
    Rational b{ 11, -15 };
    Rational::lcd( a, b );
    //std::cout << a << " " << b << std::endl;
    int expectedDenominator = 15;
    int expectedNumeratorA = 0;
    int expectedNumeratorB = -11;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
T_END

TEST( lcd06, Rational )
{
    Rational a{ 1, -5 };
    Rational b{ -11, -15 };
    Rational::lcd( a, b );
    // std::cout << a << " " << b << std::endl;
    int expectedDenominator = 15;
    int expectedNumeratorA = -3;
    int expectedNumeratorB = 11;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
T_END

TEST( lcd07, Rational )
{
    Rational a{ 3, 12 };
    Rational b{ 6, 48 };
    Rational::lcd( a, b, false );
    //std::cout << a << " " << b << std::endl;
    int expectedDenominator = 48;
    int expectedNumeratorA = 12;
    int expectedNumeratorB = 6;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
T_END

TEST( lcd08, Rational )
{
    Rational a{ 12, 16 };
    Rational b{ 1, 20 };
    Rational::lcd( a, b, false );
    //std::cout << a << " " << b << std::endl;
    int expectedDenominator = 80;
    int expectedNumeratorA = 60;
    int expectedNumeratorB = 4;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
T_END

TEST( lcd09, Rational )
{
    Rational a{ 7, 1582 };
    Rational b{ 654, 12769 };
    Rational::lcd( a, b, false );
    //std::cout << a << " " << b << std::endl;
    int expectedDenominator = 178766;
    int expectedNumeratorA = 791;
    int expectedNumeratorB = 9156;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
T_END

TEST( lcd10, Rational )
{
    Rational a{ 0, 10 };
    Rational b{ 11, -15 };
    Rational::lcd( a, b, false );
    //std::cout << a << " " << b << std::endl;
    int expectedDenominator = 30;
    int expectedNumeratorA = 0;
    int expectedNumeratorB = -22;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
T_END

TEST( lcd11, Rational )
{
    Rational a{ 1, -5 };
    Rational b{ -11, -15 };
    Rational::lcd( a, b, false );
    // std::cout << a << " " << b << std::endl;
    int expectedDenominator = 15;
    int expectedNumeratorA = -3;
    int expectedNumeratorB = 11;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
T_END

TEST( lcdList01, Rational )
{
    Rationals rats;
    Rational::lcd( rats );
    CHECK_EQUAL( 0, rats.size() );
    
}
T_END

TEST( lcdList02, Rational )
{
    Rationals rats;
    rats.push_back( Rational{ 6, 4 } );
    Rational::lcd( rats );
    CHECK_EQUAL( 1, rats.size() )
    CHECK_EQUAL( 3, rats.cbegin()->getNumerator() )
    CHECK_EQUAL( 2, rats.cbegin()->getDenominator() )
    
}
T_END

TEST( lcdList03, Rational )
{
    Rationals rats;
    rats.push_back( Rational{ 6, 4 } );
    rats.push_back( Rational{ 7, 9 } );
    rats.push_back( Rational{ 1, 10 } );
    Rational::lcd( rats );
    CHECK_EQUAL( 3, rats.size() )
    auto r = rats.cbegin();
    int denom = 90;
    CHECK_EQUAL( 135, r->getNumerator() )
    CHECK_EQUAL( denom, r->getDenominator() )
    ++r;
    CHECK_EQUAL( 70, r->getNumerator() )
    CHECK_EQUAL( denom, r->getDenominator() )
    ++r;
    CHECK_EQUAL( 9, r->getNumerator() )
    CHECK_EQUAL( denom, r->getDenominator() )
    ++r;
    CHECK( r == rats.cend() )
}
T_END

TEST( lcdList04, Rational )
{
    Rationals rats;
    rats.push_back( Rational{ 17, -18 } );
    rats.push_back( Rational{ -71, 9 } );
    rats.push_back( Rational{ -1, -10 } );
    Rational::lcd( rats );
    CHECK_EQUAL( 3, rats.size() )
    auto r = rats.cbegin();
    int denom = 90;
    CHECK_EQUAL( -85, r->getNumerator() )
    CHECK_EQUAL( denom, r->getDenominator() )
    ++r;
    CHECK_EQUAL( -710, r->getNumerator() )
    CHECK_EQUAL( denom, r->getDenominator() )
    ++r;
    CHECK_EQUAL( 9, r->getNumerator() )
    CHECK_EQUAL( denom, r->getDenominator() )
    ++r;
    CHECK( r == rats.cend() )
}
T_END

TEST( lcdList01noReduce, Rational )
{
    Rationals rats;
    rats.push_back( Rational{ 6, 4 } );
    Rational::lcd( rats, false );
    CHECK_EQUAL( 1, rats.size() )
    CHECK_EQUAL( 6, rats.cbegin()->getNumerator() )
    CHECK_EQUAL( 4, rats.cbegin()->getDenominator() )
    
}
T_END

TEST( lcdList02noReduce, Rational )
{
    Rationals rats;
    rats.push_back( Rational{ 6, 4 } );
    rats.push_back( Rational{ 7, 9 } );
    rats.push_back( Rational{ 1, 10 } );
    Rational::lcd( rats, false );
    CHECK_EQUAL( 3, rats.size() )
    auto r = rats.cbegin();
    int denom = 180;
    CHECK_EQUAL( 270, r->getNumerator() )
    CHECK_EQUAL( denom, r->getDenominator() )
    ++r;
    CHECK_EQUAL( 140, r->getNumerator() )
    CHECK_EQUAL( denom, r->getDenominator() )
    ++r;
    CHECK_EQUAL( 18, r->getNumerator() )
    CHECK_EQUAL( denom, r->getDenominator() )
    ++r;
    CHECK( r == rats.cend() )
}
T_END

TEST( lcdList03noReduce, Rational )
{
    Rationals rats;
    rats.push_back( Rational{ 17, -18 } );
    rats.push_back( Rational{ -71, 9 } );
    rats.push_back( Rational{ -1, -10 } );
    Rational::lcd( rats, false );
    CHECK_EQUAL( 3, rats.size() )
    auto r = rats.cbegin();
    int denom = 90;
    CHECK_EQUAL( -85, r->getNumerator() )
    CHECK_EQUAL( denom, r->getDenominator() )
    ++r;
    CHECK_EQUAL( -710, r->getNumerator() )
    CHECK_EQUAL( denom, r->getDenominator() )
    ++r;
    CHECK_EQUAL( 9, r->getNumerator() )
    CHECK_EQUAL( denom, r->getDenominator() )
    ++r;
    CHECK( r == rats.cend() )
}
T_END

TEST( reduce01, Rational )
{
    Rational r{ 0, 10 };
    bool changed = r.reduce();
    CHECK( changed )
    CHECK_EQUAL( 0, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
T_END

TEST( reduce02, Rational )
{
    Rational r{ 99, -99 };
    bool changed = r.reduce();
    CHECK( changed )
    CHECK_EQUAL( -1, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
T_END

TEST( reduce03, Rational )
{
    Rational r{ -200, -100 };
    bool changed = r.reduce();
    CHECK( changed )
    CHECK_EQUAL( 2, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
T_END

TEST( reduce04, Rational )
{
    Rational r{ 5, 15 };
    bool changed = r.reduce();
    CHECK( changed )
    CHECK_EQUAL( 1, r.getNumerator() )
    CHECK_EQUAL( 3, r.getDenominator() )
}
T_END

TEST( reduce05, Rational )
{
    Rational r{ 0, -115 };
    bool changed = r.reduce();
    CHECK( changed )
    CHECK_EQUAL( 0, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
T_END

TEST( reduce06, Rational )
{
    Rational r{ -3, -250377 };
    bool changed = r.reduce();
    CHECK( changed )
    CHECK_EQUAL( 1, r.getNumerator() )
    CHECK_EQUAL( 83459, r.getDenominator() )
}
T_END

TEST( reciprocal01, Rational )
{
    Rational r;
    r.reciprocal();
    CHECK_EQUAL( 0, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
T_END

TEST( reciprocal02, Rational )
{
    Rational r{ 0, 99 };
    r.reciprocal();
    CHECK_EQUAL( 0, r.getNumerator() )
    CHECK_EQUAL( 99, r.getDenominator() )
}
T_END

TEST( reciprocal03, Rational )
{
    Rational r{ 1, 3 };
    r.reciprocal();
    CHECK_EQUAL( 3, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
T_END

TEST( reciprocal04, Rational )
{
    Rational r{ 31, -93 };
    r.reciprocal();
    CHECK_EQUAL( -93, r.getNumerator() )
    CHECK_EQUAL( 31, r.getDenominator() )
}
T_END

TEST( reciprocal05, Rational )
{
    Rational r{ -19348, 8488302 };
    r.reciprocal();
    CHECK_EQUAL( 8488302, r.getNumerator() )
    CHECK_EQUAL( -19348, r.getDenominator() )
}
T_END

TEST( reciprocal06, Rational )
{
    Rational r{ -9, -7 };
    r.reciprocal();
    CHECK_EQUAL( -7, r.getNumerator() )
    CHECK_EQUAL( -9, r.getDenominator() )
}
T_END

TEST( divideisEqualTo01, Rational )
{
    int aNumer = -9;
    int aDenom = -7;
    int bNumer = 10;
    int bDenom = 11;
    int resultNumer = 99;
    int resultDenom = 70;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a /= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divideisEqualTo02, Rational )
{
    int aNumer = 234;
    int aDenom = 123;
    int bNumer = 345;
    int bDenom = 756;
    int resultNumer = 19656;
    int resultDenom = 4715;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a /= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divideisEqualTo03, Rational )
{
    int aNumer = -4576;
    int aDenom = 3478;
    int bNumer = -3478;
    int bDenom = 4578;
    int resultNumer = 5237232;
    int resultDenom = 3024121;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a /= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divideisEqualTo04, Rational )
{
    int aNumer = 9405;
    int aDenom = -9470;
    int bNumer = 3789;
    int bDenom = -9483;
    int resultNumer = 1981947;
    int resultDenom = 797374;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a /= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divideisEqualTo05, Rational )
{
    int aNumer = 5;
    int aDenom = 6;
    int bNumer = -37;
    int bDenom = -72;
    int resultNumer = 60;
    int resultDenom = 37;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a /= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divideisEqualTo06, Rational )
{
    int aNumer = 51;
    int aDenom = 26;
    int bNumer = -3;
    int bDenom = 7;
    int resultNumer = -119;
    int resultDenom = 26;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a /= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divideisEqualTo07, Rational )
{
    int aNumer = 82;
    int aDenom = 91;
    int bNumer = 10;
    int bDenom = -11;
    int resultNumer = -451;
    int resultDenom = 455;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a /= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divideisEqualTo08, Rational )
{
    int aNumer = 0;
    int aDenom = 26;
    int bNumer = 3;
    int bDenom = -7;
    int resultNumer = 0;
    int resultDenom = 1;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a /= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divideisEqualTo09, Rational )
{
    int aNumer = 15;
    int aDenom = 26;
    int bNumer = 0;
    int bDenom = -7;
    int resultNumer = 15;
    int resultDenom = 26;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a /= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( timesisEqualTo01, Rational )
{
    int aNumer = -9;
    int aDenom = -7;
    int bNumer = 10;
    int bDenom = 11;
    int resultNumer = 90;
    int resultDenom = 77;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a *= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( timesisEqualTo02, Rational )
{
    int aNumer = 234;
    int aDenom = 123;
    int bNumer = 345;
    int bDenom = 756;
    int resultNumer = 1495;
    int resultDenom = 1722;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a *= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( timesisEqualTo03, Rational )
{
    int aNumer = -4576;
    int aDenom = 3478;
    int bNumer = -3478;
    int bDenom = 4578;
    int resultNumer = 2288;
    int resultDenom = 2289;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a *= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( timesisEqualTo04, Rational )
{
    int aNumer = 9405;
    int aDenom = -9470;
    int bNumer = 3789;
    int bDenom = -9483;
    int resultNumer = 2375703;
    int resultDenom = 5986934;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a *= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( timesisEqualTo05, Rational )
{
    int aNumer = 5;
    int aDenom = 6;
    int bNumer = -37;
    int bDenom = -72;
    int resultNumer = 185;
    int resultDenom = 432;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a *= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( timesisEqualTo06, Rational )
{
    int aNumer = 51;
    int aDenom = 26;
    int bNumer = -3;
    int bDenom = 7;
    int resultNumer = -153;
    int resultDenom = 182;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a *= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( timesisEqualTo07, Rational )
{
    int aNumer = 82;
    int aDenom = 91;
    int bNumer = 10;
    int bDenom = -11;
    int resultNumer = -820;
    int resultDenom = 1001;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a *= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( timesisEqualTo08, Rational )
{
    int aNumer = 0;
    int aDenom = 26;
    int bNumer = 3;
    int bDenom = -7;
    int resultNumer = 0;
    int resultDenom = 1;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a *= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( timesisEqualTo09, Rational )
{
    int aNumer = 15;
    int aDenom = 26;
    int bNumer = 0;
    int bDenom = -7;
    int resultNumer = 0;
    int resultDenom = 1;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a *= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plusisEqualTo01, Rational )
{
    int aNumer = -9;
    int aDenom = -7;
    int bNumer = 10;
    int bDenom = 11;
    int resultNumer = 169;
    int resultDenom = 77;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a += b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plusisEqualTo02, Rational )
{
    int aNumer = 234;
    int aDenom = 123;
    int bNumer = 345;
    int bDenom = 756;
    int resultNumer = 24371;
    int resultDenom = 10332;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a += b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plusisEqualTo03, Rational )
{
    int aNumer = -4576;
    int aDenom = 3478;
    int bNumer = -3478;
    int bDenom = 4578;
    int resultNumer = -8261353;
    int resultDenom = 3980571;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a += b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plusisEqualTo04, Rational )
{
    int aNumer = 9405;
    int aDenom = -9470;
    int bNumer = 3789;
    int bDenom = -9483;
    int resultNumer = -8337963;
    int resultDenom = 5986934;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a += b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plusisEqualTo05, Rational )
{
    int aNumer = 5;
    int aDenom = 6;
    int bNumer = -37;
    int bDenom = -72;
    int resultNumer = 97;
    int resultDenom = 72;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a += b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plusisEqualTo06, Rational )
{
    int aNumer = 51;
    int aDenom = 26;
    int bNumer = -3;
    int bDenom = 7;
    int resultNumer = 279;
    int resultDenom = 182;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a += b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plusisEqualTo07, Rational )
{
    int aNumer = 82;
    int aDenom = 91;
    int bNumer = 10;
    int bDenom = -11;
    int resultNumer = -8;
    int resultDenom = 1001;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a += b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plusisEqualTo08, Rational )
{
    int aNumer = 0;
    int aDenom = 26;
    int bNumer = 3;
    int bDenom = -7;
    int resultNumer = -3;
    int resultDenom = 7;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a += b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plusisEqualTo09, Rational )
{
    int aNumer = 15;
    int aDenom = 26;
    int bNumer = 0;
    int bDenom = -7;
    int resultNumer = 15;
    int resultDenom = 26;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a += b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minusisEqualTo01, Rational )
{
    int aNumer = -9;
    int aDenom = -7;
    int bNumer = 10;
    int bDenom = 11;
    int resultNumer = 29;
    int resultDenom = 77;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a -= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minusisEqualTo02, Rational )
{
    int aNumer = 234;
    int aDenom = 123;
    int bNumer = 345;
    int bDenom = 756;
    int resultNumer = 14941;
    int resultDenom = 10332;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a -= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minusisEqualTo03, Rational )
{
    int aNumer = -4576;
    int aDenom = 3478;
    int bNumer = -3478;
    int bDenom = 4578;
    int resultNumer = -2213111;
    int resultDenom = 3980571;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a -= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minusisEqualTo04, Rational )
{
    int aNumer = 9405;
    int aDenom = -9470;
    int bNumer = 3789;
    int bDenom = -9483;
    int resultNumer = -3553719;
    int resultDenom = 5986934;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a -= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minusisEqualTo05, Rational )
{
    int aNumer = 5;
    int aDenom = 6;
    int bNumer = -37;
    int bDenom = -72;
    int resultNumer = 23;
    int resultDenom = 72;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a -= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minusisEqualTo06, Rational )
{
    int aNumer = 51;
    int aDenom = 26;
    int bNumer = -3;
    int bDenom = 7;
    int resultNumer = 435;
    int resultDenom = 182;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a -= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minusisEqualTo07, Rational )
{
    int aNumer = 82;
    int aDenom = 91;
    int bNumer = 10;
    int bDenom = -11;
    int resultNumer = 1812;
    int resultDenom = 1001;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a -= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minusisEqualTo08, Rational )
{
    int aNumer = 0;
    int aDenom = 26;
    int bNumer = 3;
    int bDenom = -7;
    int resultNumer = 3;
    int resultDenom = 7;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a -= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minusisEqualTo09, Rational )
{
    int aNumer = 15;
    int aDenom = 26;
    int bNumer = 0;
    int bDenom = -7;
    int resultNumer = 15;
    int resultDenom = 26;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a -= b;
    CHECK_EQUAL( resultNumer, a.getNumerator() )
    CHECK_EQUAL( resultDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END





/*****************************/

TEST( divide01, Rational )
{
    int aNumer = -9;
    int aDenom = -7;
    int bNumer = 10;
    int bDenom = 11;
    int resultNumer = 99;
    int resultDenom = 70;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a / b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divide02, Rational )
{
    int aNumer = 234;
    int aDenom = 123;
    int bNumer = 345;
    int bDenom = 756;
    int resultNumer = 19656;
    int resultDenom = 4715;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a / b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divide03, Rational )
{
    int aNumer = -4576;
    int aDenom = 3478;
    int bNumer = -3478;
    int bDenom = 4578;
    int resultNumer = 5237232;
    int resultDenom = 3024121;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a / b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divide04, Rational )
{
    int aNumer = 9405;
    int aDenom = -9470;
    int bNumer = 3789;
    int bDenom = -9483;
    int resultNumer = 1981947;
    int resultDenom = 797374;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a / b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divide05, Rational )
{
    int aNumer = 5;
    int aDenom = 6;
    int bNumer = -37;
    int bDenom = -72;
    int resultNumer = 60;
    int resultDenom = 37;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a / b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divide06, Rational )
{
    int aNumer = 51;
    int aDenom = 26;
    int bNumer = -3;
    int bDenom = 7;
    int resultNumer = -119;
    int resultDenom = 26;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a / b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divide07, Rational )
{
    int aNumer = 82;
    int aDenom = 91;
    int bNumer = 10;
    int bDenom = -11;
    int resultNumer = -451;
    int resultDenom = 455;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a / b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divide08, Rational )
{
    int aNumer = 0;
    int aDenom = 26;
    int bNumer = 3;
    int bDenom = -7;
    int resultNumer = 0;
    int resultDenom = 1;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a / b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( divide09, Rational )
{
    int aNumer = 15;
    int aDenom = 26;
    int bNumer = 0;
    int bDenom = -7;
    int resultNumer = 0;
    int resultDenom = 1;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a / b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( times01, Rational )
{
    int aNumer = -9;
    int aDenom = -7;
    int bNumer = 10;
    int bDenom = 11;
    int resultNumer = 90;
    int resultDenom = 77;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a * b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( times02, Rational )
{
    int aNumer = 234;
    int aDenom = 123;
    int bNumer = 345;
    int bDenom = 756;
    int resultNumer = 1495;
    int resultDenom = 1722;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a * b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( times03, Rational )
{
    int aNumer = -4576;
    int aDenom = 3478;
    int bNumer = -3478;
    int bDenom = 4578;
    int resultNumer = 2288;
    int resultDenom = 2289;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a * b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( times04, Rational )
{
    int aNumer = 9405;
    int aDenom = -9470;
    int bNumer = 3789;
    int bDenom = -9483;
    int resultNumer = 2375703;
    int resultDenom = 5986934;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a * b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( times05, Rational )
{
    int aNumer = 5;
    int aDenom = 6;
    int bNumer = -37;
    int bDenom = -72;
    int resultNumer = 185;
    int resultDenom = 432;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a * b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( times06, Rational )
{
    int aNumer = 51;
    int aDenom = 26;
    int bNumer = -3;
    int bDenom = 7;
    int resultNumer = -153;
    int resultDenom = 182;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a * b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( times07, Rational )
{
    int aNumer = 82;
    int aDenom = 91;
    int bNumer = 10;
    int bDenom = -11;
    int resultNumer = -820;
    int resultDenom = 1001;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a * b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( times08, Rational )
{
    int aNumer = 0;
    int aDenom = 26;
    int bNumer = 3;
    int bDenom = -7;
    int resultNumer = 0;
    int resultDenom = 1;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a * b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( times09, Rational )
{
    int aNumer = 15;
    int aDenom = 26;
    int bNumer = 0;
    int bDenom = -7;
    int resultNumer = 0;
    int resultDenom = 1;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a * b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plus01, Rational )
{
    int aNumer = -9;
    int aDenom = -7;
    int bNumer = 10;
    int bDenom = 11;
    int resultNumer = 169;
    int resultDenom = 77;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a + b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plus02, Rational )
{
    int aNumer = 234;
    int aDenom = 123;
    int bNumer = 345;
    int bDenom = 756;
    int resultNumer = 24371;
    int resultDenom = 10332;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a + b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plus03, Rational )
{
    int aNumer = -4576;
    int aDenom = 3478;
    int bNumer = -3478;
    int bDenom = 4578;
    int resultNumer = -8261353;
    int resultDenom = 3980571;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a + b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plus04, Rational )
{
    int aNumer = 9405;
    int aDenom = -9470;
    int bNumer = 3789;
    int bDenom = -9483;
    int resultNumer = -8337963;
    int resultDenom = 5986934;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a + b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plus05, Rational )
{
    int aNumer = 5;
    int aDenom = 6;
    int bNumer = -37;
    int bDenom = -72;
    int resultNumer = 97;
    int resultDenom = 72;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a + b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plus06, Rational )
{
    int aNumer = 51;
    int aDenom = 26;
    int bNumer = -3;
    int bDenom = 7;
    int resultNumer = 279;
    int resultDenom = 182;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a + b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plus07, Rational )
{
    int aNumer = 82;
    int aDenom = 91;
    int bNumer = 10;
    int bDenom = -11;
    int resultNumer = -8;
    int resultDenom = 1001;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a + b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plus08, Rational )
{
    int aNumer = 0;
    int aDenom = 26;
    int bNumer = 3;
    int bDenom = -7;
    int resultNumer = -3;
    int resultDenom = 7;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a + b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( plus09, Rational )
{
    int aNumer = 15;
    int aDenom = 26;
    int bNumer = 0;
    int bDenom = -7;
    int resultNumer = 15;
    int resultDenom = 26;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a + b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minus01, Rational )
{
    int aNumer = -9;
    int aDenom = -7;
    int bNumer = 10;
    int bDenom = 11;
    int resultNumer = 29;
    int resultDenom = 77;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a - b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minus02, Rational )
{
    int aNumer = 234;
    int aDenom = 123;
    int bNumer = 345;
    int bDenom = 756;
    int resultNumer = 14941;
    int resultDenom = 10332;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a - b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minus03, Rational )
{
    int aNumer = -4576;
    int aDenom = 3478;
    int bNumer = -3478;
    int bDenom = 4578;
    int resultNumer = -2213111;
    int resultDenom = 3980571;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a - b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minus04, Rational )
{
    int aNumer = 9405;
    int aDenom = -9470;
    int bNumer = 3789;
    int bDenom = -9483;
    int resultNumer = -3553719;
    int resultDenom = 5986934;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a - b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minus05, Rational )
{
    int aNumer = 5;
    int aDenom = 6;
    int bNumer = -37;
    int bDenom = -72;
    int resultNumer = 23;
    int resultDenom = 72;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a - b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minus06, Rational )
{
    int aNumer = 51;
    int aDenom = 26;
    int bNumer = -3;
    int bDenom = 7;
    int resultNumer = 435;
    int resultDenom = 182;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a - b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minus07, Rational )
{
    int aNumer = 82;
    int aDenom = 91;
    int bNumer = 10;
    int bDenom = -11;
    int resultNumer = 1812;
    int resultDenom = 1001;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a - b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minus08, Rational )
{
    int aNumer = 0;
    int aDenom = 26;
    int bNumer = 3;
    int bDenom = -7;
    int resultNumer = 3;
    int resultDenom = 7;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a - b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( minus09, Rational )
{
    int aNumer = 15;
    int aDenom = 26;
    int bNumer = 0;
    int bDenom = -7;
    int resultNumer = 15;
    int resultDenom = 26;
    Rational a{ aNumer, aDenom };
    Rational b{ bNumer, bDenom };
    auto c = a - b;
    CHECK_EQUAL( aNumer, a.getNumerator() )
    CHECK_EQUAL( aDenom, a.getDenominator() )
    CHECK_EQUAL( bNumer, b.getNumerator() )
    CHECK_EQUAL( bDenom, b.getDenominator() )
    CHECK_EQUAL( resultNumer, c.getNumerator() )
    CHECK_EQUAL( resultDenom, c.getDenominator() )
}
T_END

TEST( getIsNegative01, Rational )
{
    Rational r{ 0, 1 };
    CHECK( ! r.getIsNegative() )
}
T_END

TEST( getIsNegative02, Rational )
{
    Rational r{ 1, 10 };
    CHECK( ! r.getIsNegative() )
}
T_END

TEST( getIsNegative03, Rational )
{
    Rational r{ -48, 90 };
    CHECK( r.getIsNegative() )
}
T_END

TEST( getIsNegative04, Rational )
{
    Rational r{ 79, -23 };
    CHECK( r.getIsNegative() )
}
T_END

TEST( getIsNegative05, Rational )
{
    Rational r{ -379, -234 };
    CHECK( ! r.getIsNegative() )
}
T_END

TEST( getIsPositive01, Rational )
{
    Rational r{ 0, 1 };
    CHECK( ! r.getIsPositive() )
}
T_END

TEST( getIsPositive02, Rational )
{
    Rational r{ 1, 10 };
    CHECK( r.getIsPositive() )
}
T_END

TEST( getIsPositive03, Rational )
{
    Rational r{ -48, 90 };
    CHECK( ! r.getIsPositive() )
}
T_END

TEST( getIsPositive04, Rational )
{
    Rational r{ 79, -23 };
    CHECK( ! r.getIsPositive() )
}
T_END

TEST( getIsPositive05, Rational )
{
    Rational r{ -379, -234 };
    CHECK( r.getIsPositive() )
}
T_END

TEST( getMixedWholePart01, Rational )
{
    Rational r{ 0, 1 };
    CHECK_EQUAL( 0, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart02, Rational )
{
    Rational r{ 1, 2 };
    CHECK_EQUAL( 0, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart03, Rational )
{
    Rational r{ 3, 3 };
    CHECK_EQUAL( 1, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart04, Rational )
{
    Rational r{ 5, 4 };
    CHECK_EQUAL( 1, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart06, Rational )
{
    Rational r{ 331, 100 };
    CHECK_EQUAL( 3, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart07, Rational )
{
    Rational r{ -1, 1 };
    CHECK_EQUAL( -1, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart08, Rational )
{
    Rational r{ -1, 2 };
    CHECK_EQUAL( 0, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart09, Rational )
{
    Rational r{ -3, 3 };
    CHECK_EQUAL( -1, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart10, Rational )
{
    Rational r{ -5, 4 };
    CHECK_EQUAL( -1, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart11, Rational )
{
    Rational r{ -331, 100 };
    CHECK_EQUAL( -3, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart12, Rational )
{
    Rational r{ -1, -1 };
    CHECK_EQUAL( 1, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart13, Rational )
{
    Rational r{ -1, -2 };
    CHECK_EQUAL( 0, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart14, Rational )
{
    Rational r{ -3, -3 };
    CHECK_EQUAL( 1, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart15, Rational )
{
    Rational r{ -5, -4 };
    CHECK_EQUAL( 1, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart16, Rational )
{
    Rational r{ -331, -100 };
    CHECK_EQUAL( 3, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart17, Rational )
{
    Rational r{ 1, -1 };
    CHECK_EQUAL( -1, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart18, Rational )
{
    Rational r{ 1, -2 };
    CHECK_EQUAL( 0, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart19, Rational )
{
    Rational r{ 3, -3 };
    CHECK_EQUAL( -1, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart20, Rational )
{
    Rational r{ 5, -4 };
    CHECK_EQUAL( -1, r.getMixedWholePart() )
}
T_END

TEST( getMixedWholePart21, Rational )
{
    Rational r{ 331, -100 };
    CHECK_EQUAL( -3, r.getMixedWholePart() )
}
T_END

TEST( getMixedFractionalPart01, Rational )
{
    Rational r{ 0, 1 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 1, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart02, Rational )
{
    Rational r{ 1, 2 };
    CHECK_EQUAL( 1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 2, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart03, Rational )
{
    Rational r{ 3, 3 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 3, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart04, Rational )
{
    Rational r{ 5, 4 };
    CHECK_EQUAL( 1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 4, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart06, Rational )
{
    Rational r{ 331, 100 };
    CHECK_EQUAL( 31, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 100, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart07, Rational )
{
    Rational r{ -1, 1 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 1, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart08, Rational )
{
    Rational r{ -1, 2 };
    CHECK_EQUAL( -1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 2, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart09, Rational )
{
    Rational r{ -3, 3 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 3, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart10, Rational )
{
    Rational r{ -5, 4 };
    CHECK_EQUAL( -1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 4, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart11, Rational )
{
    Rational r{ -331, 100 };
    CHECK_EQUAL( -31, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 100, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart12, Rational )
{
    Rational r{ -1, -1 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -1, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart13, Rational )
{
    Rational r{ -1, -2 };
    CHECK_EQUAL( -1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -2, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart14, Rational )
{
    Rational r{ -3, -3 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -3, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart15, Rational )
{
    Rational r{ -5, -4 };
    CHECK_EQUAL( -1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -4, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart16, Rational )
{
    Rational r{ -331, -100 };
    CHECK_EQUAL( -31, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -100, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart17, Rational )
{
    Rational r{ 1, -1 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -1, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart18, Rational )
{
    Rational r{ 1, -2 };
    CHECK_EQUAL( 1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -2, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart19, Rational )
{
    Rational r{ 3, -3 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -3, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart20, Rational )
{
    Rational r{ 5, -4 };
    CHECK_EQUAL( 1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -4, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getMixedFractionalPart21, Rational )
{
    Rational r{ 331, -100 };
    CHECK_EQUAL( 31, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -100, r.getMixedFractionalPart().getDenominator() )
}
T_END

TEST( getIsIdenticalTo01, Rational )
{
    Rational a{ 1, -2 };
    Rational b{ 1, -2 };
    CHECK( a.getIsIdenticalTo( b ) )
    CHECK( b.getIsIdenticalTo( a ) )
}
T_END

TEST( getIsIdenticalTo02, Rational )
{
    Rational a{ 1, -2 };
    Rational b{ 2, -4 };
    CHECK( ! a.getIsIdenticalTo( b ) )
    CHECK( ! b.getIsIdenticalTo( a ) )
}
T_END

TEST( comparisons01aisEqualTob, Rational )
{
    Rational a{ 1, 2 };
    Rational b{ 1, 2 };
    CHECK( a.getIsIdenticalTo( b ) )
    CHECK(   ( a == b ) )
    CHECK( ! ( a != b ) )
    CHECK( ! ( a  < b ) )
    CHECK( ! ( a  > b ) )
    CHECK(   ( a <= b ) )
    CHECK(   ( a >= b ) )
}
T_END

TEST( comparisons01aisGreaterThanb, Rational )
{
    Rational a{ 1, 2 };
    Rational b{ 1, 3 };
    CHECK( ! a.getIsIdenticalTo( b ) )
    CHECK( ! ( a == b ) )
    CHECK(   ( a != b ) )
    CHECK( ! ( a  < b ) )
    CHECK(   ( a  > b ) )
    CHECK( ! ( a <= b ) )
    CHECK(   ( a >= b ) )
}
T_END

TEST( comparisons01aisLessThanb, Rational )
{
    Rational a{ -1, 2 };
    Rational b{ -1, -3 };
    CHECK( ! a.getIsIdenticalTo( b ) )
    CHECK( ! ( a == b ) )
    CHECK(   ( a != b ) )
    CHECK(   ( a  < b ) )
    CHECK( ! ( a  > b ) )
    CHECK(   ( a <= b ) )
    CHECK( ! ( a >= b ) )
}
T_END

TEST( comparisons02aisEqualTob, Rational )
{
    Rational a{ 13, -21 };
    Rational b{ -26, 42 };
    CHECK( ! a.getIsIdenticalTo( b ) )
    CHECK(   ( a == b ) )
    CHECK( ! ( a != b ) )
    CHECK( ! ( a  < b ) )
    CHECK( ! ( a  > b ) )
    CHECK(   ( a <= b ) )
    CHECK(   ( a >= b ) )
}
T_END

TEST( comparisons02aisGreaterThanb, Rational )
{
    Rational a{ -1, -2 };
    Rational b{ -1, 323498 };
    CHECK( ! a.getIsIdenticalTo( b ) )
    CHECK( ! ( a == b ) )
    CHECK(   ( a != b ) )
    CHECK( ! ( a  < b ) )
    CHECK(   ( a  > b ) )
    CHECK( ! ( a <= b ) )
    CHECK(   ( a >= b ) )
}
T_END

TEST( comparisons02aisLessThanb, Rational )
{
    Rational a{ -1, -200 };
    Rational b{ -1, -3 };
    CHECK( ! a.getIsIdenticalTo( b ) )
    CHECK( ! ( a == b ) )
    CHECK(   ( a != b ) )
    CHECK(   ( a  < b ) )
    CHECK( ! ( a  > b ) )
    CHECK(   ( a <= b ) )
    CHECK( ! ( a >= b ) )
}
T_END