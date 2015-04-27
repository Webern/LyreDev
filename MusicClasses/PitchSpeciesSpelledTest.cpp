#include "TestHarness.h"
#include "Definitions.h"
#include "PitchSpeciesSpelled.h"

using namespace music;

TEST( Test00, PitchSpeciesSpelled )
{
    PitchSpeciesSpelled x{ 0 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::c } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test01, PitchSpeciesSpelled )
{
    PitchSpeciesSpelled x{ 1 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::c } )
    CHECK_EQUAL( 1, x.getPitchAlter()->getValue() )
}
TEST( Test02, PitchSpeciesSpelled )
{
    PitchSpeciesSpelled x{ 2 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::d } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test03, PitchSpeciesSpelled )
{
    PitchSpeciesSpelled x{ 3 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::e } )
    CHECK_EQUAL( -1, x.getPitchAlter()->getValue() )
}
TEST( Test04, PitchSpeciesSpelled )
{
    PitchSpeciesSpelled x{ 4 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::e } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test05, PitchSpeciesSpelled )
{
    PitchSpeciesSpelled x{ 5 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::f } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test06, PitchSpeciesSpelled )
{
    PitchSpeciesSpelled x{ 6 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::f } )
    CHECK_EQUAL( 1, x.getPitchAlter()->getValue() )
}
TEST( Test07, PitchSpeciesSpelled )
{
    PitchSpeciesSpelled x{ 7 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::g } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test08, PitchSpeciesSpelled )
{
    PitchSpeciesSpelled x{ 8 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::g } )
    CHECK_EQUAL( 1, x.getPitchAlter()->getValue() )
}
TEST( Test09, PitchSpeciesSpelled )
{
    PitchSpeciesSpelled x{ 9 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::a } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test10, PitchSpeciesSpelled )
{
    PitchSpeciesSpelled x{ 10 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::b } )
    CHECK_EQUAL( -1, x.getPitchAlter()->getValue() )
}
TEST( Test11, PitchSpeciesSpelled )
{
    PitchSpeciesSpelled x{ 11 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::b } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test12, PitchSpeciesSpelled )
{
    PitchSpeciesSpelled x{ 12 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::c } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}