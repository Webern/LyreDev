#include "TestHarness.h"
#include "Step.h"

using namespace music;

TEST( Constructor01, Step )
{
    Step s;
    CHECK_EQUAL( 0, s.getValue() )
}
TEST( Constructor02, Step )
{
    Step s( StepName::D );
    CHECK_EQUAL( 1, s.getValue() )
}
TEST( Constructor03, Step )
{
    Step s( 12 );
    CHECK_EQUAL( 5, s.getValue() )
}
TEST( setValue01, Step )
{
    Step s{ 3 };
    CHECK_EQUAL( 3, s.getValue() )
    s.setValue( 4 );
    CHECK_EQUAL( 4, s.getValue() )
    s.setValue( StepName::A );
    CHECK_EQUAL( 5, s.getValue() )
}
TEST( getStepName01, Step )
{
    Step s{ 3 };
    CHECK( StepName::F == s.getStepName() )
    s.setValue( 4 );
    CHECK( StepName::G == s.getStepName() )
    s.setValue( StepName::A );
    CHECK( StepName::A == s.getStepName() )
}
TEST( operatorInt01, Step )
{
    Step s{ 3 };
    Int val3 = s;
    CHECK_EQUAL( 3 , val3 )
    s.setValue( 4 );
    Int val4 = s;
    CHECK_EQUAL( 4 , val4 )
    s.setValue( StepName::A );
    Int val5 = s;
    CHECK_EQUAL( 5 , val5 )
}
TEST( operatorPlusPlus_post, Step )
{
    Step s0{ 3 };
    auto s1 = s0++;
    CHECK_EQUAL( 3, s1.getValue() )
    CHECK_EQUAL( 4, s0.getValue() )
    s1 = s0++;
    CHECK_EQUAL( 4, s1.getValue() )
    CHECK_EQUAL( 5, s0.getValue() )
    s1 = s0++;
    CHECK_EQUAL( 5, s1.getValue() )
    CHECK_EQUAL( 6, s0.getValue() )
    s1 = s0++;
    CHECK_EQUAL( 6, s1.getValue() )
    CHECK_EQUAL( 0, s0.getValue() )
}
TEST( operatorMinusMinus_post, Step )
{
    Step s0{ 3 };
    auto s1 = s0--;
    CHECK_EQUAL( 3, s1.getValue() )
    CHECK_EQUAL( 2, s0.getValue() )
    s1 = s0--;
    CHECK_EQUAL( 2, s1.getValue() )
    CHECK_EQUAL( 1, s0.getValue() )
    s1 = s0--;
    CHECK_EQUAL( 1, s1.getValue() )
    CHECK_EQUAL( 0, s0.getValue() )
    s1 = s0--;
    CHECK_EQUAL( 0, s1.getValue() )
    CHECK_EQUAL( 6, s0.getValue() )
}
TEST( operatorPlusPlus_pre, Step )
{
    Step s0{ 3 };
    auto s1 = ++s0;
    CHECK_EQUAL( 4, s1.getValue() )
    CHECK_EQUAL( 4, s0.getValue() )
    s1 = ++s0;
    CHECK_EQUAL( 5, s1.getValue() )
    CHECK_EQUAL( 5, s0.getValue() )
    s1 = ++s0;
    CHECK_EQUAL( 6, s1.getValue() )
    CHECK_EQUAL( 6, s0.getValue() )
    s1 = ++s0;
    CHECK_EQUAL( 0, s1.getValue() )
    CHECK_EQUAL( 0, s0.getValue() )
}
TEST( operatorMinusMinus_pre, Step )
{
    Step s0{ 3 };
    auto s1 = --s0;
    CHECK_EQUAL( 2, s1.getValue() )
    CHECK_EQUAL( 2, s0.getValue() )
    s1 = --s0;
    CHECK_EQUAL( 1, s1.getValue() )
    CHECK_EQUAL( 1, s0.getValue() )
    s1 = --s0;
    CHECK_EQUAL( 0, s1.getValue() )
    CHECK_EQUAL( 0, s0.getValue() )
    s1 = --s0;
    CHECK_EQUAL( 6, s1.getValue() )
    CHECK_EQUAL( 6, s0.getValue() )
}
TEST( add, Step )
{
    Step s0{ 3 };
    auto s1 = s0.add( 3 );
    CHECK_EQUAL( 6, s1.getValue() )
    CHECK_EQUAL( 6, s0.getValue() )
    s1 = s0.add( 3 );
    CHECK_EQUAL( 2, s1.getValue() )
    CHECK_EQUAL( 2, s0.getValue() )
    s1 = s0.add( 8 );
    CHECK_EQUAL( 3, s1.getValue() )
    CHECK_EQUAL( 3, s0.getValue() )
}
TEST( subtract, Step )
{
    Step s0{ 3 };
    auto s1 = s0.subtract( 3 );
    CHECK_EQUAL( 0, s1.getValue() )
    CHECK_EQUAL( 0, s0.getValue() )
    s1 = s0.subtract( 3 );
    CHECK_EQUAL( 4, s1.getValue() )
    CHECK_EQUAL( 4, s0.getValue() )
    s1 = s0.subtract( 8 );
    CHECK_EQUAL( 3, s1.getValue() )
    CHECK_EQUAL( 3, s0.getValue() )
}
TEST( Comparisons01, Step )
{
    Step greater{ 3 };
    Step lesser{ 2 };
    CHECK( ! ( greater == lesser ) )
    CHECK(   ( greater != lesser ) )
    CHECK( ! ( greater <  lesser ) )
    CHECK(   ( greater >  lesser ) )
    CHECK( ! ( greater <= lesser ) )
    CHECK(   ( greater >= lesser ) )
}
TEST( Comparisons02, Step )
{
    Step greater{ 3 };
    Step lesser{ 2 };
    CHECK( ! ( lesser == greater ) )
    CHECK(   ( lesser != greater ) )
    CHECK(   ( lesser <  greater ) )
    CHECK( ! ( lesser >  greater ) )
    CHECK(   ( lesser <= greater ) )
    CHECK( ! ( lesser >= greater ) )
}
TEST( Comparisons03, Step )
{
    Step equal{ 3 };
    CHECK(   ( equal == equal ) )
    CHECK( ! ( equal != equal ) )
    CHECK( ! ( equal <  equal ) )
    CHECK( ! ( equal >  equal ) )
    CHECK(   ( equal <= equal ) )
    CHECK(   ( equal >= equal ) )
}