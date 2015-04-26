#include "TestHarness.h"
#include "Definitions.h"
#include "PitchAlter.h"

using namespace music;

TEST( Test01, PitchAlter )
{
    PitchAlter r;
    CHECK_EQUAL( 0, r.getValue() );
}
TEST( Test02, PitchAlter )
{
    PitchAlter r{ 11 };
    CHECK_EQUAL( 11, r.getValue() );
}
TEST( Test03, PitchAlter )
{
    PitchAlter r{ 13 };
    CHECK_EQUAL( 12, r.getValue() );
}
TEST( Test04, PitchAlter )
{
    PitchAlter r{ -13 };
    r.add( 2 );
    CHECK_EQUAL( -10, r.getValue() );
}
TEST( Test05, PitchAlter )
{
    PitchAlter r{ -9 };
    r.add( -2 );
    CHECK_EQUAL( -11, r.getValue() );
}
TEST( Test06, PitchAlter )
{
    PitchAlter r{ 9 };
    r.subtract( 2 );
    CHECK_EQUAL( 7, r.getValue() );
}
TEST( Test07, PitchAlter )
{
    PitchAlter r{ -9 };
    r.subtract( -2 );
    CHECK_EQUAL( -7, r.getValue() );
}
TEST( Test08, PitchAlter )
{
    PitchAlter r{ 9 };
    r.add( 2 ).add( 2 );
    CHECK_EQUAL( 12, r.getValue() );
}
TEST( Test09, PitchAlter )
{
    PitchAlter r{ -9 };
    r.subtract( 2 ).subtract( 2 );
    CHECK_EQUAL( -12, r.getValue() );
}