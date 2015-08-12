#include "TestHarness.h"
#include "Definitions.h"
#include "PitchSpecies.h"
#include "PitchStep.h"
#include "PitchAlter.h"

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
TEST( Test10, PitchSpecies )
{
    PitchSpecies x( 12 );
    x.setValue( 13 );
    Integer expected = 1;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test11, PitchSpecies )
{
    PitchSpecies x( 0 );
    x.setValue( 10 );
    Integer expected = 10;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test12, PitchSpecies )
{
    PitchSpecies x( 26 );
    x.setValue( -4 );
    Integer expected = 8;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test13, PitchSpecies )
{
    PitchSpecies x( 4 );
    x.add( 4 );
    Integer expected = 8;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test14, PitchSpecies )
{
    PitchSpecies x( 11 );
    x.add( 4 );
    Integer expected = 3;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test15, PitchSpecies )
{
    PitchSpecies x( 1 );
    x.add( -12 );
    Integer expected = 1;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test16, PitchSpecies )
{
    PitchSpecies x( 4 );
    x.subtract( 4 );
    Integer expected = 0;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test17, PitchSpecies )
{
    PitchSpecies x( 11 );
    x.subtract( 4 );
    Integer expected = 7;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test18, PitchSpecies )
{
    PitchSpecies x( 1 );
    x.subtract( -10 );
    Integer expected = 11;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
}
TEST( Test19, PitchSpecies )
{
    PitchSpecies x( 1 );
    PitchSpecies ret = ++x;
    Integer expected = 2;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 2, ret.getValue() )
}
TEST( Test20, PitchSpecies )
{
    PitchSpecies x( 1 );
    PitchSpecies ret = x++;
    Integer expected = 2;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 1, ret.getValue() )
}
TEST( Test21, PitchSpecies )
{
    PitchSpecies x( 10 );
    PitchSpecies ret = --x;
    Integer expected = 9;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 9, ret.getValue() )
}
TEST( Test22, PitchSpecies )
{
    PitchSpecies x( 7 );
    PitchSpecies ret = x--;
    Integer expected = 6;
    Integer actual = x.getValue();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 7, ret.getValue() )
}

TEST( Test29, PitchSpecies )
{
    PitchSpeciesPtr p = PitchSpecies::make();
    CHECK_EQUAL( 0, p->getValue() )
}

TEST( Test30, PitchSpecies )
{
    PitchSpeciesPtr p = PitchSpecies::make( 7 );
    CHECK_EQUAL( 7, p->getValue() )
}

TEST( Test31, PitchSpecies )
{
    PitchSpecies x{ 1 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::c } )
    CHECK_EQUAL( 1, x.getPitchAlter()->getValue() )
}
TEST( Test32, PitchSpecies )
{
    PitchSpecies x{ 2 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::d } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test33, PitchSpecies )
{
    PitchSpecies x{ 3 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::e } )
    CHECK_EQUAL( -1, x.getPitchAlter()->getValue() )
}
TEST( Test34, PitchSpecies )
{
    PitchSpecies x{ 4 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::e } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test35, PitchSpecies )
{
    PitchSpecies x{ 5 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::f } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test36, PitchSpecies )
{
    PitchSpecies x{ 6 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::f } )
    CHECK_EQUAL( 1, x.getPitchAlter()->getValue() )
}
TEST( Test37, PitchSpecies )
{
    PitchSpecies x{ 7 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::g } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test38, PitchSpecies )
{
    PitchSpecies x{ 8 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::g } )
    CHECK_EQUAL( 1, x.getPitchAlter()->getValue() )
}
TEST( Test39, PitchSpecies )
{
    PitchSpecies x{ 9 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::a } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test40, PitchSpecies )
{
    PitchSpecies x{ 10 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::b } )
    CHECK_EQUAL( -1, x.getPitchAlter()->getValue() )
}
TEST( Test41, PitchSpecies )
{
    PitchSpecies x{ 11 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::b } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test42, PitchSpecies )
{
    PitchSpecies x{ 12 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::c } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}
TEST( Test43, PitchSpecies )
{
    PitchSpecies x{ 0 };
    CHECK( (*x.getPitchStep()) == PitchStep{ PitchStepName::c } )
    CHECK_EQUAL( 0, x.getPitchAlter()->getValue() )
}