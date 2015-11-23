//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"

using namespace Lyre;
using namespace std;

namespace
{
    IDurationFactoryUP factory() { return createDurationFactory( DurationFactoryType::Standard ); }
}

TEST( testSetupWorks, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Quarter", 0 );
    CHECK( factory != nullptr )
    CHECK( dur != nullptr )
}

TEST( constructorA_1, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Quarter", 1 );
    CHECK_EQUAL( 1, dur->getDotCount() )
    CHECK_EQUAL( Rational( 1, 1 ), dur->getDurBaseValue() )
}

TEST( constructorA_2, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Eighth", 0 );
    CHECK_EQUAL( 0, dur->getDotCount() )
    CHECK_EQUAL( Rational( 1, 2 ), dur->getDurBaseValue() )
}

TEST( constructorA_3_InvalidDotInput, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Eighth", -1 );
    CHECK_EQUAL( 0, dur->getDotCount() )
    CHECK_EQUAL( Rational( 1, 2 ), dur->getDurBaseValue() )
}

TEST( constructorA_4_InvalidDurName, IDuration )
{
    String expected = "not a valid DurBase name";
    String actual = "no exception was thrown";
    try
    {
        IDurationUP dur = factory()->createDuration( "X", 0 );
    }
    catch (std::runtime_error& e)
    {
        actual = String{ e.what() };
    }
    CHECK( actual.find( expected ) != String::npos )
}

TEST( constructorB_1, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Quarter" );
    CHECK_EQUAL( 0, dur->getDotCount() )
    CHECK_EQUAL( Rational( 1, 1 ), dur->getDurBaseValue() )
}

TEST( constructorB_2, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Eighth" );
    CHECK_EQUAL( 0, dur->getDotCount() )
    CHECK_EQUAL( Rational( 1, 2 ), dur->getDurBaseValue() )
}

TEST( constructorB_3_InvalidDurName, IDuration )
{
    String expected = "not a valid DurBase name";
    String actual = "no exception was thrown";
    try
    {
        IDurationUP dur = factory()->createDuration( "X" );
    }
    catch (std::runtime_error& e)
    {
        actual = String{ e.what() };
    }
    CHECK( actual.find( expected ) != String::npos )
}

TEST( setDotsInvalid, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Eighth", 1 );
    CHECK_EQUAL( 1, dur->getDotCount() )
    dur->setDotCount( -1 );
    CHECK_EQUAL( 0, dur->getDotCount() )
}

TEST( setDotsValid, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Eighth", 1 );
    CHECK_EQUAL( 1, dur->getDotCount() )
    dur->setDotCount( 2 );
    CHECK_EQUAL( 2, dur->getDotCount() )
}

TEST( getValue_noDots, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Eighth", 0 );
    Rational expected{ 1, 2 };
    Rational actual = dur->getValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getValue_with1Dot, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Eighth", 1 );
    Rational expected{ 3, 4 };
    Rational actual = dur->getValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getValue_with2Dots, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Eighth", 2 );
    Rational expected{ 7, 8 };
    Rational actual = dur->getValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getValue_with3Dots, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Eighth", 3 );
    Rational expected{ 15, 16 };
    Rational actual = dur->getValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getValue_with4Dots, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Eighth", 4 );
    Rational expected{ 31, 32 };
    Rational actual = dur->getValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getValue_withMaxDots, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Quarter", DURATION_MAX_DOTS );
    Float expected = 1.9999999999999;
    Float actual = dur->getValue().getFloat();
    CHECK_DOUBLES_EQUAL( expected, actual, 0.0001 )
}

TEST( getValue_withTooManyDots, IDuration )
{
    Integer tooManyDots = DURATION_MAX_DOTS + 1;
    String expected = "too many dots";
    String actual = "no exception was thrown";
    try
    {
        IDurationUP dur = factory()->createDuration( "Quarter" );
        dur->setDotCount( tooManyDots );
    }
    catch (std::runtime_error& e)
    {
        actual = String{ e.what() };
    }
    CHECK( actual.find( expected ) != String::npos )
}

TEST( clone, IDuration )
{
    IDurationUP orig = factory()->createDuration( "Half", 1 );
    IDurationUP cloned = orig->clone();
    orig->setDotCount( 2 );
    cloned->setDotCount( 3 );
    CHECK( orig != nullptr )
    CHECK( cloned != nullptr )
    CHECK( orig.get() != cloned.get() )
    CHECK_EQUAL( 2, orig->getDotCount() )
    CHECK_EQUAL( 3, cloned->getDotCount() )
}

TEST( copyTo, IDuration )
{
    IDurationUP orig = factory()->createDuration( "Half", 1 );
    IDurationUP copied;
    orig->copyTo( copied );
    orig->setDotCount( 2 );
    copied->setDotCount( 3 );
    CHECK( orig != nullptr )
    CHECK( copied != nullptr )
    CHECK( orig.get() != copied.get() )
    CHECK_EQUAL( 2, orig->getDotCount() )
    CHECK_EQUAL( 3, copied->getDotCount() )
}

TEST( toStream, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Half", 1 );
    stringstream ss;
    dur->toStream( ss );
    String expected = "Half.";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}

TEST( toString, IDuration )
{
    IDurationUP dur = factory()->createDuration( "Whole", 0 );
    String expected = "Whole";
    String actual = dur->toString();
    CHECK_EQUAL( expected, actual )
}

TEST( streamingOperator, IDuration )
{
    IDurationUP dur = factory()->createDuration( "64th", 7 );
    stringstream ss;
    ss << ( *dur );
    String expected = "64th.......";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}

TEST( durBaseToString, IDuration )
{
    IDurationUP dur = factory()->createDuration( "32nd", 2 );
    String expected = "32nd..";
    String actual = dur->toString();
    CHECK_EQUAL( expected, actual )
}

TEST( isEqualTo1, IDuration )
{
    auto durA = factory()->createDuration( "16th", 1 );
    auto durB = factory()->createDuration( "16th", 1 );
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

TEST( isEqualTo2, IDuration )
{
    auto durA = factory()->createDuration( "Whole", 0 );
    auto durB = factory()->createDuration( "Whole", 0 );
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

TEST( isGreaterThan, IDuration )
{
    auto durA = factory()->createDuration( "Eighth", 2 );
    auto durB = factory()->createDuration( "Eighth", 1 );
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

TEST( isLessThan, IDuration )
{
    auto durA = factory()->createDuration( "32nd", 0 );
    auto durB = factory()->createDuration( "Quarter", 0 );
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
