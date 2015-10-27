//PUBLIC
#include "cpulTestHarness.h"
#include "DurOld.h"

using namespace lyre;

TEST( Compiles, DurOld )
{
    DurOld d = DurOld::Quarter;
    CHECK( d == DurOld::Quarter )
}
TEST( convertToRational_Longa, DurOld )
{
    DurOld d = DurOld::Longa;
    Rational r = convert( d );
    CHECK_EQUAL( 16, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( convertToRational_Breve, DurOld )
{
    DurOld d = DurOld::Breve;
    Rational r = convert( d );
    CHECK_EQUAL( 8, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( convertToRational_Whole, DurOld )
{
    DurOld d = DurOld::Whole;
    Rational r = convert( d );
    CHECK_EQUAL( 4, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( convertToRational_Half, DurOld )
{
    DurOld d = DurOld::Half;
    Rational r = convert( d );
    CHECK_EQUAL( 2, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( convertToRational_Quarter, DurOld )
{
    DurOld d = DurOld::Quarter;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( convertToRational_Eighth, DurOld )
{
    DurOld d = DurOld::Eighth;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 2, r.getDenominator() );
}
TEST( convertToRational_Sixteenth, DurOld )
{
    DurOld d = DurOld::Sixteenth;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 4, r.getDenominator() );
}
TEST( convertToRational_ThirtySecond, DurOld )
{
    DurOld d = DurOld::ThirtySecond;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 8, r.getDenominator() );
}
TEST( convertToRational_SixtyFourth, DurOld )
{
    DurOld d = DurOld::SixtyFourth;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 16, r.getDenominator() );
}
TEST( convertToRational_OneTwentyEighth, DurOld )
{
    DurOld d = DurOld::OneTwentyEighth;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 32, r.getDenominator() );
}
TEST( convertToRational_TwoFiftySixth, DurOld )
{
    DurOld d = DurOld::TwoFiftySixth;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 64, r.getDenominator() );
}
TEST( convertToDurOld_Longa, DurOld )
{
    Rational r{ 16, 1 };
    DurOld expected = DurOld::Longa;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDurOld_Breve, DurOld )
{
    Rational r{ 8, 1 };
    DurOld expected = DurOld::Breve;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDurOld_Whole, DurOld )
{
    Rational r{ 4, 1 };
    DurOld expected = DurOld::Whole;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDurOld_Half, DurOld )
{
    Rational r{ 2, 1 };
    DurOld expected = DurOld::Half;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDurOld_Quarter, DurOld )
{
    Rational r{ 1, 1 };
    DurOld expected = DurOld::Quarter;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDurOld_Eighth, DurOld )
{
    Rational r{ 1, 2 };
    DurOld expected = DurOld::Eighth;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDurOld_Sixteenth, DurOld )
{
    Rational r{ 1, 4 };
    DurOld expected = DurOld::Sixteenth;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDurOld_ThirtySecond, DurOld )
{
    Rational r{ 1, 8 };
    DurOld expected = DurOld::ThirtySecond;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDurOld_SixtyFourth, DurOld )
{
    Rational r{ 1, 16 };
    DurOld expected = DurOld::SixtyFourth;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDurOld_OneTwentyEighth, DurOld )
{
    Rational r{ 1, 32 };
    DurOld expected = DurOld::OneTwentyEighth;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDurOld_TwoFiftySixth, DurOld )
{
    Rational r{ 1, 64 };
    DurOld expected = DurOld::TwoFiftySixth;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDurOld_Throw01, DurOld )
{
    String expected = "rational could not be converted to a dur type";
    String actual = "no exception was thrown";
    try
    {
        convert( Rational{ 1, 65 } );
        CHECK_FAIL( "failed to throw exception" )
    }
    catch( const std::runtime_error& e )
    {
        actual = e.what();
    }
    CHECK_EQUAL( expected, actual )
}
TEST( parseFromString00, DurOld )
{
    String s = "Longa";
    auto expected = DurOld::Longa;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString01, DurOld )
{
    String s = "Breve";
    auto expected = DurOld::Breve;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString02, DurOld )
{
    String s = "Whole";
    auto expected = DurOld::Whole;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString03, DurOld )
{
    String s = "Half";
    auto expected = DurOld::Half;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString04, DurOld )
{
    String s = "Quarter";
    auto expected = DurOld::Quarter;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString05, DurOld )
{
    String s = "Eighth";
    auto expected = DurOld::Eighth;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString06, DurOld )
{
    String s = "Sixteenth";
    auto expected = DurOld::Sixteenth;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString07, DurOld )
{
    String s = "ThirtySecond";
    auto expected = DurOld::ThirtySecond;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString08, DurOld )
{
    String s = "SixtyFourth";
    auto expected = DurOld::SixtyFourth;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString09, DurOld )
{
    String s = "OneTwentyEighth";
    auto expected = DurOld::OneTwentyEighth;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString10, DurOld )
{
    String s = "TwoFiftySixth";
    auto expected = DurOld::TwoFiftySixth;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString_Throw01, DurOld )
{
    /* note parse function is case sensitive */
    String expected = "string could not be parsed to a dur type";
    String actual = "no exception was thrown";
    try
    {
        parse( "twoFiftySixth" );
        CHECK_FAIL( "failed to throw exception" )
    }
    catch( const std::runtime_error& e )
    {
        actual = e.what();
    }
    CHECK_EQUAL( expected, actual )
}
TEST( toString00, DurOld )
{
    auto d = DurOld::Longa;
    String expected = "Longa";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString01, DurOld )
{
    auto d = DurOld::Breve;
    String expected = "Breve";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString02, DurOld )
{
    auto d = DurOld::Whole;
    String expected = "Whole";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString03, DurOld )
{
    auto d = DurOld::Half;
    String expected = "Half";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString04, DurOld )
{
    auto d = DurOld::Quarter;
    String expected = "Quarter";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString05, DurOld )
{
    auto d = DurOld::Eighth;
    String expected = "Eighth";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString06, DurOld )
{
    auto d = DurOld::Sixteenth;
    String expected = "Sixteenth";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString07, DurOld )
{
    auto d = DurOld::ThirtySecond;
    String expected = "ThirtySecond";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString08, DurOld )
{
    auto d = DurOld::SixtyFourth;
    String expected = "SixtyFourth";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString09, DurOld )
{
    auto d = DurOld::OneTwentyEighth;
    String expected = "OneTwentyEighth";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString10, DurOld )
{
    auto d = DurOld::TwoFiftySixth;
    String expected = "TwoFiftySixth";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}

TEST( streamingOperator01,  DurOld )
{
    auto d = DurOld::Breve;
    std::stringstream ss;
    ss << d;
    String expected = "Breve";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator02,  DurOld )
{
    auto d = DurOld::OneTwentyEighth;
    std::stringstream ss;
    ss << d;
    String expected = "OneTwentyEighth";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}