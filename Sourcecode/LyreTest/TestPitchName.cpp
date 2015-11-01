//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Private/PitchName.h"
#include <sstream>

using namespace Lyre;
using namespace Lyre::Private;
using namespace std;


TEST( defaultConstructor, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    CHECK_EQUAL( 0, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( constructor01, PitchName )
{
    PitchNameUP n{ new PitchName{ 1, 2 } };
    CHECK_EQUAL( 1, n->getStepValue() )
    CHECK_EQUAL( 2, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( constructor02, PitchName )
{
    PitchNameUP n{ new PitchName{ "Ab" } };
    CHECK_EQUAL( 5, n->getStepValue() )
    CHECK_EQUAL( -1, n->getAlterValue() )
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( copyConstructor, PitchName )
{
    PitchName orig{ "B" };
    PitchName copy{ orig };
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( moveConstructor, PitchName )
{
    PitchName orig{ "B" };
    PitchName copy{ std::move( orig ) };
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( assignment, PitchName )
{
    PitchName orig{ "B" };
    PitchName copy;
    copy = orig;
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( moveAssignment, PitchName )
{
    PitchName orig{ "B" };
    PitchName copy;
    copy.operator=( std::move( orig ) );
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( clone, PitchName )
{
    PitchNameUP orig{ new PitchName{ "B" } };
    IPitchNameUP copy;
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
TEST( copyTo, PitchName )
{
    PitchNameUP orig{ new PitchName{ "B" } };
    PitchNameUP copy;
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

TEST( getValue01, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gddd" );
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue02, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gddb" );;
    CHECK_EQUAL( 2, n->getValue() )
}
TEST( getValue03, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gdd" );;
    CHECK_EQUAL( 3, n->getValue() )
}
TEST( getValue04, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gdb" );;
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( getValue05, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gd" );;
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( getValue06, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gb" );;
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( getValue07, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "G" );;
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( getValue08, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "G#" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue09, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gx" );;
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( getValue10, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gx#" );;
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( getValue11, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gxx" );;
    CHECK_EQUAL( 11, n->getValue() )
}
TEST( getValue12, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gxx#" );;
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( getValue13, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gxxx" );;
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue14, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dddd" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue15, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dddb" );;
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( getValue16, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Ddd" );;
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( getValue17, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Ddb" );;
    CHECK_EQUAL( 11, n->getValue() )
}
TEST( getValue18, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dd" );;
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( getValue19, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Db" );;
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue20, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "D" );;
    CHECK_EQUAL( 2, n->getValue() )
}
TEST( getValue21, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "D#" );;
    CHECK_EQUAL( 3, n->getValue() )
}
TEST( getValue22, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dx" );;
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( getValue23, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dx#" );;
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( getValue24, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dxx" );;
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( getValue25, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dxx#" );;
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( getValue26, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dxxx" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue27, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "B#" );;
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( getValue28, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "C" );;
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( getValue29, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Db" );;
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue30, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "C#" );;
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( getValue31, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "D" );;
    CHECK_EQUAL( 2, n->getValue() )
}
TEST( getValue32, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Cx" );;
    CHECK_EQUAL( 2, n->getValue() )
}
TEST( getValue33, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Eb" );;
    CHECK_EQUAL( 3, n->getValue() )
}
TEST( getValue34, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "D#" );;
    CHECK_EQUAL( 3, n->getValue() )
}
TEST( getValue37, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "E" );;
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( getValue38, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Fb" );;
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( getValue39, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "F" );;
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( getValue40, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "E#" );;
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( getValue41, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gb" );;
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( getValue42, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "F#" );;
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( getValue43, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "G" );;
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( getValue44, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Ad" );;
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( getValue45, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Ab" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue46, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "G#" );;
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( getValue47, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "A" );;
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( getValue48, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gx" );;
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( getValue49, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Bb" );;
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( getValue50, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "A#" );;
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( getValue51, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "B" );;
    CHECK_EQUAL( 11, n->getValue() )
}
TEST( getValue52, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Cb" );;
    CHECK_EQUAL( 11, n->getValue() )
}
TEST( parse_fail01, PitchName )
{
    PitchNameUP n{ new PitchName{ "F" } };
    CHECK_EQUAL( 5, n->getValue() )
    CHECK( ! n->parse( "Cbd" ) )
    CHECK_EQUAL( 5, n->getValue() )
}
TEST( parse_fail02, PitchName )
{
    PitchNameUP n{ new PitchName{ "F#" } };
    CHECK_EQUAL( 6, n->getValue() )
    CHECK( ! n->parse( "H" ) )
    CHECK_EQUAL( 6, n->getValue() )
}
TEST( parse_fail03, PitchName )
{
    PitchNameUP n{ new PitchName{ "G" } };
    CHECK_EQUAL( 7, n->getValue() )
    CHECK( ! n->parse( "#" ) )
    CHECK_EQUAL( 7, n->getValue() )
}
TEST( parse_fail04, PitchName )
{
    PitchNameUP n{ new PitchName{ "Ab" } };
    CHECK_EQUAL( 8, n->getValue() )
    CHECK( ! n->parse( "a" ) )
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( parse_success01, PitchName )
{
    PitchNameUP n{ new PitchName{ "F" } };
    CHECK_EQUAL( 5, n->getValue() )
    CHECK( n->parse( "B#" ) )
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( parse_success02, PitchName )
{
    PitchNameUP n{ new PitchName{ "F#" } };
    CHECK_EQUAL( 6, n->getValue() )
    CHECK( n->parse( "Bb" ) )
    CHECK_EQUAL( 10, n->getValue() )
}
TEST( parse_success03, PitchName )
{
    PitchNameUP n{ new PitchName{ "G" } };
    CHECK_EQUAL( 7, n->getValue() )
    CHECK( n->parse( "C#" ) )
    CHECK_EQUAL( 1, n->getValue() )
}
TEST( parse_success04, PitchName )
{
    PitchNameUP n{ new PitchName{ "Ab" } };
    CHECK_EQUAL( 8, n->getValue() )
    CHECK( n->parse( "Cdb" ) )
    CHECK_EQUAL( 9, n->getValue() )
}
TEST( toStream00, PitchName )
{
    String str = "Bb";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream01, PitchName )
{
    String str = "Cxxx";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream02, PitchName )
{
    String str = "G#";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream03, PitchName )
{
    String str = "Bb";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream04, PitchName )
{
    String str = "Ed";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream05, PitchName )
{
    String str = "Fb";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream06, PitchName )
{
    String str = "Gb";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream07, PitchName )
{
    String str = "B";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream08, PitchName )
{
    String str = "A";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream09, PitchName )
{
    String str = "Axxxxxxx";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toStream10, PitchName )
{
    String str = "Edddddddddddddb";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator00, PitchName )
{
    String str = "Bb";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator01, PitchName )
{
    String str = "Cxxx";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator02, PitchName )
{
    String str = "G#";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator03, PitchName )
{
    String str = "Bb";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator04, PitchName )
{
    String str = "Ed";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator05, PitchName )
{
    String str = "Fb";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator06, PitchName )
{
    String str = "Gb";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator07, PitchName )
{
    String str = "B";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator08, PitchName )
{
    String str = "A";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator09, PitchName )
{
    String str = "Axxxxxxx";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator10, PitchName )
{
    String str = "Edddddddddddddb";
    PitchNameUP n{ new PitchName{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
TEST( toString00, PitchName )
{
    String str = "Bb";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString01, PitchName )
{
    String str = "Cxxx";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString02, PitchName )
{
    String str = "G#";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString03, PitchName )
{
    String str = "Bb";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString04, PitchName )
{
    String str = "Ed";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString05, PitchName )
{
    String str = "Fb";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString06, PitchName )
{
    String str = "Gb";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString07, PitchName )
{
    String str = "B";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString08, PitchName )
{
    String str = "A";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString09, PitchName )
{
    String str = "Axxxxxxx";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
TEST( toString10, PitchName )
{
    String str = "Edddddddddddddb";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}

TEST( compare_a_isLessThan_b_01, PitchName )
{
    String a_str = "B#";
    String b_str = "Db";
    IPitchNameUP a{ new PitchName{ a_str } };
    IPitchNameUP b{ new PitchName{ b_str } };
    CHECK(   ( a->isLessThan( *b ) ) )
    CHECK( ! ( a->isEqualTo( *b ) ) )
    CHECK( ! ( a->isGreaterThan( *b ) ) )
}
TEST( compare_a_isLessThan_b_02, PitchName )
{
    String a_str = "Axx";
    String b_str = "Eb";
    IPitchNameUP a{ new PitchName{ a_str } };
    IPitchNameUP b{ new PitchName{ b_str } };
    CHECK(   ( a->isLessThan( *b ) ) )
    CHECK( ! ( a->isEqualTo( *b ) ) )
    CHECK( ! ( a->isGreaterThan( *b ) ) )
}
TEST( compare_a_isEqualTo_b_01, PitchName )
{
    String a_str = "F#";
    String b_str = "Gb";
    IPitchNameUP a{ new PitchName{ a_str } };
    IPitchNameUP b{ new PitchName{ b_str } };
    CHECK( ! ( a->isLessThan( *b ) ) )
    CHECK(   ( a->isEqualTo( *b ) ) )
    CHECK( ! ( a->isGreaterThan( *b ) ) )
}
TEST( compare_a_isEqualTo_b_02, PitchName )
{
    String a_str = "Cd";
    String b_str = "Gx#";
    IPitchNameUP a{ new PitchName{ a_str } };
    IPitchNameUP b{ new PitchName{ b_str } };
    CHECK( ! ( a->isLessThan( *b ) ) )
    CHECK(   ( a->isEqualTo( *b ) ) )
    CHECK( ! ( a->isGreaterThan( *b ) ) )
}
TEST( compare_a_isGreaterThan_b_01, PitchName )
{
    String a_str = "Cb";
    String b_str = "Gx#";
    IPitchNameUP a{ new PitchName{ a_str } };
    IPitchNameUP b{ new PitchName{ b_str } };
    CHECK( ! ( a->isLessThan( *b ) ) )
    CHECK( ! ( a->isEqualTo( *b ) ) )
    CHECK(   ( a->isGreaterThan( *b ) ) )
}
TEST( compare_a_isGreaterThan_b_02, PitchName )
{
    String a_str = "F";
    String b_str = "E";
    IPitchNameUP a{ new PitchName{ a_str } };
    IPitchNameUP b{ new PitchName{ b_str } };
    CHECK( ! ( a->isLessThan( *b ) ) )
    CHECK( ! ( a->isEqualTo( *b ) ) )
    CHECK(   ( a->isGreaterThan( *b ) ) )
}
TEST( getStepValue0, PitchName )
{
    String str = "C";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 0, n->getStepValue() )
}
TEST( getStepValue1, PitchName )
{
    String str = "Db";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 1, n->getStepValue() )
}
TEST( getStepValue2, PitchName )
{
    String str = "E#";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 2, n->getStepValue() )
}
TEST( getStepValue3, PitchName )
{
    String str = "F";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 3, n->getStepValue() )
}
TEST( getStepValue4, PitchName )
{
    String str = "Gb";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 4, n->getStepValue() )
}
TEST( getStepValue5, PitchName )
{
    String str = "A#";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 5, n->getStepValue() )
}
TEST( getStepValue6, PitchName )
{
    String str = "B";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 6, n->getStepValue() )
}
TEST( getMinStepValue, PitchName )
{
    IPitchNameUP n{ new PitchName{ "F" } };
    CHECK_EQUAL( 0, n->getMinStepValue() )
}
TEST( getMaxStepValue, PitchName )
{
    IPitchNameUP n{ new PitchName{ "F" } };
    CHECK_EQUAL( 6, n->getMaxStepValue() )
}
TEST( setStepValue0, PitchName )
{
    String str = "F";
    Integer setTo = 0;
    Integer expected = 0;
    IPitchNameUP n{ new PitchName{ str } };
    n->setStepValue( setTo );
    Integer actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setStepValue1, PitchName )
{
    String str = "G";
    Integer setTo = 7;
    Integer expected = 6;
    IPitchNameUP n{ new PitchName{ str } };
    n->setStepValue( setTo );
    Integer actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setStepValue2, PitchName )
{
    String str = "D";
    Integer setTo = -1;
    Integer expected = 0;
    IPitchNameUP n{ new PitchName{ str } };
    n->setStepValue( setTo );
    Integer actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
TEST( incrementStep, PitchName )
{
    IPitchNameUP n{ new PitchName{ "C" } };
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
TEST( decrementStep, PitchName )
{
    IPitchNameUP n{ new PitchName{ "C" } };
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
TEST( getAlterValue00, PitchName )
{
    String str{ "C" };
    Integer expected = 0;
    IPitchNameUP n{ new PitchName{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue01, PitchName )
{
    String str{ "Fb" };
    Integer expected = -1;
    IPitchNameUP n{ new PitchName{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue02, PitchName )
{
    String str{ "G#" };
    Integer expected = 1;
    IPitchNameUP n{ new PitchName{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue03, PitchName )
{
    String str{ "Bd" };
    Integer expected = -2;
    IPitchNameUP n{ new PitchName{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue04, PitchName )
{
    String str{ "Ax" };
    Integer expected = 2;
    IPitchNameUP n{ new PitchName{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue05, PitchName )
{
    String str{ "Ddb" };
    Integer expected = -3;
    IPitchNameUP n{ new PitchName{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue06, PitchName )
{
    String str{ "Cx#" };
    Integer expected = 3;
    IPitchNameUP n{ new PitchName{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue07, PitchName )
{
    String str{ "Edd" };
    Integer expected = -4;
    IPitchNameUP n{ new PitchName{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue08, PitchName )
{
    String str{ "Fxx" };
    Integer expected = 4;
    IPitchNameUP n{ new PitchName{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue09, PitchName )
{
    String str{ "Cddb" };
    Integer expected = -5;
    IPitchNameUP n{ new PitchName{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getAlterValue10, PitchName )
{
    String str{ "Cxx#" };
    Integer expected = 5;
    IPitchNameUP n{ new PitchName{ str } };
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setAlterValue01, PitchName )
{
    String str{ "Cxx#" };
    Integer setTo = 3;
    Integer expected = setTo;
    IPitchNameUP n{ new PitchName{ str } };
    n->setAlterValue( setTo );
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setAlterValue02, PitchName )
{
    String str{ "Cx" };
    Integer setTo = 0;
    Integer expected = setTo;
    IPitchNameUP n{ new PitchName{ str } };
    n->setAlterValue( setTo );
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setAlterValue03, PitchName )
{
    String str{ "Gb" };
    Integer setTo = 100;
    Integer expected = setTo;
    IPitchNameUP n{ new PitchName{ str } };
    n->setAlterValue( setTo );
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( setAlterValue04, PitchName )
{
    String str{ "Gb" };
    Integer setTo = -100;
    Integer expected = setTo;
    IPitchNameUP n{ new PitchName{ str } };
    n->setAlterValue( setTo );
    Integer actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getMinAlterValue, PitchName )
{
    IPitchNameUP n{ new PitchName{ "D" } };
    Integer expected = std::numeric_limits<Integer>::min();
    Integer actual = n->getMinAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( getMaxAlterValue, PitchName )
{
    IPitchNameUP n{ new PitchName{ "E" } };
    Integer expected = std::numeric_limits<Integer>::max();
    Integer actual = n->getMaxAlterValue();
    CHECK_EQUAL( expected, actual )
}
TEST( incrementAlter, PitchName )
{
    IPitchNameUP n{ new PitchName{ "Eddd" } };
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
TEST( decrementAlter, PitchName )
{
    IPitchNameUP n{ new PitchName{ "Exxx" } };
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
TEST( isIdenticalTo_true01, PitchName )
{
    PitchNameUP a = unique_ptr<PitchName>( new PitchName( "C#" ) );
    PitchNameUP b = unique_ptr<PitchName>( new PitchName( "C#" ) );
    CHECK( a->isIdenticalTo( *b ) )
}
TEST( isIdenticalTo_true02, PitchName )
{
    class MockPitchName1 : public IPitchName
    {
    public:
        virtual ~MockPitchName1() {}
        virtual IPitchNameUP clone() const { return std::unique_ptr<MockPitchName1>{ new MockPitchName1{} }; }
        /* template <typename T>
         void copyTo( std::unique_ptr<T>& output ) const */
        virtual Integer getValue() const { return 1; }
        virtual bool parse( const String& str ) { return true; }
        virtual std::ostream& toStream( std::ostream& os ) const { return os << "C#"; }
        /* virtual String toString() const;
         virtual bool isLessThan( const PitchName& other ) const;
         virtual bool isGreaterThan( const PitchName& other ) const;
         virtual bool isEqualTo( const PitchName& other ) const; */
        virtual bool isIdenticalTo( const IPitchName& other ) const { return true; }
        virtual Integer getStepValue() const { return 0; }
        virtual void setStepValue( const Integer val ) {}
        virtual Integer getMinStepValue() const { return 0; }
        virtual Integer getMaxStepValue() const { return 0; }
        virtual void incrementStep() {}
        virtual void decrementStep() {}
        virtual Integer getAlterValue() const { return 1; }
        virtual void setAlterValue( const Integer val ) {}
        virtual Integer getMinAlterValue() const { return 0; }
        virtual Integer getMaxAlterValue() const { return 0; }
        virtual void incrementAlter() {}
        virtual void decrementAlter() {}
    };
    
    PitchNameUP a = unique_ptr<PitchName>( new PitchName( "C#" ) );
    std::unique_ptr<MockPitchName1> b{ new MockPitchName1{} };
    CHECK( a->isIdenticalTo( *b ) )
}
TEST( isIdenticalTo_false01, PitchName )
{
    PitchNameUP a = unique_ptr<PitchName>( new PitchName( "A" ) );
    PitchNameUP b = unique_ptr<PitchName>( new PitchName( "B" ) );
    CHECK( ! a->isIdenticalTo( *b ) )
}
TEST( isIdenticalTo_false02, PitchName )
{
    class MockPitchName2 : public IPitchName
    {
    public:
        virtual ~MockPitchName2() {}
        virtual IPitchNameUP clone() const { return std::unique_ptr<MockPitchName2>{ new MockPitchName2{} }; }
        /* template <typename T>
         void copyTo( std::unique_ptr<T>& output ) const */
        virtual Integer getValue() const { return 1; }
        virtual bool parse( const String& str ) { return true; }
        virtual std::ostream& toStream( std::ostream& os ) const { return os << "C_"; }
        /* virtual String toString() const;
         virtual bool isLessThan( const PitchName& other ) const;
         virtual bool isGreaterThan( const PitchName& other ) const;
         virtual bool isEqualTo( const PitchName& other ) const; */
        virtual bool isIdenticalTo( const IPitchName& other ) const { return true; }
        virtual Integer getStepValue() const { return 0; }
        virtual void setStepValue( const Integer val ) {}
        virtual Integer getMinStepValue() const { return 0; }
        virtual Integer getMaxStepValue() const { return 0; }
        virtual void incrementStep() {}
        virtual void decrementStep() {}
        virtual Integer getAlterValue() const { return 1; }
        virtual void setAlterValue( const Integer val ) {}
        virtual Integer getMinAlterValue() const { return 0; }
        virtual Integer getMaxAlterValue() const { return 0; }
        virtual void incrementAlter() {}
        virtual void decrementAlter() {}
    };
    
    PitchNameUP a = unique_ptr<PitchName>( new PitchName( "C#" ) );
    std::unique_ptr<MockPitchName2> b{ new MockPitchName2{} };
    CHECK( ! a->isIdenticalTo( *b ) )
}