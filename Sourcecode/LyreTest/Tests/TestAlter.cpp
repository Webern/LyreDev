//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Private/Alter.h"
#include <sstream>
#include <limits>
#include <iostream>

using namespace Lyre;
using namespace Lyre::Private;
using namespace std;

TEST( Compiles, Alter )
{
    Alter o;
    CHECK( true )
}
TEST( SharedPtr, Alter )
{
    IAlterSP p = std::make_shared<Alter>();
    CHECK( true )
}
TEST( UniquePtr, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    CHECK( true )
}
TEST( Constructor01a, Alter )
{
    Alter s{ 5 };
    CHECK_EQUAL( 5, s.getValue() )
}
TEST( Constructor01b, Alter )
{
    Alter s{ std::numeric_limits<int>::min() };
    CHECK_EQUAL( std::numeric_limits<int>::min(), s.getValue() )
}
TEST( Constructor01c, Alter )
{
    Alter s{ std::numeric_limits<int>::max() };
    CHECK_EQUAL( std::numeric_limits<int>::max(), s.getValue() )
}
TEST( Constructor03a, Alter )
{
    Alter s{ String{ "x#" } };
    CHECK_EQUAL( 3, s.getValue() )
}
TEST( Constructor03b, Alter )
{
    Alter s{ String{ "#x" } };
    CHECK_EQUAL( 0, s.getValue() )
}
TEST( CopyConstructor01, Alter )
{
    Alter a{ 1 };
    Alter b{ a };
    CHECK_EQUAL( 1, a.getValue() )
    CHECK_EQUAL( 1, b.getValue() )
    a.setValue( 2 );
    b.setValue( 5 );
    CHECK_EQUAL( 2, a.getValue() )
    CHECK_EQUAL( 5, b.getValue() )
}
TEST( MoveConstructor01, Alter )
{
    Alter a{ 1 };
    Alter b{ std::move( a ) };
    CHECK_EQUAL( 1, b.getValue() )
    b.setValue( 5 );
    CHECK_EQUAL( 5, b.getValue() )
}
TEST( AssignmentOperator, Alter )
{
    Alter a{ 1 };
    Alter b{ 4 };
    b = a;
    CHECK_EQUAL( 1, a.getValue() )
    CHECK_EQUAL( 1, b.getValue() )
    a.setValue( 2 );
    b.setValue( 5 );
    CHECK_EQUAL( 2, a.getValue() )
    CHECK_EQUAL( 5, b.getValue() )
}
TEST( MoveAssignment, Alter )
{
    Alter a{ 1 };
    Alter b{ 4 };
    b = std::move( a );
    CHECK_EQUAL( 1, b.getValue() )
    b.setValue( 5 );
    CHECK_EQUAL( 5, b.getValue() )
}
TEST( clone, Alter )
{
    IAlterSP p1 = std::make_shared<Alter>();
    p1->setValue( 4 );
    IAlterSP p2 = p1->clone();
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 4, p1->getValue() );
    CHECK_EQUAL( 4, p2->getValue() );
    p2->setValue( 2 );
    CHECK_EQUAL( 4, p1->getValue() );
    CHECK_EQUAL( 2, p2->getValue() );
}
TEST( getMin, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    CHECK_EQUAL( std::numeric_limits<int>::min(), p->getMin() )
}
TEST( getMax, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    CHECK_EQUAL( std::numeric_limits<int>::max(), p->getMax() )
}
TEST( parseSuccess01, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -6 );
    CHECK( p->parse( "" ) )
    CHECK_EQUAL( 0, p->getValue() )
}
TEST( parseSuccess02, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "ddd" ) )
    CHECK_EQUAL( -6, p->getValue() )
}
TEST( parseSuccess03, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "ddb" ) )
    CHECK_EQUAL( -5, p->getValue() )
}
TEST( parseSuccess04, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "dd" ) )
    CHECK_EQUAL( -4, p->getValue() )
}
TEST( parseSuccess05, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "db" ) )
    CHECK_EQUAL( -3, p->getValue() )
}
TEST( parseSuccess06, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "d" ) )
    CHECK_EQUAL( -2, p->getValue() )
}
TEST( parseSuccess07, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "b" ) )
    CHECK_EQUAL( -1, p->getValue() )
}
TEST( parseSuccess08, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "" ) )
    CHECK_EQUAL( 0, p->getValue() )
}
TEST( parseSuccess09, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "#" ) )
    CHECK_EQUAL( 1, p->getValue() )
}
TEST( parseSuccess10, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "x" ) )
    CHECK_EQUAL( 2, p->getValue() )
}
TEST( parseSuccess11, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "x#" ) )
    CHECK_EQUAL( 3, p->getValue() )
}
TEST( parseSuccess12, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "xx" ) )
    CHECK_EQUAL( 4, p->getValue() )
}
TEST( parseSuccess13, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "xx#" ) )
    CHECK_EQUAL( 5, p->getValue() )
}
TEST( parseSuccess14, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "xxx" ) )
    CHECK_EQUAL( 6, p->getValue() )
}
TEST( parseSuccess15, Alter )
{
    String dbl{ "d" };
    String sgl{ "b" };
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    for( int i = 100; i > 0; --i )
    {
        stringstream ss;
        for ( int j = 2; j <= i; j += 2 )
        {
            ss << dbl;
        }
        if ( i % 2 != 0 )
        {
            ss << sgl;
        }
        p->parse( ss.str() );
        CHECK_EQUAL( ( -1 * i ), p->getValue() )
    }
}
TEST( parseSuccess16, Alter )
{
    String dbl{ "x" };
    String sgl{ "#" };
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    for( int i = 0; i > 100; ++i )
    {
        stringstream ss;
        for ( int j = 2; j <= i; j += 2 )
        {
            ss << dbl;
        }
        if ( i % 2 != 0 )
        {
            ss << sgl;
        }
        p->parse( ss.str() );
        CHECK_EQUAL( i, p->getValue() )
    }
}
TEST( parseFail01, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( " " ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail02, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "bd" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail03, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "#b" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail04, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "xb" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail05, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "#d" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail06, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "xd" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail07, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "b#" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail08, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "d#" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail09, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "bx" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail10, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "dx" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail11, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "#x" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail12, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "##" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail13, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "xx##" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail14, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "xxx#x" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail15, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "bd" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail16, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "bb" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail17, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "ddbb" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail18, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "dddbd" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail19, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter( -999 ) );
    char c = std::numeric_limits<char>::min();
    for ( ; c <= std::numeric_limits<char>::min(); ++c )
    {
        if ( c == '#' || c == 'x' || c == 'd' || c == 'b' )
        {
            CHECK( p->parse( String{ c } ) );
        }
        else
        {
            CHECK( ! p->parse( String{ c } ) );
        }
    }
    CHECK( ! ( p->parse( "dddbd" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( toStream01, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -6 );
    stringstream ss;
    p->toStream( ss );
    String expected = "ddd";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toStream02, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -5 );
    stringstream ss;
    p->toStream( ss );
    String expected = "ddb";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toStream03, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -4 );
    stringstream ss;
    p->toStream( ss );
    String expected = "dd";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toStream04, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -3 );
    stringstream ss;
    p->toStream( ss );
    String expected = "db";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toStream05, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -2 );
    stringstream ss;
    p->toStream( ss );
    String expected = "d";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toStream06, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -1 );
    stringstream ss;
    p->toStream( ss );
    String expected = "b";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toStream07, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 0 );
    stringstream ss;
    p->toStream( ss );
    String expected = "";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toStream08, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 1 );
    stringstream ss;
    p->toStream( ss );
    String expected = "#";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toStream09, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 2 );
    stringstream ss;
    p->toStream( ss );
    String expected = "x";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toStream10, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 3 );
    stringstream ss;
    p->toStream( ss );
    String expected = "x#";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toStream11, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 4 );
    stringstream ss;
    p->toStream( ss );
    String expected = "xx";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toStream12, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 5 );
    stringstream ss;
    p->toStream( ss );
    String expected = "xx#";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toStream13, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 6 );
    stringstream ss;
    p->toStream( ss );
    String expected = "xxx";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString01, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -6 );
    stringstream ss;
    ss << p->toString();
    String expected = "ddd";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString02, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -5 );
    stringstream ss;
    ss << p->toString();
    String expected = "ddb";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString03, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -4 );
    stringstream ss;
    ss << p->toString();
    String expected = "dd";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString04, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -3 );
    stringstream ss;
    ss << p->toString();
    String expected = "db";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString05, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -2 );
    stringstream ss;
    ss << p->toString();
    String expected = "d";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString06, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -1 );
    stringstream ss;
    ss << p->toString();
    String expected = "b";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString07, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 0 );
    stringstream ss;
    ss << p->toString();
    String expected = "";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString08, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 1 );
    stringstream ss;
    ss << p->toString();
    String expected = "#";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString09, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 2 );
    stringstream ss;
    ss << p->toString();
    String expected = "x";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString10, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 3 );
    stringstream ss;
    ss << p->toString();
    String expected = "x#";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString11, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 4 );
    stringstream ss;
    ss << p->toString();
    String expected = "xx";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString12, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 5 );
    stringstream ss;
    ss << p->toString();
    String expected = "xx#";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString13, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 6 );
    stringstream ss;
    ss << p->toString();
    String expected = "xxx";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator01, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -6 );
    stringstream ss;
    ss << ( *p );
    String expected = "ddd";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator02, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -5 );
    stringstream ss;
    ss << ( *p );
    String expected = "ddb";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator03, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -4 );
    stringstream ss;
    ss << ( *p );
    String expected = "dd";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator04, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -3 );
    stringstream ss;
    ss << ( *p );
    String expected = "db";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator05, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -2 );
    stringstream ss;
    ss << ( *p );
    String expected = "d";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator06, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( -1 );
    stringstream ss;
    ss << ( *p );
    String expected = "b";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator07, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 0 );
    stringstream ss;
    ss << ( *p );
    String expected = "";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator08, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 1 );
    stringstream ss;
    ss << ( *p );
    String expected = "#";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator09, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 2 );
    stringstream ss;
    ss << ( *p );
    String expected = "x";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator10, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 3 );
    stringstream ss;
    ss << ( *p );
    String expected = "x#";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator11, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 4 );
    stringstream ss;
    ss << ( *p );
    String expected = "xx";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator12, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 5 );
    stringstream ss;
    ss << ( *p );
    String expected = "xx#";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator13, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 6 );
    stringstream ss;
    ss << ( *p );
    String expected = "xxx";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator, Alter )
{
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    p->setValue( 4 );
    stringstream ss;
    ss << ( *p );
    String expected = "xx";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( comparisons_a_isLessThan_b, Alter )
{
    IAlterUP a = unique_ptr<Alter>( new Alter() );
    IAlterUP b = unique_ptr<Alter>( new Alter() );
    a->setValue( 1 );
    b->setValue( 2 );
    CHECK(   a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK(   b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
TEST( comparisons_a_isGreaterThan_b, Alter )
{
    IAlterUP a = unique_ptr<Alter>( new Alter() );
    IAlterUP b = unique_ptr<Alter>( new Alter() );
    a->setValue( 2 );
    b->setValue( 1 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK(   b->isLessThan   ( *a ) )
    CHECK(   a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
TEST( comparisons_a_isEqualTo_b, Alter )
{
    IAlterUP a = unique_ptr<Alter>( new Alter() );
    IAlterUP b = unique_ptr<Alter>( new Alter() );
    a->setValue( 3 );
    b->setValue( 3 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK(   a->isEqualTo     ( *b ) )
    CHECK(   b->isEqualTo     ( *a ) )
}
TEST( increment01, Alter )
{
    IAlterUP a = unique_ptr<Alter>( new Alter() );
    a->setValue( 1 );
    a->increment();
    CHECK_EQUAL( 2, a->getValue() )
}
TEST( increment02, Alter )
{
    IAlterUP a = unique_ptr<Alter>( new Alter() );
    a->setValue( std::numeric_limits<int>::max() );
    CHECK_EQUAL( std::numeric_limits<int>::max(), a->getValue() )
    a->increment();
    CHECK_EQUAL( std::numeric_limits<int>::min(), a->getValue() )
}
TEST( decrement01, Alter )
{
    IAlterUP a = unique_ptr<Alter>( new Alter() );
    a->setValue( 2 );
    a->decrement();
    CHECK_EQUAL( 1, a->getValue() )
}
TEST( decrement02, Alter )
{
    IAlterUP a = unique_ptr<Alter>( new Alter() );
    a->setValue( std::numeric_limits<int>::min() );
    CHECK_EQUAL( std::numeric_limits<int>::min(), a->getValue() )
    a->decrement();
    CHECK_EQUAL( std::numeric_limits<int>::max(), a->getValue() )
}
TEST( checkManyFlatStrings, Alter )
{
    auto a = unique_ptr<Alter>( new Alter() );
    int startValue = 0;
    int endValue = 100;
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    String dbl{ "d" };
    String sgl{ "b" };
    for( int i = startValue; i <= endValue; ++i )
    {
        stringstream ss;
        for ( int j = 2; j <= i; j += 2 )
        {
            if ( i != 0 )
            {
                ss << dbl;
            }
            
        }
        if ( ( i % 2 != 0 ) && i != 0 )
        {
            ss << sgl;
        }
        p->setValue( -1 * i );
        CHECK_EQUAL( ss.str(), p->toString() )
    }
}
TEST( checkManySharpStrings, Alter )
{
    auto a = unique_ptr<Alter>( new Alter() );
    int startValue = 0;
    int endValue = 100;
    IAlterUP p = unique_ptr<Alter>( new Alter() );
    String dbl{ "x" };
    String sgl{ "#" };
    for( int i = startValue; i <= endValue; ++i )
    {
        stringstream ss;
        for ( int j = 2; j <= i; j += 2 )
        {
            if ( i != 0 )
            {
                ss << dbl;
            }
            
        }
        if ( ( i % 2 != 0 ) && i != 0 )
        {
            ss << sgl;
        }
        p->setValue( i );
        CHECK_EQUAL( ss.str(), p->toString() )
    }
}
TEST( isIdenticalTo_true01, Alter )
{
    AlterUP a = unique_ptr<Alter>( new Alter( 5 ) );
    AlterUP b = unique_ptr<Alter>( new Alter( 5 ) );
    CHECK( a->isIdenticalTo( *b ) )
}
TEST( isIdenticalTo_false02, Alter )
{
    AlterUP a = unique_ptr<Alter>( new Alter( 5 ) );
    AlterUP b = unique_ptr<Alter>( new Alter( 4 ) );
    CHECK( ! a->isIdenticalTo( *b ) )
}