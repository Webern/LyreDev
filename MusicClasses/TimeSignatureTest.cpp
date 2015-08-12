#include "TestHarness.h"
#include "TimeSignature.h"

using namespace music;

TEST( Constructor01, TimeSignature )
{
    TimeSignature x;
    CHECK_EQUAL( 4, x.getBeatCount() )
    CHECK( Rational( 1, 1 ) == x.getBeatDuration().getRational() )
}
TEST( Costructor02, TimeSignature )
{
    /* continue testing TimeSignature, then
     continue writing tests alphebetically
     starting with MeasureTest.cpp */
    CHECK( false )
}