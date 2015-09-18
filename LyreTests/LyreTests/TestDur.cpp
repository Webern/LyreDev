#include "cpulTestHarness.h"
#include "Dur.h"

using namespace lyre;

TEST( Compiles, Dur )
{
    Dur d = Dur::Quarter;
    CHECK( d == Dur::Quarter )
}
TEST( convertToRational_Longa, Dur )
{
    Dur d = Dur::Longa;
    Rational r = convert( d );
    CHECK_EQUAL( 16, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( convertToRational_Breve, Dur )
{
    Dur d = Dur::Breve;
    Rational r = convert( d );
    CHECK_EQUAL( 8, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( convertToRational_Whole, Dur )
{
    Dur d = Dur::Whole;
    Rational r = convert( d );
    CHECK_EQUAL( 4, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( convertToRational_Half, Dur )
{
    Dur d = Dur::Half;
    Rational r = convert( d );
    CHECK_EQUAL( 2, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( convertToRational_Quarter, Dur )
{
    Dur d = Dur::Quarter;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 1, r.getDenominator() );
}
TEST( convertToRational_Eighth, Dur )
{
    Dur d = Dur::Eighth;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 2, r.getDenominator() );
}
TEST( convertToRational_Sixteenth, Dur )
{
    Dur d = Dur::Sixteenth;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 4, r.getDenominator() );
}
TEST( convertToRational_ThirtySecond, Dur )
{
    Dur d = Dur::ThirtySecond;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 8, r.getDenominator() );
}
TEST( convertToRational_SixtyFourth, Dur )
{
    Dur d = Dur::SixtyFourth;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 16, r.getDenominator() );
}
TEST( convertToRational_OneTwentyEighth, Dur )
{
    Dur d = Dur::OneTwentyEighth;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 32, r.getDenominator() );
}
TEST( convertToRational_TwoFiftySixth, Dur )
{
    Dur d = Dur::TwoFiftySixth;
    Rational r = convert( d );
    CHECK_EQUAL( 1, r.getNumerator() );
    CHECK_EQUAL( 64, r.getDenominator() );
}
TEST( convertToDur_Longa, Dur )
{
    Rational r{ 16, 1 };
    Dur expected = Dur::Longa;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDur_Breve, Dur )
{
    Rational r{ 8, 1 };
    Dur expected = Dur::Breve;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDur_Whole, Dur )
{
    Rational r{ 4, 1 };
    Dur expected = Dur::Whole;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDur_Half, Dur )
{
    Rational r{ 2, 1 };
    Dur expected = Dur::Half;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDur_Quarter, Dur )
{
    Rational r{ 1, 1 };
    Dur expected = Dur::Quarter;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDur_Eighth, Dur )
{
    Rational r{ 1, 2 };
    Dur expected = Dur::Eighth;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDur_Sixteenth, Dur )
{
    Rational r{ 1, 4 };
    Dur expected = Dur::Sixteenth;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDur_ThirtySecond, Dur )
{
    Rational r{ 1, 8 };
    Dur expected = Dur::ThirtySecond;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDur_SixtyFourth, Dur )
{
    Rational r{ 1, 16 };
    Dur expected = Dur::SixtyFourth;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDur_OneTwentyEighth, Dur )
{
    Rational r{ 1, 32 };
    Dur expected = Dur::OneTwentyEighth;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDur_TwoFiftySixth, Dur )
{
    Rational r{ 1, 64 };
    Dur expected = Dur::TwoFiftySixth;
    auto actual = convert( r );
    CHECK( expected == actual )
}
TEST( convertToDur_Throw01, Dur )
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
TEST( parseFromString00, Dur )
{
    String s = "Longa";
    auto expected = Dur::Longa;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString01, Dur )
{
    String s = "Breve";
    auto expected = Dur::Breve;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString02, Dur )
{
    String s = "Whole";
    auto expected = Dur::Whole;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString03, Dur )
{
    String s = "Half";
    auto expected = Dur::Half;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString04, Dur )
{
    String s = "Quarter";
    auto expected = Dur::Quarter;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString05, Dur )
{
    String s = "Eighth";
    auto expected = Dur::Eighth;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString06, Dur )
{
    String s = "Sixteenth";
    auto expected = Dur::Sixteenth;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString07, Dur )
{
    String s = "ThirtySecond";
    auto expected = Dur::ThirtySecond;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString08, Dur )
{
    String s = "SixtyFourth";
    auto expected = Dur::SixtyFourth;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString09, Dur )
{
    String s = "OneTwentyEighth";
    auto expected = Dur::OneTwentyEighth;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString10, Dur )
{
    String s = "TwoFiftySixth";
    auto expected = Dur::TwoFiftySixth;
    auto actual = parse( s );
    CHECK( expected == actual )
}
TEST( parseFromString_Throw01, Dur )
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
TEST( toString00, Dur )
{
    auto d = Dur::Longa;
    String expected = "Longa";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString01, Dur )
{
    auto d = Dur::Breve;
    String expected = "Breve";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString02, Dur )
{
    auto d = Dur::Whole;
    String expected = "Whole";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString03, Dur )
{
    auto d = Dur::Half;
    String expected = "Half";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString04, Dur )
{
    auto d = Dur::Quarter;
    String expected = "Quarter";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString05, Dur )
{
    auto d = Dur::Eighth;
    String expected = "Eighth";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString06, Dur )
{
    auto d = Dur::Sixteenth;
    String expected = "Sixteenth";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString07, Dur )
{
    auto d = Dur::ThirtySecond;
    String expected = "ThirtySecond";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString08, Dur )
{
    auto d = Dur::SixtyFourth;
    String expected = "SixtyFourth";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString09, Dur )
{
    auto d = Dur::OneTwentyEighth;
    String expected = "OneTwentyEighth";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( toString10, Dur )
{
    auto d = Dur::TwoFiftySixth;
    String expected = "TwoFiftySixth";
    String actual = toString( d );
    CHECK_EQUAL( expected, actual )
}
TEST( convertDots01, Dur )
{
    auto d = Dur::Half;
    Integer dots = 2;
    auto r = convert( d, dots );
    CHECK_EQUAL( 7, r.getNumerator() )
    CHECK_EQUAL( 2, r.getDenominator() )
}
TEST( convertDots02, Dur )
{
    auto d = Dur::Whole;
    Integer dots = 1;
    auto r = convert( d, dots );
    CHECK_EQUAL( 6, r.getNumerator() )
    CHECK_EQUAL( 1, r.getDenominator() )
}
TEST( convertDots03, Dur )
{
    auto d = Dur::Quarter;
    Integer dots = 3;
    auto r = convert( d, dots );
    CHECK_EQUAL( 15, r.getNumerator() )
    CHECK_EQUAL( 8, r.getDenominator() )
}