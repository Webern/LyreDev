#include "TestHarness.h"
#include "Definitions.h"
#include "PitchStep.h"

using namespace music;

TEST( Test01, PitchStep )
{
    PitchStep x( -1 );
    Integer expected = 6;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test03, PitchStep )
{
    PitchStep x( -4 );
    Integer expected = 3;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test04, PitchStep )
{
    PitchStep x( -11 );
    Integer expected = 3;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test05, PitchStep )
{
    PitchStep x( -7 );
    Integer expected = 0;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test06, PitchStep )
{
    PitchStep x( -8 );
    Integer expected = 6;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test07, PitchStep )
{
    PitchStep x( -6 );
    Integer expected = 1;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test02, PitchStep )
{
    PitchStep x( 7 );
    Integer expected = 0;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test08, PitchStep )
{
    PitchStep x( 13 );
    Integer expected = 6;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test09, PitchStep )
{
    PitchStep x( 16 );
    Integer expected = 2;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test10, PitchStep )
{
    PitchStep x( 12 );
    x.setValue( 8 );
    Integer expected = 1;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test11, PitchStep )
{
    PitchStep x( 0 );
    x.setValue( 6 );
    Integer expected = 6;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test12, PitchStep )
{
    PitchStep x( 26 );
    x.setValue( -4 );
    Integer expected = 3;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test13, PitchStep )
{
    PitchStep x( 4 );
    x.add( 2 );
    Integer expected = 6;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test14, PitchStep )
{
    PitchStep x( 6 );
    x.add( 4 );
    Integer expected = 3;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test15, PitchStep )
{
    PitchStep x( 1 );
    x.add( -7 );
    Integer expected = 1;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test16, PitchStep )
{
    PitchStep x( 4 );
    x.subtract( 4 );
    Integer expected = 0;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test17, PitchStep )
{
    PitchStep x( 6 );
    x.subtract( 4 );
    Integer expected = 2;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test18, PitchStep )
{
    PitchStep x( 1 );
    x.subtract( -8 );
    Integer expected = 2;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test19, PitchStep )
{
    PitchStep x( 1 );
    PitchStep ret = ++x;
    Integer expected = 2;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 2, ret.getValue() )
}
TEST( Test20, PitchStep )
{
    PitchStep x( 1 );
    PitchStep ret = x++;
    Integer expected = 2;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 1, ret.getValue() )
}
TEST( Test21, PitchStep )
{
    PitchStep x( 10 );
    PitchStep ret = --x;
    Integer expected = 2;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 2, ret.getValue() )
}
TEST( Test22, PitchStep )
{
    PitchStep x( 7 );
    PitchStep ret = x--;
    Integer expected = 6;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 0, ret.getValue() )
}
TEST( Test23, PitchStep )
{
    PitchStep x( 4 );
    PitchStep y( 4 );
    PitchStep z( 5 );
    CHECK( x == y );
    CHECK( ! (x == z ) );
}
TEST( Test24, PitchStep )
{
    PitchStep x( 4 );
    PitchStep y( 4 );
    PitchStep z( 5 );
    CHECK( ! (x != y ) );
    CHECK( x != z );
}
TEST( Test25, PitchStep )
{
    PitchStep w( 3 );
    PitchStep x( 4 );
    PitchStep y( 4 );
    PitchStep z( 5 );
    CHECK( ! ( w >= x ) )
    CHECK( x >= y )
    CHECK( z >= y )
}
TEST( Test26, PitchStep )
{
    PitchStep w( 3 );
    PitchStep x( 4 );
    PitchStep y( 4 );
    PitchStep z( 5 );
    CHECK( w <= x )
    CHECK( x <= y )
    CHECK( ! ( z <= y ) )
}

TEST( Test27, PitchStep )
{
    PitchStep w( 3 );
    PitchStep x( 4 );
    PitchStep y( 4 );
    PitchStep z( 5 );
    CHECK( ! ( w > x ) )
    CHECK( ! ( x > y ) )
    CHECK( z > y )
}
TEST( Test28, PitchStep )
{
    PitchStep w( 3 );
    PitchStep x( 4 );
    PitchStep y( 4 );
    PitchStep z( 5 );
    CHECK( w < x )
    CHECK( ! ( x < y ) )
    CHECK( ! ( z < y ) )
}

TEST( Test29, PitchStep )
{
    PitchStepPtr x = PitchStep::make( -1 );
    auto expected = 11;
    auto actual = x->getPitchSpeciesEquivalent();
    CHECK_EQUAL( expected, actual )
}
TEST( Test30, PitchStep )
{
    PitchStepPtr x = PitchStep::make( 0 );
    auto expected = 0;
    auto actual = x->getPitchSpeciesEquivalent();
    CHECK_EQUAL( expected, actual )
}
TEST( Test31, PitchStep )
{
    PitchStepPtr x = PitchStep::make( 1 );
    auto expected = 2;
    auto actual = x->getPitchSpeciesEquivalent();
    CHECK_EQUAL( expected, actual )
}
TEST( Test32, PitchStep )
{
    PitchStepPtr x = PitchStep::make( 2 );
    auto expected = 4;
    auto actual = x->getPitchSpeciesEquivalent();
    CHECK_EQUAL( expected, actual )
}
TEST( Test33, PitchStep )
{
    PitchStepPtr x = PitchStep::make( 3 );
    auto expected = 5;
    auto actual = x->getPitchSpeciesEquivalent();
    CHECK_EQUAL( expected, actual )}
TEST( Test34, PitchStep )
{
    PitchStepPtr x = PitchStep::make( 4 );
    auto expected = 7;
    auto actual = x->getPitchSpeciesEquivalent();
    CHECK_EQUAL( expected, actual )
}
TEST( Test35, PitchStep )
{
    PitchStepPtr x = PitchStep::make( 5 );
    auto expected = 8;
    auto actual = x->getPitchSpeciesEquivalent();
    CHECK_EQUAL( expected, actual )
}
TEST( Test36, PitchStep )
{
    PitchStepPtr x = PitchStep::make( 6 );
    auto expected = 11;
    auto actual = x->getPitchSpeciesEquivalent();
    CHECK_EQUAL( expected, actual )
}
TEST( Test37, PitchStep )
{
    PitchStepPtr x = PitchStep::make( 7 );
    auto expected = 0;
    auto actual = x->getPitchSpeciesEquivalent();
    CHECK_EQUAL( expected, actual )
}