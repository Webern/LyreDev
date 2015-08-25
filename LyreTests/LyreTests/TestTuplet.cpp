#include "cpulTestHarness.h"
#include "Tuplet.h"

using namespace lyre;

TEST( Compiles, Tuplet )
{
    Tuplet t;
    CHECK( true )
}
TEST( Constructor01, Tuplet )
{
    Tuplet t;
    CHECK_EQUAL( 1, t.getNumerator() )
    CHECK( Dur::Quarter == t.getNumeratorDur() )
    CHECK_EQUAL( 1, t.getDenominator() )
    CHECK( Dur::Quarter == t.getDenominatorDur() )
}
TEST( note, Tuplet )
{

    CHECK_FAIL( "continue writing Tuplet tests" )
}