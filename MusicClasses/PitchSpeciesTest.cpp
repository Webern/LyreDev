#include "TestHarness.h"
#include "Definitions.h"
#include "PitchSpecies.h"

using namespace music;

TEST( Test01, PitchSpecies )
{
    PitchSpecies x( -1 );
    Integer expected = 11;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test03, PitchSpecies )
{
    PitchSpecies x( -4 );
    Integer expected = 8;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test04, PitchSpecies )
{
    PitchSpecies x( -11 );
    Integer expected = 1;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test05, PitchSpecies )
{
    PitchSpecies x( -12 );
    Integer expected = 0;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test06, PitchSpecies )
{
    PitchSpecies x( -13 );
    Integer expected = 11;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test07, PitchSpecies )
{
    PitchSpecies x( -6 );
    Integer expected = 6;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test02, PitchSpecies )
{
    PitchSpecies x( 12 );
    Integer expected = 0;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test08, PitchSpecies )
{
    PitchSpecies x( 13 );
    Integer expected = 1;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test09, PitchSpecies )
{
    PitchSpecies x( 26 );
    Integer expected = 2;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}