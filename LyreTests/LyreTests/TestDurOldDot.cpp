//PUBLIC
#include "cpulTestHarness.h"
#include "DurOldDot.h"

using namespace lyre;

TEST( Compiles, DurOldDot )
{
    DurOldDot dd;
    CHECK( true )
}
TEST( DefaultConstructor, DurOldDot )
{
    DurOldDot dd;
    CHECK_EQUAL( 0, dd.getDots() )
    CHECK_EQUAL( DurOld::Quarter, dd.getDurOld() )
}
TEST( Constructor01, DurOldDot )
{
    DurOldDot dd{ DurOld::Sixteenth };
    CHECK_EQUAL( 0, dd.getDots() )
    CHECK_EQUAL( DurOld::Sixteenth, dd.getDurOld() )
}
TEST( Constructor02, DurOldDot )
{
    DurOldDot dd{ DurOld::Eighth, 0 };
    CHECK_EQUAL( 0, dd.getDots() )
    CHECK_EQUAL( DurOld::Eighth, dd.getDurOld() )
}
TEST( Constructor03, DurOldDot )
{
    DurOldDot dd{ DurOld::ThirtySecond, -1 };
    CHECK_EQUAL( 0, dd.getDots() )
    CHECK_EQUAL( DurOld::ThirtySecond, dd.getDurOld() )
}
TEST( Constructor04, DurOldDot )
{
    DurOldDot dd{ DurOld::Longa, 9999 };
    CHECK_EQUAL( 9999, dd.getDots() )
    CHECK_EQUAL( DurOld::Longa, dd.getDurOld() )
}
TEST( setDots01, DurOldDot )
{
    DurOldDot dd{ DurOld::TwoFiftySixth, 9999 };
    dd.setDots( 23 );
    CHECK_EQUAL( 23, dd.getDots() )
    CHECK_EQUAL( DurOld::TwoFiftySixth, dd.getDurOld() )
}
TEST( setDots02, DurOldDot )
{
    DurOldDot dd{ DurOld::Quarter, 9999 };
    dd.setDots( -93 );
    CHECK_EQUAL( 0, dd.getDots() )
    CHECK_EQUAL( DurOld::Quarter, dd.getDurOld() )
}
TEST( setDurOld01, DurOldDot )
{
    DurOldDot dd{ DurOld::Half };
    dd.setDurOld( DurOld::Eighth );
    CHECK_EQUAL( 0, dd.getDots() )
    CHECK_EQUAL( DurOld::Eighth, dd.getDurOld() )
}
TEST( setDurOld02, DurOldDot )
{
    DurOldDot dd{ DurOld::ThirtySecond, 1 };
    dd.setDurOld( DurOld::Longa );
    CHECK_EQUAL( 1, dd.getDots() )
    CHECK_EQUAL( DurOld::Longa, dd.getDurOld() )
}

TEST( toStream01, DurOldDot )
{
    DurOldDot dd{ DurOld::ThirtySecond, 1 };
    std::stringstream ss;
    dd.toStream( ss );
    String expected = "[ThirtySecond.]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream02, DurOldDot )
{
    DurOldDot dd{ DurOld::Half, 3 };
    std::stringstream ss;
    dd.toStream( ss );
    String expected = "[Half...]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream03, DurOldDot )
{
    DurOldDot dd{ DurOld::Whole };
    std::stringstream ss;
    dd.toStream( ss );
    String expected = "[Whole]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator01, DurOldDot )
{
    DurOldDot dd{ DurOld::ThirtySecond, 1 };
    std::stringstream ss;
    ss << dd;
    String expected = "[ThirtySecond.]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator02, DurOldDot )
{
    DurOldDot dd{ DurOld::Half, 3 };
    std::stringstream ss;
    ss << dd;
    String expected = "[Half...]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator03, DurOldDot )
{
    DurOldDot dd{ DurOld::Whole };
    std::stringstream ss;
    ss << dd;
    String expected = "[Whole]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toString01, DurOldDot )
{
    DurOldDot dd{ DurOld::ThirtySecond, 1 };
    String expected = "[ThirtySecond.]";
    String actual = dd.toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString02, DurOldDot )
{
    DurOldDot dd{ DurOld::Half, 3 };
    String expected = "[Half...]";
    String actual = dd.toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString03, DurOldDot )
{
    DurOldDot dd{ DurOld::Whole };
    String expected = "[Whole]";
    String actual = dd.toString();
    CHECK_EQUAL( expected, actual )
}
TEST( getRational01, DurOldDot )
{
    auto d = DurOld::Half;
    Integer dots = 2;
    DurOldDot dd{ d, dots };
    auto r = dd.getRational();
    CHECK_EQUAL( 7, r.getNumerator() )
    CHECK_EQUAL( 2, r.getDenominator() )
}
TEST( getRational02, DurOldDot )
{
    auto d = DurOld::Whole;
    Integer dots = 1;
    DurOldDot dd{ d, dots };
    auto r = dd.getRational();
    CHECK_EQUAL( 6, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
TEST( getRational03, DurOldDot )
{
    auto d = DurOld::Quarter;
    Integer dots = 3;
    DurOldDot dd{ d, dots };
    auto r = dd.getRational();
    CHECK_EQUAL( 15, r.getNumerator() )
    CHECK_EQUAL( 8, r.getDenominator() )
}
TEST( getRational04, DurOldDot )
{
    auto d = DurOld::Quarter;
    Integer dots = 10;
    DurOldDot dd{ d, dots };
    auto r = dd.getRational();
    CHECK_EQUAL( 2047, r.getNumerator() )
    CHECK_EQUAL( 1024, r.getDenominator() )
    CHECK_DOUBLES_EQUAL( 2.0, r.getFloat(), 0.01 )
}
TEST( getRational05, DurOldDot )
{
    DurOld d = DurOld::Whole;
    DurOldDot dd{ d };
    Rational r = dd.getRational();
    CHECK_EQUAL( 4, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( getRational06, DurOldDot )
{
    DurOld d = DurOld::Half;
    DurOldDot dd{ d };
    Rational r = dd.getRational();
    CHECK_EQUAL( 2, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( getRational07, DurOldDot )
{
    DurOld d = DurOld::Quarter;
    DurOldDot dd{ d };
    Rational r = dd.getRational();
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( comparisons01, DurOldDot )
{
    /* a == b */
    DurOldDot a{ DurOld::Quarter, 0 };
    DurOldDot b{ DurOld::Quarter, 0 };
    CHECK(   ( a == b ) );
    CHECK( ! ( a != b ) );
    CHECK( ! ( a <  b ) );
    CHECK( ! ( a >  b ) );
    CHECK(   ( a <= b ) );
    CHECK(   ( a >= b ) );
}
TEST( comparisons02, DurOldDot )
{
    /* a < b */
    DurOldDot a{ DurOld::Eighth, 0 };
    DurOldDot b{ DurOld::Eighth, 1 };
    CHECK( ! ( a == b ) );
    CHECK(   ( a != b ) );
    CHECK(   ( a <  b ) );
    CHECK( ! ( a >  b ) );
    CHECK(   ( a <= b ) );
    CHECK( ! ( a >= b ) );
}
TEST( comparisons03, DurOldDot )
{
    /* a > b */
    DurOldDot a{ DurOld::Whole, 0 };
    DurOldDot b{ DurOld::Half, 4 };
    CHECK( ! ( a == b ) );
    CHECK(   ( a != b ) );
    CHECK( ! ( a <  b ) );
    CHECK(   ( a >  b ) );
    CHECK( ! ( a <= b ) );
    CHECK(   ( a >= b ) );
}
TEST( parse_success01, DurOldDot )
{
    DurOldDot d;
    CHECK( d.parse( "[Eighth.]" ) )
    CHECK_EQUAL( DurOld::Eighth, d.getDurOld() )
    CHECK_EQUAL( 1, d.getDots() )
}
TEST( parse_success02, DurOldDot )
{
    DurOldDot d;
    CHECK( d.parse( "[ThirtySecond]" ) )
    CHECK_EQUAL( DurOld::ThirtySecond, d.getDurOld() )
    CHECK_EQUAL( 0, d.getDots() )
}
TEST( parse_success03, DurOldDot )
{
    DurOldDot d;
    CHECK( d.parse( "[Whole...]" ) )
    CHECK_EQUAL( DurOld::Whole, d.getDurOld() )
    CHECK_EQUAL( 3, d.getDots() )
}
TEST( parse_fail01, DurOldDot )
{
    DurOldDot d;
    CHECK( ! d.parse( "Whole...]" ) )
    CHECK_EQUAL( DurOld::Quarter, d.getDurOld() )
    CHECK_EQUAL( 0, d.getDots() )
}
TEST( parse_fail02, DurOldDot )
{
    DurOldDot d{ DurOld::OneTwentyEighth, 1 };
    CHECK( ! d.parse( "[whole.]" ) )
    CHECK_EQUAL( DurOld::OneTwentyEighth, d.getDurOld() )
    CHECK_EQUAL( 1, d.getDots() )
}
TEST( parse_fail03, DurOldDot )
{
    DurOldDot d{ DurOld::Sixteenth, 2 };
    CHECK( ! d.parse( "[Half .]" ) )
    CHECK_EQUAL( DurOld::Sixteenth, d.getDurOld() )
    CHECK_EQUAL( 2, d.getDots() )
}