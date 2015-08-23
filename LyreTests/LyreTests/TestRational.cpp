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

TEST( lcm_vec01, Rational )
{
    Integers vec = { -100, 10 };
    Integer actual = Rational::lcm( vec );
    CHECK_EQUAL( 100, actual )
}
TEST( lcm_vec02, Rational )
{
    Integers vec = { -100, 10, 5 };
    Integer actual = Rational::lcm( vec );
    CHECK_EQUAL( 100, actual )
}
TEST( lcm_vec03, Rational )
{
    Integers vec = { -297, -231, -198, -66 };
    Integer actual = Rational::lcm( vec );
    CHECK_EQUAL( 4158, actual )
}
TEST( lcm_vec04, Rational )
{
    Integers vec;
    Integer actual = Rational::lcm( vec );
    CHECK_EQUAL( 0, actual )
}
TEST( lcm_vec05, Rational )
{
    Integers vec = { -2130 };
    Integer actual = Rational::lcm( vec );
    CHECK_EQUAL( 2130, actual )
}
TEST( lcm_vec06, Rational )
{
    Integers vec = { 9 };
    Integer actual = Rational::lcm( vec );
    CHECK_EQUAL( 9, actual )
}
TEST( lcm_vec07, Rational )
{
    Integers vec = { 9, -3, 33, -99, 0 };
    std::string expected = "zeros not allowed";
    std::string actual = "no exception was thrown";
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
    CHECK_EQUAL( expected, actual )
}
TEST( lcm_vec08, Rational )
{
    Integers vec = { 0 };
    std::string expected = "zeros not allowed";
    std::string actual = "no exception was thrown";
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
    CHECK_EQUAL( expected, actual )
}

TEST( lcd01, Rational )
{
    Rational a{ 2, 4 };
    Rational b{ 1, 2 };
    Rational::lcd( a, b );
    Integer expectedDenominator = 2;
    Integer expectedNumeratorA = 1;
    Integer expectedNumeratorB = 1;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
TEST( lcd02, Rational )
{
    Rational a{ 3, 12 };
    Rational b{ 6, 48 };
    Rational::lcd( a, b );
    //std::cout << a << " " << b << std::endl;
    Integer expectedDenominator = 8;
    Integer expectedNumeratorA = 2;
    Integer expectedNumeratorB = 1;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
TEST( lcd03, Rational )
{
    Rational a{ 12, 16 };
    Rational b{ 1, 20 };
    Rational::lcd( a, b );
    //std::cout << a << " " << b << std::endl;
    Integer expectedDenominator = 20;
    Integer expectedNumeratorA = 15;
    Integer expectedNumeratorB = 1;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
TEST( lcd04, Rational )
{
    Rational a{ 7, 1582 };
    Rational b{ 654, 12769 };
    Rational::lcd( a, b );
    //std::cout << a << " " << b << std::endl;
    Integer expectedDenominator = 25538;
    Integer expectedNumeratorA = 113;
    Integer expectedNumeratorB = 1308;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
TEST( lcd05, Rational )
{
    Rational a{ 0, 10 };
    Rational b{ 11, -15 };
    Rational::lcd( a, b );
    //std::cout << a << " " << b << std::endl;
    Integer expectedDenominator = 15;
    Integer expectedNumeratorA = 0;
    Integer expectedNumeratorB = -11;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
TEST( lcd06, Rational )
{
    Rational a{ 1, -5 };
    Rational b{ -11, -15 };
    Rational::lcd( a, b );
    // std::cout << a << " " << b << std::endl;
    Integer expectedDenominator = 15;
    Integer expectedNumeratorA = -3;
    Integer expectedNumeratorB = 11;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
TEST( lcd07, Rational )
{
    Rational a{ 3, 12 };
    Rational b{ 6, 48 };
    Rational::lcd( a, b, false );
    //std::cout << a << " " << b << std::endl;
    Integer expectedDenominator = 48;
    Integer expectedNumeratorA = 12;
    Integer expectedNumeratorB = 6;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
TEST( lcd08, Rational )
{
    Rational a{ 12, 16 };
    Rational b{ 1, 20 };
    Rational::lcd( a, b, false );
    //std::cout << a << " " << b << std::endl;
    Integer expectedDenominator = 80;
    Integer expectedNumeratorA = 60;
    Integer expectedNumeratorB = 4;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
TEST( lcd09, Rational )
{
    Rational a{ 7, 1582 };
    Rational b{ 654, 12769 };
    Rational::lcd( a, b, false );
    //std::cout << a << " " << b << std::endl;
    Integer expectedDenominator = 178766;
    Integer expectedNumeratorA = 791;
    Integer expectedNumeratorB = 9156;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
TEST( lcd10, Rational )
{
    Rational a{ 0, 10 };
    Rational b{ 11, -15 };
    Rational::lcd( a, b, false );
    //std::cout << a << " " << b << std::endl;
    Integer expectedDenominator = 30;
    Integer expectedNumeratorA = 0;
    Integer expectedNumeratorB = -22;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
TEST( lcd11, Rational )
{
    Rational a{ 1, -5 };
    Rational b{ -11, -15 };
    Rational::lcd( a, b, false );
    // std::cout << a << " " << b << std::endl;
    Integer expectedDenominator = 15;
    Integer expectedNumeratorA = -3;
    Integer expectedNumeratorB = 11;
    CHECK_EQUAL( expectedNumeratorA, a.getNumerator() )
    CHECK_EQUAL( expectedDenominator, a.getDenominator() )
    CHECK_EQUAL( expectedNumeratorB, b.getNumerator() )
    CHECK_EQUAL( expectedDenominator, b.getDenominator() )
}
TEST( lcdList01, Rational )
{
    Rationals rats;
    Rational::lcd( rats );
    CHECK_EQUAL( 0, rats.size() );
    
}
TEST( lcdList02, Rational )
{
    Rationals rats;
    rats.push_back( Rational{ 6, 4 } );
    Rational::lcd( rats );
    CHECK_EQUAL( 1, rats.size() )
    CHECK_EQUAL( 3, rats.cbegin()->getNumerator() )
    CHECK_EQUAL( 2, rats.cbegin()->getDenominator() )
    
}
TEST( lcdList03, Rational )
{
    Rationals rats;
    rats.push_back( Rational{ 6, 4 } );
    rats.push_back( Rational{ 7, 9 } );
    rats.push_back( Rational{ 1, 10 } );
    Rational::lcd( rats );
    CHECK_EQUAL( 3, rats.size() )
    auto r = rats.cbegin();
    Integer denom = 90;
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
TEST( lcdList04, Rational )
{
    Rationals rats;
    rats.push_back( Rational{ 17, -18 } );
    rats.push_back( Rational{ -71, 9 } );
    rats.push_back( Rational{ -1, -10 } );
    Rational::lcd( rats );
    CHECK_EQUAL( 3, rats.size() )
    auto r = rats.cbegin();
    Integer denom = 90;
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
TEST( lcdList01noReduce, Rational )
{
    Rationals rats;
    rats.push_back( Rational{ 6, 4 } );
    Rational::lcd( rats, false );
    CHECK_EQUAL( 1, rats.size() )
    CHECK_EQUAL( 6, rats.cbegin()->getNumerator() )
    CHECK_EQUAL( 4, rats.cbegin()->getDenominator() )
    
}
TEST( lcdList02noReduce, Rational )
{
    Rationals rats;
    rats.push_back( Rational{ 6, 4 } );
    rats.push_back( Rational{ 7, 9 } );
    rats.push_back( Rational{ 1, 10 } );
    Rational::lcd( rats, false );
    CHECK_EQUAL( 3, rats.size() )
    auto r = rats.cbegin();
    Integer denom = 180;
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
TEST( lcdList03noReduce, Rational )
{
    Rationals rats;
    rats.push_back( Rational{ 17, -18 } );
    rats.push_back( Rational{ -71, 9 } );
    rats.push_back( Rational{ -1, -10 } );
    Rational::lcd( rats, false );
    CHECK_EQUAL( 3, rats.size() )
    auto r = rats.cbegin();
    Integer denom = 90;
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