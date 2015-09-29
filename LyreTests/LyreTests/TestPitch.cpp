
#include "cpulTestHarness.h"
#include "Pitch.h"
#include <sstream>

using namespace lyre;
using namespace std;

TEST( defaultConstructor, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    CHECK_EQUAL( 0, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( constructor01, Pitch )
{
    PitchUPtr n{ new Pitch{ 1, 2, 4 } };
    CHECK_EQUAL( 1, n->getStepValue() )
    CHECK_EQUAL( 2, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( constructor02, Pitch )
{
    PitchUPtr n{ new Pitch{ "Ab3" } };
    CHECK_EQUAL( 5, n->getStepValue() )
    CHECK_EQUAL( -1, n->getAlterValue() )
    CHECK_EQUAL( 3, n->getOctaveValue() )
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( copyConstructor, Pitch )
{
    Pitch orig{ "B6" };
    Pitch copy{ orig };
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( moveConstructor, Pitch )
{
    Pitch orig{ "B6" };
    Pitch copy{ std::move( orig ) };
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( assignment, Pitch )
{
    Pitch orig{ "B6" };
    Pitch copy;
    copy = orig;
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( moveAssignment, Pitch )
{
    Pitch orig{ "B6" };
    Pitch copy;
    copy.operator=( std::move( orig ) );
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( clone, Pitch )
{
    PitchUPtr orig{ new Pitch{ "B6" } };
    IPitchUPtr copy;
    CHECK( ! ( copy ) )
    copy = orig->clone();
    CHECK( ( copy ) )
    CHECK( ! ( copy.get() == orig.get() ) )
    CHECK_EQUAL( 11, orig->getValue() )
    CHECK_EQUAL( 11, copy->getValue() )
    copy->setStepValue( 0 );
    CHECK_EQUAL( 11, orig->getValue() )
    CHECK_EQUAL( 0, copy->getValue() )
}
TEST( copyTo, Pitch )
{
    PitchUPtr orig{ new Pitch{ "B6" } };
    PitchUPtr copy;
    CHECK( ! ( copy ) )
    orig->copyTo( copy );
    CHECK( ( copy ) )
    CHECK( ! ( copy.get() == orig.get() ) )
    CHECK_EQUAL( 11, orig->getValue() )
    CHECK_EQUAL( 11, copy->getValue() )
    copy->setStepValue( 0 );
    CHECK_EQUAL( 11, orig->getValue() )
    CHECK_EQUAL( 0, copy->getValue() )
}

TEST( getValue01, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Gddd-2" );
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue02, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Gddb-1" );;
    CHECK_EQUAL( 2, n->getValue() )
}
TEST( getValue03, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Gdd0" );;
    CHECK_EQUAL( 3, n->getValue() )
}
TEST( getValue04, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Gdb1" );;
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( getValue05, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Gd2" );;
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( getValue06, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Gb3" );;
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( getValue07, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "G4" );;
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( getValue08, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "G#5" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue09, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Gx6" );;
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( getValue10, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Gx#7" );;
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( getValue11, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Gxx8" );;
    CHECK_EQUAL( 11, n->getValue() )
}
TEST( getValue12, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Gxx#9" );;
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( getValue13, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Gxxx10" );;
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue14, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Dddd-31" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue15, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Dddb-3" );;
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( getValue16, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Ddd-2" );;
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( getValue17, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Ddb-1" );;
    CHECK_EQUAL( 11, n->getValue() )
}
TEST( getValue18, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Dd0" );;
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( getValue19, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Db1" );;
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue20, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "D2" );;
    CHECK_EQUAL( 2, n->getValue() )
}
TEST( getValue21, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "D#3" );;
    CHECK_EQUAL( 3, n->getValue() )
}
TEST( getValue22, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Dx4" );;
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( getValue23, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Dx#5" );;
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( getValue24, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Dxx6" );;
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( getValue25, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Dxx#7" );;
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( getValue26, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Dxxx8" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue27, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "B#9" );;
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( getValue28, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "C10" );;
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( getValue29, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Db4" );;
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue30, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "C#4" );;
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue31, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "D4" );;
    CHECK_EQUAL( 2, n->getValue() )
}
TEST( getValue32, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Cx4" );;
    CHECK_EQUAL( 2, n->getValue() )
}
TEST( getValue33, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Eb4" );;
    CHECK_EQUAL( 3, n->getValue() )
}
TEST( getValue34, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "D#4" );;
    CHECK_EQUAL( 3, n->getValue() )
}
TEST( getValue37, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "E4" );;
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( getValue38, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Fb4" );;
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( getValue39, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "F4" );;
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( getValue40, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "E#4" );;
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( getValue41, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Gb4" );;
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( getValue42, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "F#4" );;
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( getValue43, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "G4" );;
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( getValue44, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Ad4" );;
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( getValue45, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Ab4" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue46, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "G#4" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue47, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "A4" );;
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( getValue48, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Gx4" );;
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( getValue49, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Bb4" );;
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( getValue50, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "A#4" );;
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( getValue51, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "B4" );;
    CHECK_EQUAL( 11, n->getValue() )
}
TEST( getValue52, Pitch )
{
    PitchUPtr n{ new Pitch{} };
    n->parse( "Cb4" );;
    CHECK_EQUAL( 11, n->getValue() )
}
TEST( parse_fail01, Pitch )
{
    PitchUPtr n{ new Pitch{ "F4" } };
    CHECK_EQUAL( 5, n->getValue() )
    CHECK( ! n->parse( "Cbd3" ) )
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( parse_fail02, Pitch )
{
    PitchUPtr n{ new Pitch{ "F#" } };
    CHECK_EQUAL( 6, n->getValue() )
    CHECK( ! n->parse( "B-" ) )
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( parse_fail03, Pitch )
{
    PitchUPtr n{ new Pitch{ "G" } };
    CHECK_EQUAL( 7, n->getValue() )
    CHECK( ! n->parse( "#6" ) )
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( parse_fail04, Pitch )
{
    PitchUPtr n{ new Pitch{ "Ab" } };
    CHECK_EQUAL( 8, n->getValue() )
    CHECK( ! n->parse( "Ab" ) )
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( parse_success01, Pitch )
{
    PitchUPtr n{ new Pitch{ "F" } };
    CHECK_EQUAL( 5, n->getValue() )
    CHECK( n->parse( "B#3" ) )
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( parse_success02, Pitch )
{
    PitchUPtr n{ new Pitch{ "F#" } };
    CHECK_EQUAL( 6, n->getValue() )
    CHECK( n->parse( "Bb2" ) )
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( parse_success03, Pitch )
{
    PitchUPtr n{ new Pitch{ "G" } };
    CHECK_EQUAL( 7, n->getValue() )
    CHECK( n->parse( "C#-12387" ) )
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( parse_success04, Pitch )
{
    PitchUPtr n{ new Pitch{ "Ab" } };
    CHECK_EQUAL( 8, n->getValue() )
    CHECK( n->parse( "Cdb1537" ) )
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( toStream00, Pitch )
{
    String str = "Bb4";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream01, Pitch )
{
    String str = "Cxxx-1";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream02, Pitch )
{
    String str = "G#5";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream03, Pitch )
{
    String str = "Bb-2";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream04, Pitch )
{
    String str = "Ed6";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream05, Pitch )
{
    String str = "Fb0";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream06, Pitch )
{
    String str = "Gb7";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream07, Pitch )
{
    String str = "B8";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream08, Pitch )
{
    String str = "A10";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream09, Pitch )
{
    String str = "Axxxxxxx94827";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream10, Pitch )
{
    String str = "Edddddddddddddb-7583721";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator00, Pitch )
{
    String str = "Bb4";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator01, Pitch )
{
    String str = "Cxxx5";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator02, Pitch )
{
    String str = "G#6";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator03, Pitch )
{
    String str = "Bb1024";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator04, Pitch )
{
    String str = "Ed-123";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator05, Pitch )
{
    String str = "Fb6";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator06, Pitch )
{
    String str = "Gb3";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator07, Pitch )
{
    String str = "B76";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator08, Pitch )
{
    String str = "A8";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator09, Pitch )
{
    String str = "Axxxxxxx-1023473";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator10, Pitch )
{
    String str = "Edddddddddddddb35436";
    PitchUPtr n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toString00, Pitch )
{
    String str = "Bb4";
    PitchUPtr n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString01, Pitch )
{
    String str = "Cxxx5";
    PitchUPtr n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString02, Pitch )
{
    String str = "G#3";
    PitchUPtr n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString03, Pitch )
{
    String str = "Bb6";
    PitchUPtr n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString04, Pitch )
{
    String str = "Ed1";
    PitchUPtr n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString05, Pitch )
{
    String str = "Fb9";
    PitchUPtr n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString06, Pitch )
{
    String str = "Gb0";
    PitchUPtr n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString07, Pitch )
{
    String str = "B-1";
    PitchUPtr n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString08, Pitch )
{
    String str = "A-2";
    PitchUPtr n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString09, Pitch )
{
    String str = "Axxxxxxx-4569268";
    PitchUPtr n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString10, Pitch )
{
    String str = "Edddddddddddddb2458719";
    PitchUPtr n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}

TEST( compare_a_lessThan_b_01, Pitch )
{
    String a_str = "B#3";
    String b_str = "Db4";
    IPitchUPtr a{ new Pitch{ a_str } };
    IPitchUPtr b{ new Pitch{ b_str } };
    CHECK(   ( a->lessThan( *b ) ) )
    CHECK( ! ( a->equals( *b ) ) )
    CHECK( ! ( a->greaterThan( *b ) ) )
}
TEST( compare_a_lessThan_b_02, Pitch )
{
    String a_str = "Axx4";
    String b_str = "D5";
    IPitchUPtr a{ new Pitch{ a_str } };
    IPitchUPtr b{ new Pitch{ b_str } };
    CHECK(   ( a->lessThan( *b ) ) )
    CHECK( ! ( a->equals( *b ) ) )
    CHECK( ! ( a->greaterThan( *b ) ) )
}
TEST( compare_a_equals_b_01, Pitch )
{
    String a_str = "F#";
    String b_str = "Gb";
    IPitchUPtr a{ new Pitch{ a_str } };
    IPitchUPtr b{ new Pitch{ b_str } };
    CHECK( ! ( a->lessThan( *b ) ) )
    CHECK(   ( a->equals( *b ) ) )
    CHECK( ! ( a->greaterThan( *b ) ) )
}
TEST( compare_a_equals_b_02, Pitch )
{
    String a_str = "Cd";
    String b_str = "Gx#";
    IPitchUPtr a{ new Pitch{ a_str } };
    IPitchUPtr b{ new Pitch{ b_str } };
    CHECK( ! ( a->lessThan( *b ) ) )
    CHECK(   ( a->equals( *b ) ) )
    CHECK( ! ( a->greaterThan( *b ) ) )
}
TEST( compare_a_greaterThan_b_01, Pitch )
{
    String a_str = "Cb";
    String b_str = "Gx#";
    IPitchUPtr a{ new Pitch{ a_str } };
    IPitchUPtr b{ new Pitch{ b_str } };
    CHECK( ! ( a->lessThan( *b ) ) )
    CHECK( ! ( a->equals( *b ) ) )
    CHECK(   ( a->greaterThan( *b ) ) )
}
TEST( compare_a_greaterThan_b_02, Pitch )
{
    String a_str = "F";
    String b_str = "E";
    IPitchUPtr a{ new Pitch{ a_str } };
    IPitchUPtr b{ new Pitch{ b_str } };
    CHECK( ! ( a->lessThan( *b ) ) )
    CHECK( ! ( a->equals( *b ) ) )
    CHECK(   ( a->greaterThan( *b ) ) )
}
TEST( getStepValue0, Pitch )
{
    String str = "C";
    IPitchUPtr n{ new Pitch{ str } };
    CHECK_EQUAL( 0, n->getStepValue() )
}
TEST( getStepValue1, Pitch )
{
    String str = "Db";
    IPitchUPtr n{ new Pitch{ str } };
    CHECK_EQUAL( 1, n->getStepValue() )
}
TEST( getStepValue2, Pitch )
{
    String str = "E#";
    IPitchUPtr n{ new Pitch{ str } };
    CHECK_EQUAL( 2, n->getStepValue() )
}
TEST( getStepValue3, Pitch )
{
    String str = "F";
    IPitchUPtr n{ new Pitch{ str } };
    CHECK_EQUAL( 3, n->getStepValue() )
}
TEST( getStepValue4, Pitch )
{
    String str = "Gb";
    IPitchUPtr n{ new Pitch{ str } };
    CHECK_EQUAL( 4, n->getStepValue() )
}
TEST( getStepValue5, Pitch )
{
    String str = "A#";
    IPitchUPtr n{ new Pitch{ str } };
    CHECK_EQUAL( 5, n->getStepValue() )
}
TEST( getStepValue6, Pitch )
{
    String str = "B";
    IPitchUPtr n{ new Pitch{ str } };
    CHECK_EQUAL( 6, n->getStepValue() )
}
TEST( setStepValue0, Pitch )
{
    String str = "F";
    Integer setTo = 0;
    Integer expected = 0;
    IPitchUPtr n{ new Pitch{ str } };
    n->setStepValue( setTo );
    Integer actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setStepValue1, Pitch )
{
    String str = "G";
    Integer setTo = 7;
    Integer expected = 6;
    IPitchUPtr n{ new Pitch{ str } };
    n->setStepValue( setTo );
    Integer actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setStepValue2, Pitch )
{
    String str = "D";
    Integer setTo = -1;
    Integer expected = 0;
    IPitchUPtr n{ new Pitch{ str } };
    n->setStepValue( setTo );
    Integer actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
TEST( incrementStep, Pitch )
{
    IPitchUPtr n{ new Pitch{ "C" } };
    n->incrementStep();
    CHECK_EQUAL( 1, n->getStepValue() )
    n->incrementStep();
    CHECK_EQUAL( 2, n->getStepValue() )
    n->incrementStep();
    CHECK_EQUAL( 3, n->getStepValue() )
    n->incrementStep();
    CHECK_EQUAL( 4, n->getStepValue() )
    n->incrementStep();
    CHECK_EQUAL( 5, n->getStepValue() )
    n->incrementStep();
    CHECK_EQUAL( 6, n->getStepValue() )
    n->incrementStep();
    CHECK_EQUAL( 0, n->getStepValue() )
}
TEST( decrementStep, Pitch )
{
    IPitchUPtr n{ new Pitch{ "C" } };
    n->decrementStep();
    CHECK_EQUAL( 6, n->getStepValue() )
    n->decrementStep();
    CHECK_EQUAL( 5, n->getStepValue() )
    n->decrementStep();
    CHECK_EQUAL( 4, n->getStepValue() )
    n->decrementStep();
    CHECK_EQUAL( 3, n->getStepValue() )
    n->decrementStep();
    CHECK_EQUAL( 2, n->getStepValue() )
    n->decrementStep();
    CHECK_EQUAL( 1, n->getStepValue() )
    n->decrementStep();
    CHECK_EQUAL( 0, n->getStepValue() )
}
TEST( getAlterValue00, Pitch )
{
    String str{ "C" };
    Integer expected = 0;
    IPitchUPtr n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue01, Pitch )
{
    String str{ "Fb" };
    Integer expected = -1;
    IPitchUPtr n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue02, Pitch )
{
    String str{ "G#" };
    Integer expected = 1;
    IPitchUPtr n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue03, Pitch )
{
    String str{ "Bd" };
    Integer expected = -2;
    IPitchUPtr n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue04, Pitch )
{
    String str{ "Ax" };
    Integer expected = 2;
    IPitchUPtr n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue05, Pitch )
{
    String str{ "Ddb" };
    Integer expected = -3;
    IPitchUPtr n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue06, Pitch )
{
    String str{ "Cx#" };
    Integer expected = 3;
    IPitchUPtr n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue07, Pitch )
{
    String str{ "Edd" };
    Integer expected = -4;
    IPitchUPtr n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue08, Pitch )
{
    String str{ "Fxx" };
    Integer expected = 4;
    IPitchUPtr n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue09, Pitch )
{
    String str{ "Cddb" };
    Integer expected = -5;
    IPitchUPtr n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue10, Pitch )
{
    String str{ "Cxx#" };
    Integer expected = 5;
    IPitchUPtr n{ new Pitch{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setAlterValue01, Pitch )
{
    String str{ "Cxx#" };
    Integer setTo = 3;
    Integer expected = setTo;
    IPitchUPtr n{ new Pitch{ str } };
    n->setAlterValue( setTo );
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setAlterValue02, Pitch )
{
    String str{ "Cx" };
    Integer setTo = 0;
    Integer expected = setTo;
    IPitchUPtr n{ new Pitch{ str } };
    n->setAlterValue( setTo );
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setAlterValue03, Pitch )
{
    String str{ "Gb" };
    Integer setTo = 100;
    Integer expected = setTo;
    IPitchUPtr n{ new Pitch{ str } };
    n->setAlterValue( setTo );
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setAlterValue04, Pitch )
{
    String str{ "Gb" };
    Integer setTo = -100;
    Integer expected = setTo;
    IPitchUPtr n{ new Pitch{ str } };
    n->setAlterValue( setTo );
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( incrementAlter, Pitch )
{
    IPitchUPtr n{ new Pitch{ "Eddd" } };
    n->incrementAlter();
    CHECK_EQUAL( -5, n->getAlterValue() )
    n->incrementAlter();
    CHECK_EQUAL( -4, n->getAlterValue() )
    n->incrementAlter();
    CHECK_EQUAL( -3, n->getAlterValue() )
    n->incrementAlter();
    CHECK_EQUAL( -2, n->getAlterValue() )
    n->incrementAlter();
    CHECK_EQUAL( -1, n->getAlterValue() )
    n->incrementAlter();
    CHECK_EQUAL( 0, n->getAlterValue() )
    n->incrementAlter();
    CHECK_EQUAL( 1, n->getAlterValue() )
    n->incrementAlter();
    CHECK_EQUAL( 2, n->getAlterValue() )
    n->incrementAlter();
    CHECK_EQUAL( 3, n->getAlterValue() )
    n->incrementAlter();
    CHECK_EQUAL( 4, n->getAlterValue() )
    n->incrementAlter();
    CHECK_EQUAL( 5, n->getAlterValue() )
    n->incrementAlter();
    CHECK_EQUAL( 6, n->getAlterValue() )
    n->setAlterValue( std::numeric_limits<Integer>::max() );
    CHECK_EQUAL( std::numeric_limits<Integer>::max(), n->getAlterValue() )
    n->incrementAlter();
    CHECK_EQUAL( std::numeric_limits<Integer>::min(), n->getAlterValue() )
}
TEST( decrementAlter, Pitch )
{
    IPitchUPtr n{ new Pitch{ "Exxx" } };
    n->decrementAlter();
    CHECK_EQUAL( 5, n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( 4, n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( 3, n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( 2, n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( 1, n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( 0, n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( -1, n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( -2, n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( -3, n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( -4, n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( -5, n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( -6, n->getAlterValue() )
    n->setAlterValue( std::numeric_limits<Integer>::min() );
    CHECK_EQUAL( std::numeric_limits<Integer>::min(), n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( std::numeric_limits<Integer>::max(), n->getAlterValue() )
}
TEST( getOctave, Pitch )
{
    CHECK( false )
}
TEST( setOctave, Pitch )
{
    CHECK( false )
}
TEST( incrementOctave, Pitch )
{
    CHECK( false )
}
TEST( decrementOctave, Pitch )
{
    CHECK( false )
}
