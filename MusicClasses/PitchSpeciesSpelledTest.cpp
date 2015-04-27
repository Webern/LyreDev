#include "TestHarness.h"
#include "Definitions.h"
#include "SpelledPitch.h"

using namespace music;

TEST( Test00, SpelledPitch )
{
    SpelledPitch x{ 0 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::c } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test01, SpelledPitch )
{
    SpelledPitch x{ 1 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::c } )
    CHECK_EQUAL( 1, x.getPitchAlter()->getValue() )
}
TEST( Test02, SpelledPitch )
{
    SpelledPitch x{ 2 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::d } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test03, SpelledPitch )
{
    SpelledPitch x{ 3 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::e } )
    CHECK_EQUAL( -1, x.getPitchAlter()->getValue() )
}
TEST( Test04, SpelledPitch )
{
    SpelledPitch x{ 4 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::e } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test05, SpelledPitch )
{
    SpelledPitch x{ 5 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::f } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test06, SpelledPitch )
{
    SpelledPitch x{ 6 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::f } )
    CHECK_EQUAL( 1, x.getPitchAlter()->getValue() )
}
TEST( Test07, SpelledPitch )
{
    SpelledPitch x{ 7 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::g } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test08, SpelledPitch )
{
    SpelledPitch x{ 8 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::g } )
    CHECK_EQUAL( 1, x.getPitchAlter()->getValue() )
}
TEST( Test09, SpelledPitch )
{
    SpelledPitch x{ 9 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::a } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test10, SpelledPitch )
{
    SpelledPitch x{ 10 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::b } )
    CHECK_EQUAL( -1, x.getPitchAlter()->getValue() )
}
TEST( Test11, SpelledPitch )
{
    SpelledPitch x{ 11 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::b } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test12, SpelledPitch )
{
    SpelledPitch x{ 12 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::c } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}