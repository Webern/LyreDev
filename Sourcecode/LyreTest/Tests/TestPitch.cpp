//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Private/Pitch.h"
#include <sstream>

using namespace Lyre;
using namespace Lyre::Private;
using namespace std;

TEST( defaultConstructor, Pitch )
{
    PitchUP n{ new Pitch{} };
    CHECK_EQUAL( 0, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 0, n->getOctaveValue() )
    CHECK_EQUAL( 12, n->getValue() )
}
TEST( constructor01, Pitch )
{
    PitchUP n{ new Pitch{ 1, 2, 4 } };
    CHECK_EQUAL( 1, n->getStepValue() )
    CHECK_EQUAL( 2, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    CHECK_EQUAL( 64, n->getValue() )
}
TEST( constructor02, Pitch )
{
    PitchUP n{ new Pitch{ "Ab3" } };
    CHECK_EQUAL( 5, n->getStepValue() )
    CHECK_EQUAL( -1, n->getAlterValue() )
    CHECK_EQUAL( 3, n->getOctaveValue() )
    CHECK_EQUAL( 56, n->getValue() )
}
TEST( copyConstructor, Pitch )
{
    Pitch orig{ "B6" };
    Pitch copy{ orig };
    CHECK_EQUAL( 95, orig.getValue() )
    CHECK_EQUAL( 95, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 95, orig.getValue() )
    CHECK_EQUAL( 84, copy.getValue() )
}
TEST( moveConstructor, Pitch )
{
    Pitch orig{ "B6" };
    Pitch copy{ std::move( orig ) };
    CHECK_EQUAL( 95, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 84, copy.getValue() )
}
TEST( assignment, Pitch )
{
    Pitch orig{ "B6" };
    Pitch copy;
    copy = orig;
    CHECK_EQUAL( 95, orig.getValue() )
    CHECK_EQUAL( 95, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 95, orig.getValue() )
    CHECK_EQUAL( 84, copy.getValue() )
}
TEST( moveAssignment, Pitch )
{
    Pitch orig{ "B6" };
    Pitch copy;
    copy.operator=( std::move( orig ) );
    CHECK_EQUAL( 95, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 84, copy.getValue() )
}
TEST( clone, Pitch )
{
    PitchUP orig{ new Pitch{ "B6" } };
    IPitchUP copy;
    CHECK( ! ( copy ) )
    copy = orig->clone();
    CHECK( ( copy ) )
    CHECK( ! ( copy.get() == orig.get() ) )
    CHECK_EQUAL( 95, orig->getValue() )
    CHECK_EQUAL( 95, copy->getValue() )
    copy->setStepValue( 0 );
    CHECK_EQUAL( 95, orig->getValue() )
    CHECK_EQUAL( 84, copy->getValue() )
}
//TEST( copyTo, Pitch )
//{
//    PitchUP orig{ new Pitch{ "B6" } };
//    PitchUP copy;
//    CHECK( ! ( copy ) )
//    orig->copyTo( copy );
//    CHECK( ( copy ) )
//    CHECK( ! ( copy.get() == orig.get() ) )
//    CHECK_EQUAL( 95, orig->getValue() )
//    CHECK_EQUAL( 95, copy->getValue() )
//    copy->setStepValue( 0 );
//    CHECK_EQUAL( 95, orig->getValue() )
//    CHECK_EQUAL( 84, copy->getValue() )
//}

TEST( getValue01, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gddd-2" );
    CHECK_EQUAL( -11, n->getValue() )
}

TEST( getValue02, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gddb-1" );;
    CHECK_EQUAL( 2, n->getValue() )
}
TEST( getValue03, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gdd0" );;
    CHECK_EQUAL( 15, n->getValue() )
}
TEST( getValue04, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gdb1" );;
    CHECK_EQUAL( 28, n->getValue() )
}
TEST( getValue05, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gd2" );;
    CHECK_EQUAL( 41, n->getValue() )
}
TEST( getValue06, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gb3" );;
    CHECK_EQUAL( 54, n->getValue() )
}
TEST( getValue07, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "G4" );;
    CHECK_EQUAL( 67, n->getValue() )
}

TEST( getValue08, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "G#5" );;
    CHECK_EQUAL( 80, n->getValue() )
}
TEST( getValue09, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gx6" );;
    CHECK_EQUAL( 93, n->getValue() )
}
TEST( getValue10, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gx#7" );;
    CHECK_EQUAL( 106, n->getValue() )
}
TEST( getValue11, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gxx8" );;
    CHECK_EQUAL( 119, n->getValue() )
}
TEST( getValue12, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gxx#9" );;
    CHECK_EQUAL( 132, n->getValue() )
}
TEST( getValue13, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gxxx10" );;
    CHECK_EQUAL( 145, n->getValue() )
}
TEST( getValue14, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dddd-31" );;
    CHECK_EQUAL( -364, n->getValue() )
}
TEST( getValue15, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dddb-3" );;
    CHECK_EQUAL( -27, n->getValue() )
}
TEST( getValue16, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Ddd-2" );;
    CHECK_EQUAL( -14, n->getValue() )
}
TEST( getValue17, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Ddb-1" );;
    CHECK_EQUAL( -1, n->getValue() )
}
TEST( getValue18, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dd0" );;
    CHECK_EQUAL( 12, n->getValue() )
}
TEST( getValue19, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Db1" );;
    CHECK_EQUAL( 25, n->getValue() )
}
TEST( getValue20, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "D2" );;
    CHECK_EQUAL( 38, n->getValue() )
}
TEST( getValue21, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "D#3" );;
    CHECK_EQUAL( 51, n->getValue() )
}
TEST( getValue22, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dx4" );;
    CHECK_EQUAL( 64, n->getValue() )
}
TEST( getValue23, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dx#5" );;
    CHECK_EQUAL( 77, n->getValue() )
}
TEST( getValue24, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dxx6" );;
    CHECK_EQUAL( 90, n->getValue() )
}
TEST( getValue25, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dxx#7" );;
    CHECK_EQUAL( 103, n->getValue() )
}
TEST( getValue26, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dxxx8" );;
    CHECK_EQUAL( 116, n->getValue() )
}
TEST( getValue27, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "B#9" );;
    CHECK_EQUAL( 132, n->getValue() )
}
TEST( getValue28, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "C10" );;
    CHECK_EQUAL( 132, n->getValue() )
}
TEST( getValue29, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Db4" );;
    CHECK_EQUAL( 61, n->getValue() )
}
TEST( getValue30, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "C#4" );;
    CHECK_EQUAL( 61, n->getValue() )
}
TEST( getValue31, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "D4" );;
    CHECK_EQUAL( 62, n->getValue() )
}
TEST( getValue32, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Cx4" );;
    CHECK_EQUAL( 62, n->getValue() )
}
TEST( getValue33, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Eb4" );;
    CHECK_EQUAL( 63, n->getValue() )
}
TEST( getValue34, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "D#4" );;
    CHECK_EQUAL( 63, n->getValue() )
}
TEST( getValue37, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "E4" );;
    CHECK_EQUAL( 64, n->getValue() )
}
TEST( getValue38, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Fb4" );;
    CHECK_EQUAL( 64, n->getValue() )
}
TEST( getValue39, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "F4" );;
    CHECK_EQUAL( 65, n->getValue() )
}
TEST( getValue40, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "E#4" );;
    CHECK_EQUAL( 65, n->getValue() )
}
TEST( getValue41, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gb4" );;
    CHECK_EQUAL( 66, n->getValue() )
}
TEST( getValue42, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "F#4" );;
    CHECK_EQUAL( 66, n->getValue() )
}
TEST( getValue43, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "G4" );;
    CHECK_EQUAL( 67, n->getValue() )
}
TEST( getValue44, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Ad4" );;
    CHECK_EQUAL( 67, n->getValue() )
}
TEST( getValue45, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Ab4" );;
    CHECK_EQUAL( 68, n->getValue() )
}
TEST( getValue46, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "G#4" );;
    CHECK_EQUAL( 68, n->getValue() )
}
TEST( getValue47, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "A4" );;
    CHECK_EQUAL( 69, n->getValue() )
}
TEST( getValue48, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gx4" );;
    CHECK_EQUAL( 69, n->getValue() )
}
TEST( getValue49, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Bb4" );;
    CHECK_EQUAL( 70, n->getValue() )
}
TEST( getValue50, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "A#4" );;
    CHECK_EQUAL( 70, n->getValue() )
}
TEST( getValue51, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "B4" );;
    CHECK_EQUAL( 71, n->getValue() )
}
TEST( getValue52, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Cb4" );;
    CHECK_EQUAL( 59, n->getValue() )
}

TEST( parse_fail01, Pitch )
{
    PitchUP n{ new Pitch{ "F4" } };
    CHECK_EQUAL( 65, n->getValue() )
    CHECK( ! n->parse( "Cbd3" ) )
    CHECK_EQUAL( 65, n->getValue() )
}
TEST( parse_fail02, Pitch )
{
    PitchUP n{ new Pitch{ "F#2" } };
    CHECK_EQUAL( 42, n->getValue() )
    CHECK( ! n->parse( "B-" ) )
    CHECK_EQUAL( 42, n->getValue() )
}
TEST( parse_fail03, Pitch )
{
    PitchUP n{ new Pitch{ "G6" } };
    CHECK_EQUAL( 91, n->getValue() )
    CHECK( ! n->parse( "#6" ) )
    CHECK_EQUAL( 91, n->getValue() )
}
TEST( parse_fail04, Pitch )
{
    PitchUP n{ new Pitch{ "Ab3" } };
    CHECK_EQUAL( 56, n->getValue() )
    CHECK( ! n->parse( "Ab" ) )
    CHECK_EQUAL( 56, n->getValue() )
}
TEST( parse_fail05, Pitch )
{
    PitchUP n{ new Pitch{ "Ab3" } };
    CHECK_EQUAL( 56, n->getValue() )
    CHECK( ! n->parse( "F-0" ) )
    CHECK_EQUAL( 56, n->getValue() )
}
TEST( parse_fail06, Pitch )
{
    PitchUP n{ new Pitch{ "Ab3" } };
    CHECK_EQUAL( 56, n->getValue() )
    CHECK( ! n->parse( "G01" ) )
    CHECK_EQUAL( 56, n->getValue() )
}
TEST( parse_fail07, Pitch )
{
    PitchUP n{ new Pitch{ "Ab3" } };
    CHECK_EQUAL( 56, n->getValue() )
    CHECK( ! n->parse( "G0-1" ) )
    CHECK_EQUAL( 56, n->getValue() )
}
TEST( parse_success01, Pitch )
{
    PitchUP n{ new Pitch{ "F1" } };
    CHECK_EQUAL( 29, n->getValue() )
    CHECK( n->parse( "B#3" ) )
    CHECK_EQUAL( 60, n->getValue() )
}
TEST( parse_success02, Pitch )
{
    PitchUP n{ new Pitch{ "F#-1" } };
    CHECK_EQUAL( 6, n->getValue() )
    CHECK( n->parse( "Bb2" ) )
    CHECK_EQUAL( 46, n->getValue() )
}
TEST( parse_success03, Pitch )
{
    PitchUP n{ new Pitch{ "G" } };
    CHECK_EQUAL( 12, n->getValue() )
    CHECK( n->parse( "C#-1000" ) )
    CHECK_EQUAL( -11987, n->getValue() )
}
TEST( parse_success04, Pitch )
{
    PitchUP n{ new Pitch{ "Ab-1" } };
    CHECK_EQUAL( 8, n->getValue() )
    CHECK( n->parse( "Cdb1537" ) )
    CHECK_EQUAL( 18453, n->getValue() )
}

TEST( toStream00, Pitch )
{
    String str = "Bb4";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream01, Pitch )
{
    String str = "Cxxx-1";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream02, Pitch )
{
    String str = "G#5";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream03, Pitch )
{
    String str = "Bb-2";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream04, Pitch )
{
    String str = "Ed6";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream05, Pitch )
{
    String str = "Fb0";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream06, Pitch )
{
    String str = "Gb7";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream07, Pitch )
{
    String str = "B8";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream08, Pitch )
{
    String str = "A10";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream09, Pitch )
{
    String str = "Axxxxxxx9487";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream10, Pitch )
{
    String str = "Edddddddddddddb-7581";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator00, Pitch )
{
    String str = "Bb4";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator01, Pitch )
{
    String str = "Cxxx5";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator02, Pitch )
{
    String str = "G#6";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator03, Pitch )
{
    String str = "Bb1024";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator04, Pitch )
{
    String str = "Ed-123";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator05, Pitch )
{
    String str = "Fb6";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator06, Pitch )
{
    String str = "Gb3";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator07, Pitch )
{
    String str = "B76";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator08, Pitch )
{
    String str = "A8";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator09, Pitch )
{
    String str = "Axxxxxxx-1073";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator10, Pitch )
{
    String str = "Edddddddddddddb336";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toString00, Pitch )
{
    String str = "Bb4";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString01, Pitch )
{
    String str = "Cxxx5";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString02, Pitch )
{
    String str = "G#3";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString03, Pitch )
{
    String str = "Bb6";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString04, Pitch )
{
    String str = "Ed1";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString05, Pitch )
{
    String str = "Fb9";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString06, Pitch )
{
    String str = "Gb0";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString07, Pitch )
{
    String str = "B-1";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString08, Pitch )
{
    String str = "A-2";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString09, Pitch )
{
    String str = "Axxxxxxx-4568";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString10, Pitch )
{
    String str = "Edddddddddddddb2459";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}

TEST( compare_a_isLessThan_b_01, Pitch )
{
    String a_str = "Cb4";
    String b_str = "B#3";
    IPitchUP a{ new Pitch{ a_str } };
    IPitchUP b{ new Pitch{ b_str } };
    CHECK(   ( a->isLessThan( *b ) ) )
    CHECK( ! ( a->isEqualTo( *b ) ) )
    CHECK( ! ( a->isGreaterThan( *b ) ) )
}

TEST( compare_a_isLessThan_b_02, Pitch )
{
    String a_str = "Axx4";
    String b_str = "D5";
    IPitchUP a{ new Pitch{ a_str } };
    IPitchUP b{ new Pitch{ b_str } };
    CHECK(   ( a->isLessThan( *b ) ) )
    CHECK( ! ( a->isEqualTo( *b ) ) )
    CHECK( ! ( a->isGreaterThan( *b ) ) )
}
TEST( compare_a_isEqualTo_b_01, Pitch )
{
    String a_str = "F#6";
    String b_str = "Gb6";
    IPitchUP a{ new Pitch{ a_str } };
    IPitchUP b{ new Pitch{ b_str } };
    CHECK( ! ( a->isLessThan( *b ) ) )
    CHECK(   ( a->isEqualTo( *b ) ) )
    CHECK( ! ( a->isGreaterThan( *b ) ) )
}
TEST( compare_a_isEqualTo_b_02, Pitch )
{
    String a_str = "Cd-3";
    String b_str = "Gx#-4";
    IPitchUP a{ new Pitch{ a_str } };
    IPitchUP b{ new Pitch{ b_str } };
    CHECK( ! ( a->isLessThan( *b ) ) )
    CHECK(   ( a->isEqualTo( *b ) ) )
    CHECK( ! ( a->isGreaterThan( *b ) ) )
}

TEST( compare_a_isGreaterThan_b_01, Pitch )
{
    String a_str = "C4";
    String b_str = "Gdddd4";
    IPitchUP a{ new Pitch{ a_str } };
    IPitchUP b{ new Pitch{ b_str } };
    CHECK( ! ( a->isLessThan( *b ) ) )
    CHECK( ! ( a->isEqualTo( *b ) ) )
    CHECK(   ( a->isGreaterThan( *b ) ) )
}
TEST( compare_a_isGreaterThan_b_02, Pitch )
{
    String a_str = "F4";
    String b_str = "E4";
    IPitchUP a{ new Pitch{ a_str } };
    IPitchUP b{ new Pitch{ b_str } };
    CHECK( ! ( a->isLessThan( *b ) ) )
    CHECK( ! ( a->isEqualTo( *b ) ) )
    CHECK(   ( a->isGreaterThan( *b ) ) )
}


TEST( getStepValue0, Pitch )
{
    String str = "C2";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 0, n->getStepValue() )
}
TEST( getStepValue1, Pitch )
{
    String str = "Db1";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 1, n->getStepValue() )
}
TEST( getStepValue2, Pitch )
{
    String str = "E#3";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 2, n->getStepValue() )
}
TEST( getStepValue3, Pitch )
{
    String str = "F4";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 3, n->getStepValue() )
}
TEST( getStepValue4, Pitch )
{
    String str = "Gb5";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 4, n->getStepValue() )
}
TEST( getStepValue5, Pitch )
{
    String str = "A#-1";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 5, n->getStepValue() )
}
TEST( getStepValue6, Pitch )
{
    String str = "B-2";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 6, n->getStepValue() )
}
TEST( setStepValue0, Pitch )
{
    String str = "F1";
    Integer setTo = 0;
    Integer expected = 0;
    IPitchUP n{ new Pitch{ str } };
    n->setStepValue( setTo );
    Integer actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}

TEST( setStepValue1, Pitch )
{
    String str = "G2";
    Integer setTo = 7;
    Integer expected = 6;
    IPitchUP n{ new Pitch{ str } };
    n->setStepValue( setTo );
    Integer actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setStepValue2, Pitch )
{
    String str = "D3";
    Integer setTo = -1;
    Integer expected = 0;
    IPitchUP n{ new Pitch{ str } };
    n->setStepValue( setTo );
    Integer actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
TEST( incrementStep, Pitch )
{
    IPitchUP n{ new Pitch{ "C4" } };
    n->incrementStep();
    CHECK_EQUAL( 1, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    n->incrementStep();
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    n->incrementStep();
    CHECK_EQUAL( 3, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    n->incrementStep();
    CHECK_EQUAL( 4, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    n->incrementStep();
    CHECK_EQUAL( 5, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    n->incrementStep();
    CHECK_EQUAL( 6, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    n->incrementStep();
    CHECK_EQUAL( 0, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
}
TEST( decrementStep, Pitch )
{
    IPitchUP n{ new Pitch{ "C-1" } };
    n->decrementStep();
    CHECK_EQUAL( 6, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
    n->decrementStep();
    CHECK_EQUAL( 5, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
    n->decrementStep();
    CHECK_EQUAL( 4, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
    n->decrementStep();
    CHECK_EQUAL( 3, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
    n->decrementStep();
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
    n->decrementStep();
    CHECK_EQUAL( 1, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
    n->decrementStep();
    CHECK_EQUAL( 0, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
}
TEST( getAlterValue00, Pitch )
{
    String str{ "C8" };
    Integer expected = 0;
    IPitchUP n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue01, Pitch )
{
    String str{ "Fb4" };
    Integer expected = -1;
    IPitchUP n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue02, Pitch )
{
    String str{ "G#5" };
    Integer expected = 1;
    IPitchUP n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue03, Pitch )
{
    String str{ "Bd-101" };
    Integer expected = -2;
    IPitchUP n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue04, Pitch )
{
    String str{ "Ax12" };
    Integer expected = 2;
    IPitchUP n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue05, Pitch )
{
    String str{ "Ddb3" };
    Integer expected = -3;
    IPitchUP n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue06, Pitch )
{
    String str{ "Cx#7" };
    Integer expected = 3;
    IPitchUP n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue07, Pitch )
{
    String str{ "Edd3" };
    Integer expected = -4;
    IPitchUP n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue08, Pitch )
{
    String str{ "Fxx1013" };
    Integer expected = 4;
    IPitchUP n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue09, Pitch )
{
    String str{ "Cddb-321" };
    Integer expected = -5;
    IPitchUP n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue10, Pitch )
{
    String str{ "Cxx#8" };
    Integer expected = 5;
    IPitchUP n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setAlterValue01, Pitch )
{
    String str{ "Cxx#4" };
    Integer setTo = 3;
    Integer expected = setTo;
    IPitchUP n{ new Pitch{ str } };
    n->setAlterValue( setTo );
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setAlterValue02, Pitch )
{
    String str{ "Cx1" };
    Integer setTo = 0;
    Integer expected = setTo;
    IPitchUP n{ new Pitch{ str } };
    n->setAlterValue( setTo );
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setAlterValue03, Pitch )
{
    String str{ "Gb2" };
    Integer setTo = 100;
    Integer expected = setTo;
    IPitchUP n{ new Pitch{ str } };
    n->setAlterValue( setTo );
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setAlterValue04, Pitch )
{
    String str{ "Gb3" };
    Integer setTo = -100;
    Integer expected = setTo;
    IPitchUP n{ new Pitch{ str } };
    n->setAlterValue( setTo );
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( incrementAlter, Pitch )
{
    IPitchUP n{ new Pitch{ "Eddd9" } };
    n->incrementAlter();
    CHECK_EQUAL( -5, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( -4, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( -3, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( -2, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( -1, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 1, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 2, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 3, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 4, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 5, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 6, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->setAlterValue( std::numeric_limits<Integer>::max() );
    CHECK_EQUAL( std::numeric_limits<Integer>::max(), n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( std::numeric_limits<Integer>::min(), n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
}
TEST( decrementAlter, Pitch )
{
    IPitchUP n{ new Pitch{ "Exxx-2" } };
    n->decrementAlter();
    CHECK_EQUAL( 5, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( 4, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( 3, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( 2, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( 1, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( 0, n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( -1, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( -2, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( -3, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( -4, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( -5, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( -6, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->setAlterValue( std::numeric_limits<Integer>::min() );
    CHECK_EQUAL( std::numeric_limits<Integer>::min(), n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( std::numeric_limits<Integer>::max(), n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
}
TEST( getOctave, Pitch )
{
    IPitchUP n{ new Pitch{ "Gx-2" } };
    CHECK_EQUAL( 2, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
}
TEST( setOctave, Pitch )
{
    IPitchUP n{ new Pitch{ "F#7" } };
    CHECK_EQUAL( 1, n->getAlterValue() )
    CHECK_EQUAL( 3, n->getStepValue() )
    CHECK_EQUAL( 7, n->getOctaveValue() )
    n->setOctaveValue( -1 );
    CHECK_EQUAL( -1, n->getOctaveValue() )
}
TEST( incrementOctave, Pitch )
{
    IPitchUP n{ new Pitch{ "F#7" } };
    CHECK_EQUAL( 1, n->getAlterValue() )
    CHECK_EQUAL( 3, n->getStepValue() )
    CHECK_EQUAL( 7, n->getOctaveValue() )
    n->incrementOctave();
    CHECK_EQUAL( 8, n->getOctaveValue() )
}
TEST( decrementOctave, Pitch )
{
    IPitchUP n{ new Pitch{ "F#7" } };
    CHECK_EQUAL( 1, n->getAlterValue() )
    CHECK_EQUAL( 3, n->getStepValue() )
    CHECK_EQUAL( 7, n->getOctaveValue() )
    n->decrementOctave();
    CHECK_EQUAL( 6, n->getOctaveValue() )
}
TEST( isIdenticalTo_true01, Pitch )
{
    IPitchUP a{ new Pitch{ "C4" } };
    IPitchUP b{ new Pitch{ "C4" } };
    CHECK( a->isIdenticalTo( *b ) )
}
TEST( isIdenticalTo_false01, Pitch )
{
    IPitchUP a{ new Pitch{ "C4" } };
    IPitchUP b{ new Pitch{ "B#3" } };
    CHECK( a->isEqualTo( *b ) );
    CHECK( ! a->isIdenticalTo( *b ) )
}