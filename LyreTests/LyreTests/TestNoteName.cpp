#include "cpulTestHarness.h"
#include "NoteName.h"
#include <sstream>

using namespace lyre;
using namespace std;


TEST( defaultConstructor, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    CHECK_EQUAL( 0, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( constructor01, NoteName )
{
    NoteNameUPtr n{ new NoteName{ 1, 2 } };
    CHECK_EQUAL( 1, n->getStepValue() )
    CHECK_EQUAL( 2, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( constructor02, NoteName )
{
    NoteNameUPtr n{ new NoteName{ "Ab" } };
    CHECK_EQUAL( 5, n->getStepValue() )
    CHECK_EQUAL( -1, n->getAlterValue() )
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( copyConstructor, NoteName )
{
    NoteName orig{ "B" };
    NoteName copy{ orig };
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( moveConstructor, NoteName )
{
    NoteName orig{ "B" };
    NoteName copy{ std::move( orig ) };
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( assignment, NoteName )
{
    NoteName orig{ "B" };
    NoteName copy;
    copy = orig;
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( moveAssignment, NoteName )
{
    NoteName orig{ "B" };
    NoteName copy;
    copy.operator=( std::move( orig ) );
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( clone, NoteName )
{
    NoteNameUPtr orig{ new NoteName{ "B" } };
    INoteNameUPtr copy;
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
TEST( copyTo, NoteName )
{
    NoteNameUPtr orig{ new NoteName{ "B" } };
    NoteNameUPtr copy;
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

TEST( getValue01, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Gddd" );
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue02, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Gddb" );;
    CHECK_EQUAL( 2, n->getValue() )
}
TEST( getValue03, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Gdd" );;
    CHECK_EQUAL( 3, n->getValue() )
}
TEST( getValue04, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Gdb" );;
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( getValue05, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Gd" );;
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( getValue06, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Gb" );;
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( getValue07, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "G" );;
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( getValue08, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "G#" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue09, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Gx" );;
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( getValue10, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Gx#" );;
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( getValue11, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Gxx" );;
    CHECK_EQUAL( 11, n->getValue() )
}
TEST( getValue12, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Gxx#" );;
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( getValue13, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Gxxx" );;
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue14, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Dddd" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue15, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Dddb" );;
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( getValue16, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Ddd" );;
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( getValue17, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Ddb" );;
    CHECK_EQUAL( 11, n->getValue() )
}
TEST( getValue18, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Dd" );;
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( getValue19, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Db" );;
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue20, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "D" );;
    CHECK_EQUAL( 2, n->getValue() )
}
TEST( getValue21, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "D#" );;
    CHECK_EQUAL( 3, n->getValue() )
}
TEST( getValue22, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Dx" );;
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( getValue23, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Dx#" );;
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( getValue24, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Dxx" );;
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( getValue25, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Dxx#" );;
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( getValue26, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Dxxx" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue27, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "B#" );;
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( getValue28, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "C" );;
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( getValue29, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Db" );;
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue30, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "C#" );;
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue31, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "D" );;
    CHECK_EQUAL( 2, n->getValue() )
}
TEST( getValue32, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Cx" );;
    CHECK_EQUAL( 2, n->getValue() )
}
TEST( getValue33, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Eb" );;
    CHECK_EQUAL( 3, n->getValue() )
}
TEST( getValue34, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "D#" );;
    CHECK_EQUAL( 3, n->getValue() )
}
TEST( getValue37, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "E" );;
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( getValue38, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Fb" );;
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( getValue39, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "F" );;
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( getValue40, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "E#" );;
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( getValue41, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Gb" );;
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( getValue42, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "F#" );;
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( getValue43, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "G" );;
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( getValue44, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Ad" );;
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( getValue45, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Ab" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue46, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "G#" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue47, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "A" );;
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( getValue48, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Gx" );;
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( getValue49, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Bb" );;
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( getValue50, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "A#" );;
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( getValue51, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "B" );;
    CHECK_EQUAL( 11, n->getValue() )
}
TEST( getValue52, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->parse( "Cb" );;
    CHECK_EQUAL( 11, n->getValue() )
}
TEST( parse_fail01, NoteName )
{
    NoteNameUPtr n{ new NoteName{ "F" } };
    CHECK_EQUAL( 5, n->getValue() )
    CHECK( ! n->parse( "Cbd" ) )
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( parse_fail02, NoteName )
{
    NoteNameUPtr n{ new NoteName{ "F#" } };
    CHECK_EQUAL( 6, n->getValue() )
    CHECK( ! n->parse( "H" ) )
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( parse_fail03, NoteName )
{
    NoteNameUPtr n{ new NoteName{ "G" } };
    CHECK_EQUAL( 7, n->getValue() )
    CHECK( ! n->parse( "#" ) )
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( parse_fail04, NoteName )
{
    NoteNameUPtr n{ new NoteName{ "Ab" } };
    CHECK_EQUAL( 8, n->getValue() )
    CHECK( ! n->parse( "a" ) )
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( parse_success01, NoteName )
{
    NoteNameUPtr n{ new NoteName{ "F" } };
    CHECK_EQUAL( 5, n->getValue() )
    CHECK( n->parse( "B#" ) )
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( parse_success02, NoteName )
{
    NoteNameUPtr n{ new NoteName{ "F#" } };
    CHECK_EQUAL( 6, n->getValue() )
    CHECK( n->parse( "Bb" ) )
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( parse_success03, NoteName )
{
    NoteNameUPtr n{ new NoteName{ "G" } };
    CHECK_EQUAL( 7, n->getValue() )
    CHECK( n->parse( "C#" ) )
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( parse_success04, NoteName )
{
    NoteNameUPtr n{ new NoteName{ "Ab" } };
    CHECK_EQUAL( 8, n->getValue() )
    CHECK( n->parse( "Cdb" ) )
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( toStream00, NoteName )
{
    String str = "Bb";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream01, NoteName )
{
    String str = "Cxxx";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream02, NoteName )
{
    String str = "G#";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream03, NoteName )
{
    String str = "Bb";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream04, NoteName )
{
    String str = "Ed";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream05, NoteName )
{
    String str = "Fb";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream06, NoteName )
{
    String str = "Gb";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream07, NoteName )
{
    String str = "B";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream08, NoteName )
{
    String str = "A";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream09, NoteName )
{
    String str = "Axxxxxxx";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream10, NoteName )
{
    String str = "Edddddddddddddb";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator00, NoteName )
{
    String str = "Bb";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator01, NoteName )
{
    String str = "Cxxx";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator02, NoteName )
{
    String str = "G#";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator03, NoteName )
{
    String str = "Bb";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator04, NoteName )
{
    String str = "Ed";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator05, NoteName )
{
    String str = "Fb";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator06, NoteName )
{
    String str = "Gb";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator07, NoteName )
{
    String str = "B";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator08, NoteName )
{
    String str = "A";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator09, NoteName )
{
    String str = "Axxxxxxx";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator10, NoteName )
{
    String str = "Edddddddddddddb";
    NoteNameUPtr n{ new NoteName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toString00, NoteName )
{
    String str = "Bb";
    NoteNameUPtr n{ new NoteName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString01, NoteName )
{
    String str = "Cxxx";
    NoteNameUPtr n{ new NoteName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString02, NoteName )
{
    String str = "G#";
    NoteNameUPtr n{ new NoteName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString03, NoteName )
{
    String str = "Bb";
    NoteNameUPtr n{ new NoteName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString04, NoteName )
{
    String str = "Ed";
    NoteNameUPtr n{ new NoteName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString05, NoteName )
{
    String str = "Fb";
    NoteNameUPtr n{ new NoteName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString06, NoteName )
{
    String str = "Gb";
    NoteNameUPtr n{ new NoteName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString07, NoteName )
{
    String str = "B";
    NoteNameUPtr n{ new NoteName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString08, NoteName )
{
    String str = "A";
    NoteNameUPtr n{ new NoteName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString09, NoteName )
{
    String str = "Axxxxxxx";
    NoteNameUPtr n{ new NoteName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString10, NoteName )
{
    String str = "Edddddddddddddb";
    NoteNameUPtr n{ new NoteName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}

TEST( compare_a_lessThan_b_01, NoteName )
{
    String a_str = "B#";
    String b_str = "Db";
    INoteNameUPtr a{ new NoteName{ a_str } };
    INoteNameUPtr b{ new NoteName{ b_str } };
    CHECK(   ( a->lessThan( *b ) ) )
    CHECK( ! ( a->equals( *b ) ) )
    CHECK( ! ( a->greaterThan( *b ) ) )
}
TEST( compare_a_lessThan_b_02, NoteName )
{
    String a_str = "Axx";
    String b_str = "Eb";
    INoteNameUPtr a{ new NoteName{ a_str } };
    INoteNameUPtr b{ new NoteName{ b_str } };
    CHECK(   ( a->lessThan( *b ) ) )
    CHECK( ! ( a->equals( *b ) ) )
    CHECK( ! ( a->greaterThan( *b ) ) )
}
TEST( compare_a_equals_b_01, NoteName )
{
    String a_str = "F#";
    String b_str = "Gb";
    INoteNameUPtr a{ new NoteName{ a_str } };
    INoteNameUPtr b{ new NoteName{ b_str } };
    CHECK( ! ( a->lessThan( *b ) ) )
    CHECK(   ( a->equals( *b ) ) )
    CHECK( ! ( a->greaterThan( *b ) ) )
}
TEST( compare_a_equals_b_02, NoteName )
{
    String a_str = "Cd";
    String b_str = "Gx#";
    INoteNameUPtr a{ new NoteName{ a_str } };
    INoteNameUPtr b{ new NoteName{ b_str } };
    CHECK( ! ( a->lessThan( *b ) ) )
    CHECK(   ( a->equals( *b ) ) )
    CHECK( ! ( a->greaterThan( *b ) ) )
}
TEST( compare_a_greaterThan_b_01, NoteName )
{
    String a_str = "Cb";
    String b_str = "Gx#";
    INoteNameUPtr a{ new NoteName{ a_str } };
    INoteNameUPtr b{ new NoteName{ b_str } };
    CHECK( ! ( a->lessThan( *b ) ) )
    CHECK( ! ( a->equals( *b ) ) )
    CHECK(   ( a->greaterThan( *b ) ) )
}
TEST( compare_a_greaterThan_b_02, NoteName )
{
    String a_str = "F";
    String b_str = "E";
    INoteNameUPtr a{ new NoteName{ a_str } };
    INoteNameUPtr b{ new NoteName{ b_str } };
    CHECK( ! ( a->lessThan( *b ) ) )
    CHECK( ! ( a->equals( *b ) ) )
    CHECK(   ( a->greaterThan( *b ) ) )
}