#include "cpulTestHarness.h"
#include "Rational.h"
#include "TypeDefs.h"

using namespace lyre;

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
TEST( reduce01, Rational )
{
    Rational r{ 0, 10 };
    bool changed = r.reduce();
    CHECK( changed )
    CHECK_EQUAL( 0, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
TEST( reduce02, Rational )
{
    Rational r{ 99, -99 };
    bool changed = r.reduce();
    CHECK( changed )
    CHECK_EQUAL( -1, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
TEST( reduce03, Rational )
{
    Rational r{ -200, -100 };
    bool changed = r.reduce();
    CHECK( changed )
    CHECK_EQUAL( 2, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
TEST( reduce04, Rational )
{
    Rational r{ 5, 15 };
    bool changed = r.reduce();
    CHECK( changed )
    CHECK_EQUAL( 1, r.getNumerator() )
    CHECK_EQUAL( 3, r.getDenominator() )
}
TEST( reduce05, Rational )
{
    Rational r{ 0, -115 };
    bool changed = r.reduce();
    CHECK( changed )
    CHECK_EQUAL( 0, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
TEST( reduce06, Rational )
{
    Rational r{ -3, -250377 };
    bool changed = r.reduce();
    CHECK( changed )
    CHECK_EQUAL( 1, r.getNumerator() )
    CHECK_EQUAL( 83459, r.getDenominator() )
}
TEST( reciprocal01, Rational )
{
    Rational r;
    r.reciprocal();
    CHECK_EQUAL( 0, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
TEST( reciprocal02, Rational )
{
    Rational r{ 0, 99 };
    r.reciprocal();
    CHECK_EQUAL( 0, r.getNumerator() )
    CHECK_EQUAL( 99, r.getDenominator() )
}
TEST( reciprocal03, Rational )
{
    Rational r{ 1, 3 };
    r.reciprocal();
    CHECK_EQUAL( 3, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
TEST( reciprocal04, Rational )
{
    Rational r{ 31, -93 };
    r.reciprocal();
    CHECK_EQUAL( -93, r.getNumerator() )
    CHECK_EQUAL( 31, r.getDenominator() )
}
TEST( reciprocal05, Rational )
{
    Rational r{ -19348, 8488302 };
    r.reciprocal();
    CHECK_EQUAL( 8488302, r.getNumerator() )
    CHECK_EQUAL( -19348, r.getDenominator() )
}
TEST( reciprocal06, Rational )
{
    Rational r{ -9, -7 };
    r.reciprocal();
    CHECK_EQUAL( -7, r.getNumerator() )
    CHECK_EQUAL( -9, r.getDenominator() )
}
TEST( divideEquals01, Rational )
{
    Integer aNumer = -9;
    Integer aDenom = -7;
    Integer bNumer = 10;
    Integer bDenom = 11;
    Integer resultNumer = 99;
    Integer resultDenom = 70;
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
TEST( divideEquals02, Rational )
{
    Integer aNumer = 234;
    Integer aDenom = 123;
    Integer bNumer = 345;
    Integer bDenom = 756;
    Integer resultNumer = 19656;
    Integer resultDenom = 4715;
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
TEST( divideEquals03, Rational )
{
    Integer aNumer = -4576;
    Integer aDenom = 3478;
    Integer bNumer = -3478;
    Integer bDenom = 4578;
    Integer resultNumer = 5237232;
    Integer resultDenom = 3024121;
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
TEST( divideEquals04, Rational )
{
    Integer aNumer = 9405;
    Integer aDenom = -9470;
    Integer bNumer = 3789;
    Integer bDenom = -9483;
    Integer resultNumer = 1981947;
    Integer resultDenom = 797374;
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
TEST( divideEquals05, Rational )
{
    Integer aNumer = 5;
    Integer aDenom = 6;
    Integer bNumer = -37;
    Integer bDenom = -72;
    Integer resultNumer = 60;
    Integer resultDenom = 37;
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
TEST( divideEquals06, Rational )
{
    Integer aNumer = 51;
    Integer aDenom = 26;
    Integer bNumer = -3;
    Integer bDenom = 7;
    Integer resultNumer = -119;
    Integer resultDenom = 26;
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
TEST( divideEquals07, Rational )
{
    Integer aNumer = 82;
    Integer aDenom = 91;
    Integer bNumer = 10;
    Integer bDenom = -11;
    Integer resultNumer = -451;
    Integer resultDenom = 455;
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
TEST( divideEquals08, Rational )
{
    Integer aNumer = 0;
    Integer aDenom = 26;
    Integer bNumer = 3;
    Integer bDenom = -7;
    Integer resultNumer = 0;
    Integer resultDenom = 1;
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
TEST( divideEquals09, Rational )
{
    Integer aNumer = 15;
    Integer aDenom = 26;
    Integer bNumer = 0;
    Integer bDenom = -7;
    Integer resultNumer = 15;
    Integer resultDenom = 26;
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
TEST( timesEquals01, Rational )
{
    Integer aNumer = -9;
    Integer aDenom = -7;
    Integer bNumer = 10;
    Integer bDenom = 11;
    Integer resultNumer = 90;
    Integer resultDenom = 77;
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
TEST( timesEquals02, Rational )
{
    Integer aNumer = 234;
    Integer aDenom = 123;
    Integer bNumer = 345;
    Integer bDenom = 756;
    Integer resultNumer = 1495;
    Integer resultDenom = 1722;
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
TEST( timesEquals03, Rational )
{
    Integer aNumer = -4576;
    Integer aDenom = 3478;
    Integer bNumer = -3478;
    Integer bDenom = 4578;
    Integer resultNumer = 2288;
    Integer resultDenom = 2289;
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
TEST( timesEquals04, Rational )
{
    Integer aNumer = 9405;
    Integer aDenom = -9470;
    Integer bNumer = 3789;
    Integer bDenom = -9483;
    Integer resultNumer = 2375703;
    Integer resultDenom = 5986934;
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
TEST( timesEquals05, Rational )
{
    Integer aNumer = 5;
    Integer aDenom = 6;
    Integer bNumer = -37;
    Integer bDenom = -72;
    Integer resultNumer = 185;
    Integer resultDenom = 432;
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
TEST( timesEquals06, Rational )
{
    Integer aNumer = 51;
    Integer aDenom = 26;
    Integer bNumer = -3;
    Integer bDenom = 7;
    Integer resultNumer = -153;
    Integer resultDenom = 182;
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
TEST( timesEquals07, Rational )
{
    Integer aNumer = 82;
    Integer aDenom = 91;
    Integer bNumer = 10;
    Integer bDenom = -11;
    Integer resultNumer = -820;
    Integer resultDenom = 1001;
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
TEST( timesEquals08, Rational )
{
    Integer aNumer = 0;
    Integer aDenom = 26;
    Integer bNumer = 3;
    Integer bDenom = -7;
    Integer resultNumer = 0;
    Integer resultDenom = 1;
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
TEST( timesEquals09, Rational )
{
    Integer aNumer = 15;
    Integer aDenom = 26;
    Integer bNumer = 0;
    Integer bDenom = -7;
    Integer resultNumer = 0;
    Integer resultDenom = 1;
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

TEST( plusEquals01, Rational )
{
    Integer aNumer = -9;
    Integer aDenom = -7;
    Integer bNumer = 10;
    Integer bDenom = 11;
    Integer resultNumer = 169;
    Integer resultDenom = 77;
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
TEST( plusEquals02, Rational )
{
    Integer aNumer = 234;
    Integer aDenom = 123;
    Integer bNumer = 345;
    Integer bDenom = 756;
    Integer resultNumer = 24371;
    Integer resultDenom = 10332;
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
TEST( plusEquals03, Rational )
{
    Integer aNumer = -4576;
    Integer aDenom = 3478;
    Integer bNumer = -3478;
    Integer bDenom = 4578;
    Integer resultNumer = -8261353;
    Integer resultDenom = 3980571;
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
TEST( plusEquals04, Rational )
{
    Integer aNumer = 9405;
    Integer aDenom = -9470;
    Integer bNumer = 3789;
    Integer bDenom = -9483;
    Integer resultNumer = -8337963;
    Integer resultDenom = 5986934;
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
TEST( plusEquals05, Rational )
{
    Integer aNumer = 5;
    Integer aDenom = 6;
    Integer bNumer = -37;
    Integer bDenom = -72;
    Integer resultNumer = 97;
    Integer resultDenom = 72;
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
TEST( plusEquals06, Rational )
{
    Integer aNumer = 51;
    Integer aDenom = 26;
    Integer bNumer = -3;
    Integer bDenom = 7;
    Integer resultNumer = 279;
    Integer resultDenom = 182;
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
TEST( plusEquals07, Rational )
{
    Integer aNumer = 82;
    Integer aDenom = 91;
    Integer bNumer = 10;
    Integer bDenom = -11;
    Integer resultNumer = -8;
    Integer resultDenom = 1001;
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
TEST( plusEquals08, Rational )
{
    Integer aNumer = 0;
    Integer aDenom = 26;
    Integer bNumer = 3;
    Integer bDenom = -7;
    Integer resultNumer = -3;
    Integer resultDenom = 7;
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
TEST( plusEquals09, Rational )
{
    Integer aNumer = 15;
    Integer aDenom = 26;
    Integer bNumer = 0;
    Integer bDenom = -7;
    Integer resultNumer = 15;
    Integer resultDenom = 26;
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

TEST( minusEquals01, Rational )
{
    Integer aNumer = -9;
    Integer aDenom = -7;
    Integer bNumer = 10;
    Integer bDenom = 11;
    Integer resultNumer = 29;
    Integer resultDenom = 77;
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
TEST( minusEquals02, Rational )
{
    Integer aNumer = 234;
    Integer aDenom = 123;
    Integer bNumer = 345;
    Integer bDenom = 756;
    Integer resultNumer = 14941;
    Integer resultDenom = 10332;
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
TEST( minusEquals03, Rational )
{
    Integer aNumer = -4576;
    Integer aDenom = 3478;
    Integer bNumer = -3478;
    Integer bDenom = 4578;
    Integer resultNumer = -2213111;
    Integer resultDenom = 3980571;
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
TEST( minusEquals04, Rational )
{
    Integer aNumer = 9405;
    Integer aDenom = -9470;
    Integer bNumer = 3789;
    Integer bDenom = -9483;
    Integer resultNumer = -3553719;
    Integer resultDenom = 5986934;
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
TEST( minusEquals05, Rational )
{
    Integer aNumer = 5;
    Integer aDenom = 6;
    Integer bNumer = -37;
    Integer bDenom = -72;
    Integer resultNumer = 23;
    Integer resultDenom = 72;
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
TEST( minusEquals06, Rational )
{
    Integer aNumer = 51;
    Integer aDenom = 26;
    Integer bNumer = -3;
    Integer bDenom = 7;
    Integer resultNumer = 435;
    Integer resultDenom = 182;
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
TEST( minusEquals07, Rational )
{
    Integer aNumer = 82;
    Integer aDenom = 91;
    Integer bNumer = 10;
    Integer bDenom = -11;
    Integer resultNumer = 1812;
    Integer resultDenom = 1001;
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
TEST( minusEquals08, Rational )
{
    Integer aNumer = 0;
    Integer aDenom = 26;
    Integer bNumer = 3;
    Integer bDenom = -7;
    Integer resultNumer = 3;
    Integer resultDenom = 7;
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
TEST( minusEquals09, Rational )
{
    Integer aNumer = 15;
    Integer aDenom = 26;
    Integer bNumer = 0;
    Integer bDenom = -7;
    Integer resultNumer = 15;
    Integer resultDenom = 26;
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





/*****************************/

TEST( divide01, Rational )
{
    Integer aNumer = -9;
    Integer aDenom = -7;
    Integer bNumer = 10;
    Integer bDenom = 11;
    Integer resultNumer = 99;
    Integer resultDenom = 70;
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
TEST( divide02, Rational )
{
    Integer aNumer = 234;
    Integer aDenom = 123;
    Integer bNumer = 345;
    Integer bDenom = 756;
    Integer resultNumer = 19656;
    Integer resultDenom = 4715;
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
TEST( divide03, Rational )
{
    Integer aNumer = -4576;
    Integer aDenom = 3478;
    Integer bNumer = -3478;
    Integer bDenom = 4578;
    Integer resultNumer = 5237232;
    Integer resultDenom = 3024121;
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
TEST( divide04, Rational )
{
    Integer aNumer = 9405;
    Integer aDenom = -9470;
    Integer bNumer = 3789;
    Integer bDenom = -9483;
    Integer resultNumer = 1981947;
    Integer resultDenom = 797374;
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
TEST( divide05, Rational )
{
    Integer aNumer = 5;
    Integer aDenom = 6;
    Integer bNumer = -37;
    Integer bDenom = -72;
    Integer resultNumer = 60;
    Integer resultDenom = 37;
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
TEST( divide06, Rational )
{
    Integer aNumer = 51;
    Integer aDenom = 26;
    Integer bNumer = -3;
    Integer bDenom = 7;
    Integer resultNumer = -119;
    Integer resultDenom = 26;
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
TEST( divide07, Rational )
{
    Integer aNumer = 82;
    Integer aDenom = 91;
    Integer bNumer = 10;
    Integer bDenom = -11;
    Integer resultNumer = -451;
    Integer resultDenom = 455;
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
TEST( divide08, Rational )
{
    Integer aNumer = 0;
    Integer aDenom = 26;
    Integer bNumer = 3;
    Integer bDenom = -7;
    Integer resultNumer = 0;
    Integer resultDenom = 1;
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
TEST( divide09, Rational )
{
    Integer aNumer = 15;
    Integer aDenom = 26;
    Integer bNumer = 0;
    Integer bDenom = -7;
    Integer resultNumer = 0;
    Integer resultDenom = 1;
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
TEST( times01, Rational )
{
    Integer aNumer = -9;
    Integer aDenom = -7;
    Integer bNumer = 10;
    Integer bDenom = 11;
    Integer resultNumer = 90;
    Integer resultDenom = 77;
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
TEST( times02, Rational )
{
    Integer aNumer = 234;
    Integer aDenom = 123;
    Integer bNumer = 345;
    Integer bDenom = 756;
    Integer resultNumer = 1495;
    Integer resultDenom = 1722;
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
TEST( times03, Rational )
{
    Integer aNumer = -4576;
    Integer aDenom = 3478;
    Integer bNumer = -3478;
    Integer bDenom = 4578;
    Integer resultNumer = 2288;
    Integer resultDenom = 2289;
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
TEST( times04, Rational )
{
    Integer aNumer = 9405;
    Integer aDenom = -9470;
    Integer bNumer = 3789;
    Integer bDenom = -9483;
    Integer resultNumer = 2375703;
    Integer resultDenom = 5986934;
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
TEST( times05, Rational )
{
    Integer aNumer = 5;
    Integer aDenom = 6;
    Integer bNumer = -37;
    Integer bDenom = -72;
    Integer resultNumer = 185;
    Integer resultDenom = 432;
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
TEST( times06, Rational )
{
    Integer aNumer = 51;
    Integer aDenom = 26;
    Integer bNumer = -3;
    Integer bDenom = 7;
    Integer resultNumer = -153;
    Integer resultDenom = 182;
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
TEST( times07, Rational )
{
    Integer aNumer = 82;
    Integer aDenom = 91;
    Integer bNumer = 10;
    Integer bDenom = -11;
    Integer resultNumer = -820;
    Integer resultDenom = 1001;
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
TEST( times08, Rational )
{
    Integer aNumer = 0;
    Integer aDenom = 26;
    Integer bNumer = 3;
    Integer bDenom = -7;
    Integer resultNumer = 0;
    Integer resultDenom = 1;
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
TEST( times09, Rational )
{
    Integer aNumer = 15;
    Integer aDenom = 26;
    Integer bNumer = 0;
    Integer bDenom = -7;
    Integer resultNumer = 0;
    Integer resultDenom = 1;
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

TEST( plus01, Rational )
{
    Integer aNumer = -9;
    Integer aDenom = -7;
    Integer bNumer = 10;
    Integer bDenom = 11;
    Integer resultNumer = 169;
    Integer resultDenom = 77;
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
TEST( plus02, Rational )
{
    Integer aNumer = 234;
    Integer aDenom = 123;
    Integer bNumer = 345;
    Integer bDenom = 756;
    Integer resultNumer = 24371;
    Integer resultDenom = 10332;
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
TEST( plus03, Rational )
{
    Integer aNumer = -4576;
    Integer aDenom = 3478;
    Integer bNumer = -3478;
    Integer bDenom = 4578;
    Integer resultNumer = -8261353;
    Integer resultDenom = 3980571;
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
TEST( plus04, Rational )
{
    Integer aNumer = 9405;
    Integer aDenom = -9470;
    Integer bNumer = 3789;
    Integer bDenom = -9483;
    Integer resultNumer = -8337963;
    Integer resultDenom = 5986934;
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
TEST( plus05, Rational )
{
    Integer aNumer = 5;
    Integer aDenom = 6;
    Integer bNumer = -37;
    Integer bDenom = -72;
    Integer resultNumer = 97;
    Integer resultDenom = 72;
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
TEST( plus06, Rational )
{
    Integer aNumer = 51;
    Integer aDenom = 26;
    Integer bNumer = -3;
    Integer bDenom = 7;
    Integer resultNumer = 279;
    Integer resultDenom = 182;
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
TEST( plus07, Rational )
{
    Integer aNumer = 82;
    Integer aDenom = 91;
    Integer bNumer = 10;
    Integer bDenom = -11;
    Integer resultNumer = -8;
    Integer resultDenom = 1001;
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
TEST( plus08, Rational )
{
    Integer aNumer = 0;
    Integer aDenom = 26;
    Integer bNumer = 3;
    Integer bDenom = -7;
    Integer resultNumer = -3;
    Integer resultDenom = 7;
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
TEST( plus09, Rational )
{
    Integer aNumer = 15;
    Integer aDenom = 26;
    Integer bNumer = 0;
    Integer bDenom = -7;
    Integer resultNumer = 15;
    Integer resultDenom = 26;
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

TEST( minus01, Rational )
{
    Integer aNumer = -9;
    Integer aDenom = -7;
    Integer bNumer = 10;
    Integer bDenom = 11;
    Integer resultNumer = 29;
    Integer resultDenom = 77;
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
TEST( minus02, Rational )
{
    Integer aNumer = 234;
    Integer aDenom = 123;
    Integer bNumer = 345;
    Integer bDenom = 756;
    Integer resultNumer = 14941;
    Integer resultDenom = 10332;
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
TEST( minus03, Rational )
{
    Integer aNumer = -4576;
    Integer aDenom = 3478;
    Integer bNumer = -3478;
    Integer bDenom = 4578;
    Integer resultNumer = -2213111;
    Integer resultDenom = 3980571;
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
TEST( minus04, Rational )
{
    Integer aNumer = 9405;
    Integer aDenom = -9470;
    Integer bNumer = 3789;
    Integer bDenom = -9483;
    Integer resultNumer = -3553719;
    Integer resultDenom = 5986934;
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
TEST( minus05, Rational )
{
    Integer aNumer = 5;
    Integer aDenom = 6;
    Integer bNumer = -37;
    Integer bDenom = -72;
    Integer resultNumer = 23;
    Integer resultDenom = 72;
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
TEST( minus06, Rational )
{
    Integer aNumer = 51;
    Integer aDenom = 26;
    Integer bNumer = -3;
    Integer bDenom = 7;
    Integer resultNumer = 435;
    Integer resultDenom = 182;
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
TEST( minus07, Rational )
{
    Integer aNumer = 82;
    Integer aDenom = 91;
    Integer bNumer = 10;
    Integer bDenom = -11;
    Integer resultNumer = 1812;
    Integer resultDenom = 1001;
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
TEST( minus08, Rational )
{
    Integer aNumer = 0;
    Integer aDenom = 26;
    Integer bNumer = 3;
    Integer bDenom = -7;
    Integer resultNumer = 3;
    Integer resultDenom = 7;
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
TEST( minus09, Rational )
{
    Integer aNumer = 15;
    Integer aDenom = 26;
    Integer bNumer = 0;
    Integer bDenom = -7;
    Integer resultNumer = 15;
    Integer resultDenom = 26;
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
TEST( getIsNegative01, Rational )
{
    Rational r{ 0, 1 };
    CHECK( ! r.getIsNegative() )
}
TEST( getIsNegative02, Rational )
{
    Rational r{ 1, 10 };
    CHECK( ! r.getIsNegative() )
}
TEST( getIsNegative03, Rational )
{
    Rational r{ -48, 90 };
    CHECK( r.getIsNegative() )
}
TEST( getIsNegative04, Rational )
{
    Rational r{ 79, -23 };
    CHECK( r.getIsNegative() )
}
TEST( getIsNegative05, Rational )
{
    Rational r{ -379, -234 };
    CHECK( ! r.getIsNegative() )
}
TEST( getIsPositive01, Rational )
{
    Rational r{ 0, 1 };
    CHECK( ! r.getIsPositive() )
}
TEST( getIsPositive02, Rational )
{
    Rational r{ 1, 10 };
    CHECK( r.getIsPositive() )
}
TEST( getIsPositive03, Rational )
{
    Rational r{ -48, 90 };
    CHECK( ! r.getIsPositive() )
}
TEST( getIsPositive04, Rational )
{
    Rational r{ 79, -23 };
    CHECK( ! r.getIsPositive() )
}
TEST( getIsPositive05, Rational )
{
    Rational r{ -379, -234 };
    CHECK( r.getIsPositive() )
}
TEST( getMixedWholePart01, Rational )
{
    Rational r{ 0, 1 };
    CHECK_EQUAL( 0, r.getMixedWholePart() )
}
TEST( getMixedWholePart02, Rational )
{
    Rational r{ 1, 2 };
    CHECK_EQUAL( 0, r.getMixedWholePart() )
}
TEST( getMixedWholePart03, Rational )
{
    Rational r{ 3, 3 };
    CHECK_EQUAL( 1, r.getMixedWholePart() )
}
TEST( getMixedWholePart04, Rational )
{
    Rational r{ 5, 4 };
    CHECK_EQUAL( 1, r.getMixedWholePart() )
}
TEST( getMixedWholePart06, Rational )
{
    Rational r{ 331, 100 };
    CHECK_EQUAL( 3, r.getMixedWholePart() )
}
TEST( getMixedWholePart07, Rational )
{
    Rational r{ -1, 1 };
    CHECK_EQUAL( -1, r.getMixedWholePart() )
}
TEST( getMixedWholePart08, Rational )
{
    Rational r{ -1, 2 };
    CHECK_EQUAL( 0, r.getMixedWholePart() )
}
TEST( getMixedWholePart09, Rational )
{
    Rational r{ -3, 3 };
    CHECK_EQUAL( -1, r.getMixedWholePart() )
}
TEST( getMixedWholePart10, Rational )
{
    Rational r{ -5, 4 };
    CHECK_EQUAL( -1, r.getMixedWholePart() )
}
TEST( getMixedWholePart11, Rational )
{
    Rational r{ -331, 100 };
    CHECK_EQUAL( -3, r.getMixedWholePart() )
}
TEST( getMixedWholePart12, Rational )
{
    Rational r{ -1, -1 };
    CHECK_EQUAL( 1, r.getMixedWholePart() )
}
TEST( getMixedWholePart13, Rational )
{
    Rational r{ -1, -2 };
    CHECK_EQUAL( 0, r.getMixedWholePart() )
}
TEST( getMixedWholePart14, Rational )
{
    Rational r{ -3, -3 };
    CHECK_EQUAL( 1, r.getMixedWholePart() )
}
TEST( getMixedWholePart15, Rational )
{
    Rational r{ -5, -4 };
    CHECK_EQUAL( 1, r.getMixedWholePart() )
}
TEST( getMixedWholePart16, Rational )
{
    Rational r{ -331, -100 };
    CHECK_EQUAL( 3, r.getMixedWholePart() )
}
TEST( getMixedWholePart17, Rational )
{
    Rational r{ 1, -1 };
    CHECK_EQUAL( -1, r.getMixedWholePart() )
}
TEST( getMixedWholePart18, Rational )
{
    Rational r{ 1, -2 };
    CHECK_EQUAL( 0, r.getMixedWholePart() )
}
TEST( getMixedWholePart19, Rational )
{
    Rational r{ 3, -3 };
    CHECK_EQUAL( -1, r.getMixedWholePart() )
}
TEST( getMixedWholePart20, Rational )
{
    Rational r{ 5, -4 };
    CHECK_EQUAL( -1, r.getMixedWholePart() )
}
TEST( getMixedWholePart21, Rational )
{
    Rational r{ 331, -100 };
    CHECK_EQUAL( -3, r.getMixedWholePart() )
}

TEST( getMixedFractionalPart01, Rational )
{
    Rational r{ 0, 1 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 1, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart02, Rational )
{
    Rational r{ 1, 2 };
    CHECK_EQUAL( 1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 2, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart03, Rational )
{
    Rational r{ 3, 3 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 3, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart04, Rational )
{
    Rational r{ 5, 4 };
    CHECK_EQUAL( 1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 4, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart06, Rational )
{
    Rational r{ 331, 100 };
    CHECK_EQUAL( 31, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 100, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart07, Rational )
{
    Rational r{ -1, 1 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 1, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart08, Rational )
{
    Rational r{ -1, 2 };
    CHECK_EQUAL( -1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 2, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart09, Rational )
{
    Rational r{ -3, 3 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 3, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart10, Rational )
{
    Rational r{ -5, 4 };
    CHECK_EQUAL( -1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 4, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart11, Rational )
{
    Rational r{ -331, 100 };
    CHECK_EQUAL( -31, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( 100, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart12, Rational )
{
    Rational r{ -1, -1 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -1, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart13, Rational )
{
    Rational r{ -1, -2 };
    CHECK_EQUAL( -1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -2, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart14, Rational )
{
    Rational r{ -3, -3 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -3, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart15, Rational )
{
    Rational r{ -5, -4 };
    CHECK_EQUAL( -1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -4, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart16, Rational )
{
    Rational r{ -331, -100 };
    CHECK_EQUAL( -31, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -100, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart17, Rational )
{
    Rational r{ 1, -1 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -1, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart18, Rational )
{
    Rational r{ 1, -2 };
    CHECK_EQUAL( 1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -2, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart19, Rational )
{
    Rational r{ 3, -3 };
    CHECK_EQUAL( 0, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -3, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart20, Rational )
{
    Rational r{ 5, -4 };
    CHECK_EQUAL( 1, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -4, r.getMixedFractionalPart().getDenominator() )
}
TEST( getMixedFractionalPart21, Rational )
{
    Rational r{ 331, -100 };
    CHECK_EQUAL( 31, r.getMixedFractionalPart().getNumerator() )
    CHECK_EQUAL( -100, r.getMixedFractionalPart().getDenominator() )
}
TEST( getIsIdenticalTo01, Rational )
{
    Rational a{ 1, -2 };
    Rational b{ 1, -2 };
    CHECK( a.getIsIdenticalTo( b ) )
    CHECK( b.getIsIdenticalTo( a ) )
}
TEST( getIsIdenticalTo02, Rational )
{
    Rational a{ 1, -2 };
    Rational b{ 2, -4 };
    CHECK( ! a.getIsIdenticalTo( b ) )
    CHECK( ! b.getIsIdenticalTo( a ) )
}
TEST( comparisons01aEqualsb, Rational )
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
TEST( comparisons01aGreaterThanb, Rational )
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
TEST( comparisons01aLessThanb, Rational )
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
TEST( comparisons02aEqualsb, Rational )
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
TEST( comparisons02aGreaterThanb, Rational )
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
TEST( comparisons02aLessThanb, Rational )
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