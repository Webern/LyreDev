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
T_END

TEST( constructor01, PitchName )
{
    PitchNameUP n{ new PitchName{ 1, 2 } };
    CHECK_EQUAL( 1, n->getStepValue() )
    CHECK_EQUAL( 2, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getValue() )
}
T_END

TEST( constructor02, PitchName )
{
    PitchNameUP n{ new PitchName{ "Ab" } };
    CHECK_EQUAL( 5, n->getStepValue() )
    CHECK_EQUAL( -1, n->getAlterValue() )
    CHECK_EQUAL( 8, n->getValue() )
}
T_END

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
T_END

TEST( moveConstructor, PitchName )
{
    PitchName orig{ "B" };
    PitchName copy{ std::move( orig ) };
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 0, copy.getValue() )
}
T_END

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
T_END

TEST( moveAssignment, PitchName )
{
    PitchName orig{ "B" };
    PitchName copy;
    copy.operator=( std::move( orig ) );
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 0, copy.getValue() )
}
T_END

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
T_END

TEST( getValue01, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gddd" );
    CHECK_EQUAL( 1, n->getValue() )
}
T_END

TEST( getValue02, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gddb" );;
    CHECK_EQUAL( 2, n->getValue() )
}
T_END

TEST( getValue03, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gdd" );;
    CHECK_EQUAL( 3, n->getValue() )
}
T_END

TEST( getValue04, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gdb" );;
    CHECK_EQUAL( 4, n->getValue() )
}
T_END

TEST( getValue05, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gd" );;
    CHECK_EQUAL( 5, n->getValue() )
}
T_END

TEST( getValue06, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gb" );;
    CHECK_EQUAL( 6, n->getValue() )
}
T_END

TEST( getValue07, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "G" );;
    CHECK_EQUAL( 7, n->getValue() )
}
T_END

TEST( getValue08, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "G#" );;
    CHECK_EQUAL( 8, n->getValue() )
}
T_END

TEST( getValue09, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gx" );;
    CHECK_EQUAL( 9, n->getValue() )
}
T_END

TEST( getValue10, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gx#" );;
    CHECK_EQUAL( 10, n->getValue() )
}
T_END

TEST( getValue11, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gxx" );;
    CHECK_EQUAL( 11, n->getValue() )
}
T_END

TEST( getValue12, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gxx#" );;
    CHECK_EQUAL( 0, n->getValue() )
}
T_END

TEST( getValue13, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gxxx" );;
    CHECK_EQUAL( 1, n->getValue() )
}
T_END

TEST( getValue14, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dddd" );;
    CHECK_EQUAL( 8, n->getValue() )
}
T_END

TEST( getValue15, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dddb" );;
    CHECK_EQUAL( 9, n->getValue() )
}
T_END

TEST( getValue16, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Ddd" );;
    CHECK_EQUAL( 10, n->getValue() )
}
T_END

TEST( getValue17, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Ddb" );;
    CHECK_EQUAL( 11, n->getValue() )
}
T_END

TEST( getValue18, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dd" );;
    CHECK_EQUAL( 0, n->getValue() )
}
T_END

TEST( getValue19, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Db" );;
    CHECK_EQUAL( 1, n->getValue() )
}
T_END

TEST( getValue20, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "D" );;
    CHECK_EQUAL( 2, n->getValue() )
}
T_END

TEST( getValue21, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "D#" );;
    CHECK_EQUAL( 3, n->getValue() )
}
T_END

TEST( getValue22, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dx" );;
    CHECK_EQUAL( 4, n->getValue() )
}
T_END

TEST( getValue23, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dx#" );;
    CHECK_EQUAL( 5, n->getValue() )
}
T_END

TEST( getValue24, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dxx" );;
    CHECK_EQUAL( 6, n->getValue() )
}
T_END

TEST( getValue25, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dxx#" );;
    CHECK_EQUAL( 7, n->getValue() )
}
T_END

TEST( getValue26, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Dxxx" );;
    CHECK_EQUAL( 8, n->getValue() )
}
T_END

TEST( getValue27, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "B#" );;
    CHECK_EQUAL( 0, n->getValue() )
}
T_END

TEST( getValue28, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "C" );;
    CHECK_EQUAL( 0, n->getValue() )
}
T_END

TEST( getValue29, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Db" );;
    CHECK_EQUAL( 1, n->getValue() )
}
T_END

TEST( getValue30, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "C#" );;
    CHECK_EQUAL( 1, n->getValue() )
}
T_END

TEST( getValue31, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "D" );;
    CHECK_EQUAL( 2, n->getValue() )
}
T_END

TEST( getValue32, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Cx" );;
    CHECK_EQUAL( 2, n->getValue() )
}
T_END

TEST( getValue33, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Eb" );;
    CHECK_EQUAL( 3, n->getValue() )
}
T_END

TEST( getValue34, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "D#" );;
    CHECK_EQUAL( 3, n->getValue() )
}
T_END

TEST( getValue37, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "E" );;
    CHECK_EQUAL( 4, n->getValue() )
}
T_END

TEST( getValue38, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Fb" );;
    CHECK_EQUAL( 4, n->getValue() )
}
T_END

TEST( getValue39, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "F" );;
    CHECK_EQUAL( 5, n->getValue() )
}
T_END

TEST( getValue40, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "E#" );;
    CHECK_EQUAL( 5, n->getValue() )
}
T_END

TEST( getValue41, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gb" );;
    CHECK_EQUAL( 6, n->getValue() )
}
T_END

TEST( getValue42, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "F#" );;
    CHECK_EQUAL( 6, n->getValue() )
}
T_END

TEST( getValue43, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "G" );;
    CHECK_EQUAL( 7, n->getValue() )
}
T_END

TEST( getValue44, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Ad" );;
    CHECK_EQUAL( 7, n->getValue() )
}
T_END

TEST( getValue45, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Ab" );;
    CHECK_EQUAL( 8, n->getValue() )
}
T_END

TEST( getValue46, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "G#" );;
    CHECK_EQUAL( 8, n->getValue() )
}
T_END

TEST( getValue47, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "A" );;
    CHECK_EQUAL( 9, n->getValue() )
}
T_END

TEST( getValue48, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Gx" );;
    CHECK_EQUAL( 9, n->getValue() )
}
T_END

TEST( getValue49, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Bb" );;
    CHECK_EQUAL( 10, n->getValue() )
}
T_END

TEST( getValue50, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "A#" );;
    CHECK_EQUAL( 10, n->getValue() )
}
T_END

TEST( getValue51, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "B" );;
    CHECK_EQUAL( 11, n->getValue() )
}
T_END

TEST( getValue52, PitchName )
{
    PitchNameUP n{ new PitchName{} };
    n->parse( "Cb" );;
    CHECK_EQUAL( 11, n->getValue() )
}
T_END

TEST( parse_fail01, PitchName )
{
    PitchNameUP n{ new PitchName{ "F" } };
    CHECK_EQUAL( 5, n->getValue() )
    CHECK( ! n->parse( "Cbd" ) )
    CHECK_EQUAL( 5, n->getValue() )
}
T_END

TEST( parse_fail02, PitchName )
{
    PitchNameUP n{ new PitchName{ "F#" } };
    CHECK_EQUAL( 6, n->getValue() )
    CHECK( ! n->parse( "H" ) )
    CHECK_EQUAL( 6, n->getValue() )
}
T_END

TEST( parse_fail03, PitchName )
{
    PitchNameUP n{ new PitchName{ "G" } };
    CHECK_EQUAL( 7, n->getValue() )
    CHECK( ! n->parse( "#" ) )
    CHECK_EQUAL( 7, n->getValue() )
}
T_END

TEST( parse_fail04, PitchName )
{
    PitchNameUP n{ new PitchName{ "Ab" } };
    CHECK_EQUAL( 8, n->getValue() )
    CHECK( ! n->parse( "a" ) )
    CHECK_EQUAL( 8, n->getValue() )
}
T_END

TEST( parse_success01, PitchName )
{
    PitchNameUP n{ new PitchName{ "F" } };
    CHECK_EQUAL( 5, n->getValue() )
    CHECK( n->parse( "B#" ) )
    CHECK_EQUAL( 0, n->getValue() )
}
T_END

TEST( parse_success02, PitchName )
{
    PitchNameUP n{ new PitchName{ "F#" } };
    CHECK_EQUAL( 6, n->getValue() )
    CHECK( n->parse( "Bb" ) )
    CHECK_EQUAL( 10, n->getValue() )
}
T_END

TEST( parse_success03, PitchName )
{
    PitchNameUP n{ new PitchName{ "G" } };
    CHECK_EQUAL( 7, n->getValue() )
    CHECK( n->parse( "C#" ) )
    CHECK_EQUAL( 1, n->getValue() )
}
T_END

TEST( parse_success04, PitchName )
{
    PitchNameUP n{ new PitchName{ "Ab" } };
    CHECK_EQUAL( 8, n->getValue() )
    CHECK( n->parse( "Cdb" ) )
    CHECK_EQUAL( 9, n->getValue() )
}
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

TEST( toString00, PitchName )
{
    String str = "Bb";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString01, PitchName )
{
    String str = "Cxxx";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString02, PitchName )
{
    String str = "G#";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString03, PitchName )
{
    String str = "Bb";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString04, PitchName )
{
    String str = "Ed";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString05, PitchName )
{
    String str = "Fb";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString06, PitchName )
{
    String str = "Gb";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString07, PitchName )
{
    String str = "B";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString08, PitchName )
{
    String str = "A";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString09, PitchName )
{
    String str = "Axxxxxxx";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString10, PitchName )
{
    String str = "Edddddddddddddb";
    PitchNameUP n{ new PitchName{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

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
T_END

TEST( getStepValue0, PitchName )
{
    String str = "C";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 0, n->getStepValue() )
}
T_END

TEST( getStepValue1, PitchName )
{
    String str = "Db";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 1, n->getStepValue() )
}
T_END

TEST( getStepValue2, PitchName )
{
    String str = "E#";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 2, n->getStepValue() )
}
T_END

TEST( getStepValue3, PitchName )
{
    String str = "F";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 3, n->getStepValue() )
}
T_END

TEST( getStepValue4, PitchName )
{
    String str = "Gb";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 4, n->getStepValue() )
}
T_END

TEST( getStepValue5, PitchName )
{
    String str = "A#";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 5, n->getStepValue() )
}
T_END

TEST( getStepValue6, PitchName )
{
    String str = "B";
    IPitchNameUP n{ new PitchName{ str } };
    CHECK_EQUAL( 6, n->getStepValue() )
}
T_END

TEST( getMinStepValue, PitchName )
{
    IPitchNameUP n{ new PitchName{ "F" } };
    CHECK_EQUAL( 0, n->getMinStepValue() )
}
T_END

TEST( getMaxStepValue, PitchName )
{
    IPitchNameUP n{ new PitchName{ "F" } };
    CHECK_EQUAL( 6, n->getMaxStepValue() )
}
T_END

TEST( setStepValue0, PitchName )
{
    String str = "F";
    int setTo = 0;
    int expected = 0;
    IPitchNameUP n{ new PitchName{ str } };
    n->setStepValue( setTo );
    int actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( setStepValue1, PitchName )
{
    String str = "G";
    int setTo = 7;
    int expected = 6;
    IPitchNameUP n{ new PitchName{ str } };
    n->setStepValue( setTo );
    int actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( setStepValue2, PitchName )
{
    String str = "D";
    int setTo = -1;
    int expected = 0;
    IPitchNameUP n{ new PitchName{ str } };
    n->setStepValue( setTo );
    int actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
T_END

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
T_END

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
T_END

TEST( getAlterValue00, PitchName )
{
    String str{ "C" };
    int expected = 0;
    IPitchNameUP n{ new PitchName{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue01, PitchName )
{
    String str{ "Fb" };
    int expected = -1;
    IPitchNameUP n{ new PitchName{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue02, PitchName )
{
    String str{ "G#" };
    int expected = 1;
    IPitchNameUP n{ new PitchName{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue03, PitchName )
{
    String str{ "Bd" };
    int expected = -2;
    IPitchNameUP n{ new PitchName{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue04, PitchName )
{
    String str{ "Ax" };
    int expected = 2;
    IPitchNameUP n{ new PitchName{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue05, PitchName )
{
    String str{ "Ddb" };
    int expected = -3;
    IPitchNameUP n{ new PitchName{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue06, PitchName )
{
    String str{ "Cx#" };
    int expected = 3;
    IPitchNameUP n{ new PitchName{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue07, PitchName )
{
    String str{ "Edd" };
    int expected = -4;
    IPitchNameUP n{ new PitchName{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue08, PitchName )
{
    String str{ "Fxx" };
    int expected = 4;
    IPitchNameUP n{ new PitchName{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue09, PitchName )
{
    String str{ "Cddb" };
    int expected = -5;
    IPitchNameUP n{ new PitchName{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue10, PitchName )
{
    String str{ "Cxx#" };
    int expected = 5;
    IPitchNameUP n{ new PitchName{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( setAlterValue01, PitchName )
{
    String str{ "Cxx#" };
    int setTo = 3;
    int expected = setTo;
    IPitchNameUP n{ new PitchName{ str } };
    n->setAlterValue( setTo );
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( setAlterValue02, PitchName )
{
    String str{ "Cx" };
    int setTo = 0;
    int expected = setTo;
    IPitchNameUP n{ new PitchName{ str } };
    n->setAlterValue( setTo );
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( setAlterValue03, PitchName )
{
    String str{ "Gb" };
    int setTo = 100;
    int expected = setTo;
    IPitchNameUP n{ new PitchName{ str } };
    n->setAlterValue( setTo );
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( setAlterValue04, PitchName )
{
    String str{ "Gb" };
    int setTo = -100;
    int expected = setTo;
    IPitchNameUP n{ new PitchName{ str } };
    n->setAlterValue( setTo );
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getMinAlterValue, PitchName )
{
    IPitchNameUP n{ new PitchName{ "D" } };
    int expected = std::numeric_limits<int>::min();
    int actual = n->getMinAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getMaxAlterValue, PitchName )
{
    IPitchNameUP n{ new PitchName{ "E" } };
    int expected = std::numeric_limits<int>::max();
    int actual = n->getMaxAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

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
    n->setAlterValue( std::numeric_limits<int>::max() );
    CHECK_EQUAL( std::numeric_limits<int>::max(), n->getAlterValue() )
    n->incrementAlter();
    CHECK_EQUAL( std::numeric_limits<int>::min(), n->getAlterValue() )
}
T_END

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
    n->setAlterValue( std::numeric_limits<int>::min() );
    CHECK_EQUAL( std::numeric_limits<int>::min(), n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( std::numeric_limits<int>::max(), n->getAlterValue() )
}
T_END

TEST( isIdenticalTo_true01, PitchName )
{
    PitchNameUP a = unique_ptr<PitchName>( new PitchName( "C#" ) );
    PitchNameUP b = unique_ptr<PitchName>( new PitchName( "C#" ) );
    CHECK( a->isIdenticalTo( *b ) )
}
T_END

class MockPitchName1 : public IPitchName
{
public:
    virtual ~MockPitchName1() {}
    virtual IPitchNameUP clone() const
    {
        return std::unique_ptr<MockPitchName1>{ new MockPitchName1{} };
    }
    virtual int getValue() const { return 1; }
    virtual bool parse( const String& str ) { UNUSED_PARAMETER( str ) return true; }
    virtual std::ostream& toStream( std::ostream& os ) const { return os << "C#"; }
    /* virtual String toString() const;
    virtual bool isLessThan( const PitchName& other ) const;
    virtual bool isGreaterThan( const PitchName& other ) const;
    virtual bool isEqualTo( const PitchName& other ) const; */
    virtual bool isIdenticalTo( const IPitchName& other ) const { UNUSED_PARAMETER( other ) return true; }
    virtual int getStepValue() const { return 0; }
    virtual void setStepValue( const int val ) { UNUSED_PARAMETER( val ) }
    virtual int getMinStepValue() const { return 0; }
    virtual int getMaxStepValue() const { return 0; }
    virtual void incrementStep() {}
    virtual void decrementStep() {}
    virtual int getAlterValue() const { return 1; }
    virtual void setAlterValue( const int val ) { UNUSED_PARAMETER( val ) }
    virtual int getMinAlterValue() const { return 0; }
    virtual int getMaxAlterValue() const { return 0; }
    virtual void incrementAlter() {}
    virtual void decrementAlter() {}
};

TEST( isIdenticalTo_true02, PitchName )
{
    PitchNameUP a = unique_ptr<PitchName>( new PitchName( "C#" ) );
    std::unique_ptr<MockPitchName1> b{ new MockPitchName1{} };
    CHECK( a->isIdenticalTo( *b ) )
}
T_END

TEST( isIdenticalTo_false01, PitchName )
{
    PitchNameUP a = unique_ptr<PitchName>( new PitchName( "A" ) );
    PitchNameUP b = unique_ptr<PitchName>( new PitchName( "B" ) );
    CHECK( ! a->isIdenticalTo( *b ) )
}
T_END

class MockPitchName2 : public IPitchName
{
public:
    virtual ~MockPitchName2() {}
    virtual IPitchNameUP clone() const
    {
        return std::unique_ptr<MockPitchName2>{ new MockPitchName2{} };
    }
    virtual int getValue() const { return 1; }
    virtual bool parse( const String& str ) { UNUSED_PARAMETER( str ) return true; }
    virtual std::ostream& toStream( std::ostream& os ) const { return os << "C_"; }
    /* virtual String toString() const;
    virtual bool isLessThan( const PitchName& other ) const;
    virtual bool isGreaterThan( const PitchName& other ) const;
    virtual bool isEqualTo( const PitchName& other ) const; */
    virtual bool isIdenticalTo( const IPitchName& other ) const { UNUSED_PARAMETER( other ) return true; }
    virtual int getStepValue() const { return 0; }
    virtual void setStepValue( const int val ) { UNUSED_PARAMETER( val ) }
    virtual int getMinStepValue() const { return 0; }
    virtual int getMaxStepValue() const { return 0; }
    virtual void incrementStep() {}
    virtual void decrementStep() {}
    virtual int getAlterValue() const { return 1; }
    virtual void setAlterValue( const int val ) { UNUSED_PARAMETER( val ) }
    virtual int getMinAlterValue() const { return 0; }
    virtual int getMaxAlterValue() const { return 0; }
    virtual void incrementAlter() {}
    virtual void decrementAlter() {}
};

TEST( isIdenticalTo_false02, PitchName )
{
    PitchNameUP a = unique_ptr<PitchName>( new PitchName( "C#" ) );
    std::unique_ptr<MockPitchName2> b{ new MockPitchName2{} };
    CHECK( ! a->isIdenticalTo( *b ) )
}
T_END
