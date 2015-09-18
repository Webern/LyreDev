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
TEST( Constructor02, Tuplet )
{
    Tuplet t{ 3, Dur::Eighth, 4, Dur::Sixteenth };
    CHECK_EQUAL( 3, t.getNumerator() )
    CHECK( Dur::Eighth == t.getNumeratorDur() )
    CHECK_EQUAL( 4, t.getDenominator() )
    CHECK( Dur::Sixteenth == t.getDenominatorDur() )
}
TEST( Constructor03, Tuplet )
{
    Tuplet t{ Dur::Half, 7, 6 };
    CHECK_EQUAL( 7, t.getNumerator() )
    CHECK( Dur::Half == t.getNumeratorDur() )
    CHECK_EQUAL( 6, t.getDenominator() )
    CHECK( Dur::Half == t.getDenominatorDur() )
}
TEST( setNumerator, Tuplet )
{
    Tuplet t{ 10, Dur::Longa, 9, Dur::Breve };
    t.setNumerator( 33 );
    CHECK_EQUAL( 33, t.getNumerator() )
    CHECK( Dur::Longa == t.getNumeratorDur() )
    CHECK_EQUAL( 9, t.getDenominator() )
    CHECK( Dur::Breve == t.getDenominatorDur() )
}
TEST( setNumeratorDur, Tuplet )
{
    Tuplet t{ 10, Dur::Longa, 9, Dur::Breve };
    t.setNumeratorDur( Dur::TwoFiftySixth );
    CHECK_EQUAL( 10, t.getNumerator() )
    CHECK( Dur::TwoFiftySixth == t.getNumeratorDur() )
    CHECK_EQUAL( 9, t.getDenominator() )
    CHECK( Dur::Breve == t.getDenominatorDur() )
}
TEST( setDenominator, Tuplet )
{
    Tuplet t{ 10, Dur::Longa, 9, Dur::Breve };
    t.setDenominator( 42 );
    CHECK_EQUAL( 10, t.getNumerator() )
    CHECK( Dur::Longa == t.getNumeratorDur() )
    CHECK_EQUAL( 42, t.getDenominator() )
    CHECK( Dur::Breve == t.getDenominatorDur() )
}
TEST( setDenominatorDur, Tuplet )
{
    Tuplet t{ 10, Dur::Longa, 9, Dur::Breve };
    t.setDenominatorDur( Dur::SixtyFourth );
    CHECK_EQUAL( 10, t.getNumerator() )
    CHECK( Dur::Longa == t.getNumeratorDur() )
    CHECK_EQUAL( 9, t.getDenominator() )
    CHECK( Dur::SixtyFourth == t.getDenominatorDur() )
}

TEST( reminder, Tuplet )
{

    //CHECK_FAIL( "continue writing Tuplet tests" )
}