#include "cpulTestHarness.h"
#include "DurDot.h"

using namespace lyre;

TEST( Compiles, DurDot )
{
    DurDot dd;
    CHECK( true )
}
TEST( DefaultConstructor, DurDot )
{
    DurDot dd;
    CHECK_EQUAL( 0, dd.getDots() )
    CHECK_EQUAL( Dur::Quarter, dd.getDur() )
}
TEST( Constructor01, DurDot )
{
    DurDot dd{ Dur::Sixteenth };
    CHECK_EQUAL( 0, dd.getDots() )
    CHECK_EQUAL( Dur::Sixteenth, dd.getDur() )
}
TEST( Constructor02, DurDot )
{
    DurDot dd{ Dur::Eighth, 0 };
    CHECK_EQUAL( 0, dd.getDots() )
    CHECK_EQUAL( Dur::Eighth, dd.getDur() )
}
TEST( Constructor03, DurDot )
{
    DurDot dd{ Dur::ThirtySecond, -1 };
    CHECK_EQUAL( 0, dd.getDots() )
    CHECK_EQUAL( Dur::ThirtySecond, dd.getDur() )
}
TEST( Constructor04, DurDot )
{
    DurDot dd{ Dur::Longa, 9999 };
    CHECK_EQUAL( 9999, dd.getDots() )
    CHECK_EQUAL( Dur::Longa, dd.getDur() )
}
TEST( setDots01, DurDot )
{
    DurDot dd{ Dur::TwoFiftySixth, 9999 };
    dd.setDots( 23 );
    CHECK_EQUAL( 23, dd.getDots() )
    CHECK_EQUAL( Dur::TwoFiftySixth, dd.getDur() )
}
TEST( setDots02, DurDot )
{
    DurDot dd{ Dur::Quarter, 9999 };
    dd.setDots( -93 );
    CHECK_EQUAL( 0, dd.getDots() )
    CHECK_EQUAL( Dur::Quarter, dd.getDur() )
}
TEST( setDur01, DurDot )
{
    DurDot dd{ Dur::Half };
    dd.setDur( Dur::Eighth );
    CHECK_EQUAL( 0, dd.getDots() )
    CHECK_EQUAL( Dur::Eighth, dd.getDur() )
}
TEST( setDur02, DurDot )
{
    DurDot dd{ Dur::ThirtySecond, 1 };
    dd.setDur( Dur::Longa );
    CHECK_EQUAL( 1, dd.getDots() )
    CHECK_EQUAL( Dur::Longa, dd.getDur() )
}

TEST( toStream01, DurDot )
{
    DurDot dd{ Dur::ThirtySecond, 1 };
    std::stringstream ss;
    dd.toStream( ss );
    String expected = "[ThirtySecond.]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream02, DurDot )
{
    DurDot dd{ Dur::Half, 3 };
    std::stringstream ss;
    dd.toStream( ss );
    String expected = "[Half...]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream03, DurDot )
{
    DurDot dd{ Dur::Whole };
    std::stringstream ss;
    dd.toStream( ss );
    String expected = "[Whole]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator01, DurDot )
{
    DurDot dd{ Dur::ThirtySecond, 1 };
    std::stringstream ss;
    ss << dd;
    String expected = "[ThirtySecond.]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator02, DurDot )
{
    DurDot dd{ Dur::Half, 3 };
    std::stringstream ss;
    ss << dd;
    String expected = "[Half...]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator03, DurDot )
{
    DurDot dd{ Dur::Whole };
    std::stringstream ss;
    ss << dd;
    String expected = "[Whole]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toString01, DurDot )
{
    DurDot dd{ Dur::ThirtySecond, 1 };
    String expected = "[ThirtySecond.]";
    String actual = dd.toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString02, DurDot )
{
    DurDot dd{ Dur::Half, 3 };
    String expected = "[Half...]";
    String actual = dd.toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString03, DurDot )
{
    DurDot dd{ Dur::Whole };
    String expected = "[Whole]";
    String actual = dd.toString();
    CHECK_EQUAL( expected, actual )
}
TEST( getRational01, DurDot )
{
    auto d = Dur::Half;
    Integer dots = 2;
    DurDot dd{ d, dots };
    auto r = dd.getRational();
    CHECK_EQUAL( 7, r.getNumerator() )
    CHECK_EQUAL( 2, r.getDenominator() )
}
TEST( getRational02, DurDot )
{
    auto d = Dur::Whole;
    Integer dots = 1;
    DurDot dd{ d, dots };
    auto r = dd.getRational();
    CHECK_EQUAL( 6, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
TEST( getRational03, DurDot )
{
    auto d = Dur::Quarter;
    Integer dots = 3;
    DurDot dd{ d, dots };
    auto r = dd.getRational();
    CHECK_EQUAL( 15, r.getNumerator() )
    CHECK_EQUAL( 8, r.getDenominator() )
}
TEST( getRational04, DurDot )
{
    auto d = Dur::Quarter;
    Integer dots = 10;
    DurDot dd{ d, dots };
    auto r = dd.getRational();
    CHECK_EQUAL( 2047, r.getNumerator() )
    CHECK_EQUAL( 1024, r.getDenominator() )
    CHECK_DOUBLES_EQUAL( 2.0, r.getFloat(), 0.01 )
}
TEST( getRational05, DurDot )
{
    Dur d = Dur::Whole;
    DurDot dd{ d };
    Rational r = dd.getRational();
    CHECK_EQUAL( 4, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( getRational06, DurDot )
{
    Dur d = Dur::Half;
    DurDot dd{ d };
    Rational r = dd.getRational();
    CHECK_EQUAL( 2, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( getRational07, DurDot )
{
    Dur d = Dur::Quarter;
    DurDot dd{ d };
    Rational r = dd.getRational();
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( comparisons01, DurDot )
{
    /* a == b */
    DurDot a{ Dur::Quarter, 0 };
    DurDot b{ Dur::Quarter, 0 };
    CHECK(   ( a == b ) );
    CHECK( ! ( a != b ) );
    CHECK( ! ( a <  b ) );
    CHECK( ! ( a >  b ) );
    CHECK(   ( a <= b ) );
    CHECK(   ( a >= b ) );
}
TEST( comparisons02, DurDot )
{
    /* a < b */
    DurDot a{ Dur::Eighth, 0 };
    DurDot b{ Dur::Eighth, 1 };
    CHECK( ! ( a == b ) );
    CHECK(   ( a != b ) );
    CHECK(   ( a <  b ) );
    CHECK( ! ( a >  b ) );
    CHECK(   ( a <= b ) );
    CHECK( ! ( a >= b ) );
}
TEST( comparisons03, DurDot )
{
    /* a > b */
    DurDot a{ Dur::Whole, 0 };
    DurDot b{ Dur::Half, 4 };
    CHECK( ! ( a == b ) );
    CHECK(   ( a != b ) );
    CHECK( ! ( a <  b ) );
    CHECK(   ( a >  b ) );
    CHECK( ! ( a <= b ) );
    CHECK(   ( a >= b ) );
}