//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/IDurDotFactory.h"
#include "Lyre/IDurDot.h"

using namespace Lyre;
using namespace std;

namespace
{
    IDurDotFactoryUP factory() { return createDurDotFactory( DurDotFactoryType::Standard ); }
}

TEST( testSetupWorks, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Quarter", 0 );
    CHECK( factory != nullptr )
    CHECK( dur != nullptr )
}
T_END

TEST( constructorA_1, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Quarter", 1 );
    CHECK_EQUAL( 1, dur->getDotCount() )
    CHECK_EQUAL( Rational( 1, 1 ), dur->getDurBaseValue() )
}
T_END

TEST( constructorA_2, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Eighth", 0 );
    CHECK_EQUAL( 0, dur->getDotCount() )
    CHECK_EQUAL( Rational( 1, 2 ), dur->getDurBaseValue() )
}
T_END

TEST( constructorA_3_InvalidDotInput, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Eighth", -1 );
    CHECK_EQUAL( 0, dur->getDotCount() )
    CHECK_EQUAL( Rational( 1, 2 ), dur->getDurBaseValue() )
}
T_END

TEST( constructorA_4_InvalidDurName, IDurDot )
{
    String expected = "not a valid DurBase name";
    String actual = "no exception was thrown";
    try
    {
        IDurDotUP dur = factory()->createDurDot( "X", 0 );
    }
    catch (std::runtime_error& e)
    {
        actual = String{ e.what() };
    }
    CHECK( actual.find( expected ) != String::npos )
}
T_END

TEST( constructorB_1, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Quarter" );
    CHECK_EQUAL( 0, dur->getDotCount() )
    CHECK_EQUAL( Rational( 1, 1 ), dur->getDurBaseValue() )
}
T_END

TEST( constructorB_2, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Eighth" );
    CHECK_EQUAL( 0, dur->getDotCount() )
    CHECK_EQUAL( Rational( 1, 2 ), dur->getDurBaseValue() )
}
T_END

TEST( constructorB_3_InvalidDurName, IDurDot )
{
    String expected = "not a valid DurBase name";
    String actual = "no exception was thrown";
    try
    {
        IDurDotUP dur = factory()->createDurDot( "X" );
    }
    catch (std::runtime_error& e)
    {
        actual = String{ e.what() };
    }
    CHECK( actual.find( expected ) != String::npos )
}
T_END

TEST( setDotsInvalid, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Eighth", 1 );
    CHECK_EQUAL( 1, dur->getDotCount() )
    dur->setDotCount( -1 );
    CHECK_EQUAL( 0, dur->getDotCount() )
}
T_END

TEST( setDotsValid, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Eighth", 1 );
    CHECK_EQUAL( 1, dur->getDotCount() )
    dur->setDotCount( 2 );
    CHECK_EQUAL( 2, dur->getDotCount() )
}
T_END

TEST( getValue_noDots, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Eighth", 0 );
    Rational expected{ 1, 2 };
    Rational actual = dur->getValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getValue_with1Dot, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Eighth", 1 );
    Rational expected{ 3, 4 };
    Rational actual = dur->getValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getValue_with2Dots, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Eighth", 2 );
    Rational expected{ 7, 8 };
    Rational actual = dur->getValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getValue_with3Dots, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Eighth", 3 );
    Rational expected{ 15, 16 };
    Rational actual = dur->getValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getValue_with4Dots, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Eighth", 4 );
    Rational expected{ 31, 32 };
    Rational actual = dur->getValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getValue_withMaxDots, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Quarter", DURATION_MAX_DOTS );
    Float expected = 1.9999999999999;
    Float actual = dur->getValue().getFloat();
    CHECK_DOUBLES_EQUAL( expected, actual, 0.0001 )
}
T_END

TEST( getValue_withTooManyDots, IDurDot )
{
    int tooManyDots = DURATION_MAX_DOTS + 1;
    String expected = "too many dots";
    String actual = "no exception was thrown";
    try
    {
        IDurDotUP dur = factory()->createDurDot( "Quarter" );
        dur->setDotCount( tooManyDots );
    }
    catch (std::runtime_error& e)
    {
        actual = String{ e.what() };
    }
    CHECK( actual.find( expected ) != String::npos )
}
T_END

TEST( clone, IDurDot )
{
    IDurDotUP orig = factory()->createDurDot( "Half", 1 );
    IDurDotUP cloned = orig->clone();
    orig->setDotCount( 2 );
    cloned->setDotCount( 3 );
    CHECK( orig != nullptr )
    CHECK( cloned != nullptr )
    CHECK( orig.get() != cloned.get() )
    CHECK_EQUAL( 2, orig->getDotCount() )
    CHECK_EQUAL( 3, cloned->getDotCount() )
}
T_END

TEST( toStream, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Half", 1 );
    stringstream ss;
    dur->toStream( ss );
    String expected = "Half.";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "Whole", 0 );
    String expected = "Whole";
    String actual = dur->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "64th", 7 );
    stringstream ss;
    ss << ( *dur );
    String expected = "64th.......";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getDurBaseName, IDurDot )
{
    IDurDotUP dur = factory()->createDurDot( "32nd", 2 );
    String expected = "32nd..";
    String actual = dur->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( isEqualTo1, IDurDot )
{
    auto durA = factory()->createDurDot( "16th", 1 );
    auto durB = factory()->createDurDot( "16th", 1 );
    CHECK(   durA->isEqualTo( *durB ) )
    CHECK(   durB->isEqualTo( *durA ) )
    CHECK( ! durA->isGreaterThan( *durB ) )
    CHECK( ! durB->isGreaterThan( *durA ) )
    CHECK( ! durA->isLessThan( *durB ) )
    CHECK( ! durB->isLessThan( *durA ) )
    
    CHECK(   ( *durA == *durB ) )
    CHECK(   ( *durB == *durA ) )
    CHECK( ! ( *durA != *durB ) )
    CHECK( ! ( *durB != *durA ) )
    CHECK(   ( *durA >= *durB ) )
    CHECK(   ( *durB >= *durA ) )
    CHECK(   ( *durA <= *durB ) )
    CHECK(   ( *durB <= *durA ) )
    CHECK( ! ( *durA > *durB ) )
    CHECK( ! ( *durB > *durA ) )
    CHECK( ! ( *durA < *durB ) )
    CHECK( ! ( *durB < *durA ) )
}
T_END

TEST( isEqualTo2, IDurDot )
{
    auto durA = factory()->createDurDot( "Whole", 0 );
    auto durB = factory()->createDurDot( "Whole", 0 );
    CHECK(   durA->isEqualTo( *durB ) )
    CHECK(   durB->isEqualTo( *durA ) )
    CHECK( ! durA->isGreaterThan( *durB ) )
    CHECK( ! durB->isGreaterThan( *durA ) )
    CHECK( ! durA->isLessThan( *durB ) )
    CHECK( ! durB->isLessThan( *durA ) )
    
    CHECK(   ( *durA == *durB ) )
    CHECK(   ( *durB == *durA ) )
    CHECK( ! ( *durA != *durB ) )
    CHECK( ! ( *durB != *durA ) )
    CHECK(   ( *durA >= *durB ) )
    CHECK(   ( *durB >= *durA ) )
    CHECK(   ( *durA <= *durB ) )
    CHECK(   ( *durB <= *durA ) )
    CHECK( ! ( *durA > *durB ) )
    CHECK( ! ( *durB > *durA ) )
    CHECK( ! ( *durA < *durB ) )
    CHECK( ! ( *durB < *durA ) )
}
T_END

TEST( isGreaterThan, IDurDot )
{
    auto durA = factory()->createDurDot( "Eighth", 2 );
    auto durB = factory()->createDurDot( "Eighth", 1 );
    CHECK( ! durA->isEqualTo( *durB ) )
    CHECK( ! durB->isEqualTo( *durA ) )
    CHECK(   durA->isGreaterThan( *durB ) )
    CHECK( ! durB->isGreaterThan( *durA ) )
    CHECK( ! durA->isLessThan( *durB ) )
    CHECK(   durB->isLessThan( *durA ) )
    
    CHECK( ! ( *durA == *durB ) )
    CHECK( ! ( *durB == *durA ) )
    CHECK(   ( *durA != *durB ) )
    CHECK(   ( *durB != *durA ) )
    CHECK(   ( *durA >= *durB ) )
    CHECK( ! ( *durB >= *durA ) )
    CHECK( ! ( *durA <= *durB ) )
    CHECK(   ( *durB <= *durA ) )
    CHECK(   ( *durA > *durB ) )
    CHECK( ! ( *durB > *durA ) )
    CHECK( ! ( *durA < *durB ) )
    CHECK(   ( *durB < *durA ) )
}
T_END

TEST( isLessThan, IDurDot )
{
    auto durA = factory()->createDurDot( "32nd", 0 );
    auto durB = factory()->createDurDot( "Quarter", 0 );
    CHECK( ! durA->isEqualTo( *durB ) )
    CHECK( ! durB->isEqualTo( *durA ) )
    CHECK( ! durA->isGreaterThan( *durB ) )
    CHECK(   durB->isGreaterThan( *durA ) )
    CHECK(   durA->isLessThan( *durB ) )
    CHECK( ! durB->isLessThan( *durA ) )
    
    CHECK( ! ( *durA == *durB ) )
    CHECK( ! ( *durB == *durA ) )
    CHECK(   ( *durA != *durB ) )
    CHECK(   ( *durB != *durA ) )
    CHECK( ! ( *durA >= *durB ) )
    CHECK(   ( *durB >= *durA ) )
    CHECK(   ( *durA <= *durB ) )
    CHECK( ! ( *durB <= *durA ) )
    CHECK( ! ( *durA > *durB ) )
    CHECK(   ( *durB > *durA ) )
    CHECK(   ( *durA < *durB ) )
    CHECK( ! ( *durB < *durA ) )
}
T_END
