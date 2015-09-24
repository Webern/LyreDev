#include "cpulTestHarness.h"
#include "Alter.h"
#include <sstream>
#include <limits>
#include <iostream>

using namespace lyre;
using namespace std;

TEST( Compiles, Alter )
{
    Alter o;
    CHECK( true )
}
TEST( SharedPtr, Alter )
{
    IAlterPtr p = std::make_shared<Alter>();
    CHECK( true )
}
TEST( UniquePtr, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    CHECK( true )
}

TEST( Constructor01a, Alter )
{
    Alter s{ 5 };
    CHECK_EQUAL( 5, s.getValue() )
}
TEST( Constructor01b, Alter )
{
    Alter s{ std::numeric_limits<Integer>::min() };
    CHECK_EQUAL( std::numeric_limits<Integer>::min(), s.getValue() )
}
TEST( Constructor01c, Alter )
{
    Alter s{ std::numeric_limits<Integer>::max() };
    CHECK_EQUAL( std::numeric_limits<Integer>::max(), s.getValue() )
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
    IAlterPtr p1 = std::make_shared<Alter>();
    p1->setValue( 4 );
    IAlterPtr p2 = p1->clone();
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 4, p1->getValue() );
    CHECK_EQUAL( 4, p2->getValue() );
    p2->setValue( 2 );
    CHECK_EQUAL( 4, p1->getValue() );
    CHECK_EQUAL( 2, p2->getValue() );
}
TEST( copyTo, Alter )
{
    std::shared_ptr<Alter> p1 = std::make_shared<Alter>();
    p1->setValue( -1 );
    std::shared_ptr<Alter> p2;
    p1->copyTo( p2 );
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 0, p1->getValue() );
    CHECK_EQUAL( 0, p2->getValue() );
    p2->setValue( 200 );
    CHECK_EQUAL( 0, p1->getValue() );
    CHECK_EQUAL( 200, p2->getValue() );
}
TEST( getMin, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    CHECK_EQUAL( std::numeric_limits<Integer>::min(), p->getMin() )
}
TEST( getMax, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    CHECK_EQUAL( std::numeric_limits<Integer>::max(), p->getMax() )
}
TEST( parseSuccess01, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -6 );
    CHECK( p->parse( "" ) )
    CHECK_EQUAL( 0, p->getValue() )
}
TEST( parseSuccess02, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "ddd" ) )
    CHECK_EQUAL( -6, p->getValue() )
}
TEST( parseSuccess03, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "ddb" ) )
    CHECK_EQUAL( -5, p->getValue() )
}
TEST( parseSuccess04, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "dd" ) )
    CHECK_EQUAL( -4, p->getValue() )
}
TEST( parseSuccess05, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "db" ) )
    CHECK_EQUAL( -3, p->getValue() )
}
TEST( parseSuccess06, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "d" ) )
    CHECK_EQUAL( -2, p->getValue() )
}
TEST( parseSuccess07, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "b" ) )
    CHECK_EQUAL( -1, p->getValue() )
}
TEST( parseSuccess08, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "" ) )
    CHECK_EQUAL( 0, p->getValue() )
}
TEST( parseSuccess09, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "#" ) )
    CHECK_EQUAL( 1, p->getValue() )
}
TEST( parseSuccess10, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "x" ) )
    CHECK_EQUAL( 2, p->getValue() )
}
TEST( parseSuccess11, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "x#" ) )
    CHECK_EQUAL( 3, p->getValue() )
}
TEST( parseSuccess12, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "xx" ) )
    CHECK_EQUAL( 4, p->getValue() )
}
TEST( parseSuccess13, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "xx#" ) )
    CHECK_EQUAL( 5, p->getValue() )
}
TEST( parseSuccess14, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( -999 );
    CHECK( p->parse( "xxx" ) )
    CHECK_EQUAL( 6, p->getValue() )
}
TEST( parseSuccess15, Alter )
{
    String dbl{ "d" };
    String sgl{ "b" };
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    for( Integer i = 100000; i > 0; --i )
    {
        stringstream ss;
        for ( Integer j = 2; j <= i; j += 2 )
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
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    for( Integer i = 0; i > 100000; ++i )
    {
        stringstream ss;
        for ( Integer j = 2; j <= i; j += 2 )
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
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( " " ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail02, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "bd" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail03, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "#b" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail04, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "xb" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail05, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "#d" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail06, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "xd" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail07, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "b#" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail08, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "d#" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail09, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "bx" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail10, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "dx" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail11, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "#x" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail12, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "##" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail13, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "xx##" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail14, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "xxx#x" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail15, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "bd" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail16, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "bb" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail17, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "ddbb" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( parseFail18, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter( -999 ) );
    CHECK( ! ( p->parse( "dddbd" ) ) )
    CHECK_EQUAL( -999, p->getValue() )
}
TEST( toStream, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( 1 );
    stringstream ss;
    p->toStream( ss );
    String expected = "D";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( 6 );
    String expected = "B";
    String actual{ p->toString() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( 4 );
    stringstream ss;
    ss << ( *p );
    String expected = "G";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( comparisons_a_lessThan_b, Alter )
{
    IAlterUPtr a = unique_ptr<Alter>( new Alter() );
    IAlterUPtr b = unique_ptr<Alter>( new Alter() );
    a->setValue( 1 );
    b->setValue( 2 );
    CHECK(   a->lessThan   ( *b ) )
    CHECK( ! b->lessThan   ( *a ) )
    CHECK( ! a->greaterThan( *b ) )
    CHECK(   b->greaterThan( *a ) )
    CHECK( ! a->equals     ( *b ) )
    CHECK( ! b->equals     ( *a ) )
}
TEST( comparisons_a_greaterThan_b, Alter )
{
    IAlterUPtr a = unique_ptr<Alter>( new Alter() );
    IAlterUPtr b = unique_ptr<Alter>( new Alter() );
    a->setValue( 2 );
    b->setValue( 1 );
    CHECK( ! a->lessThan   ( *b ) )
    CHECK(   b->lessThan   ( *a ) )
    CHECK(   a->greaterThan( *b ) )
    CHECK( ! b->greaterThan( *a ) )
    CHECK( ! a->equals     ( *b ) )
    CHECK( ! b->equals     ( *a ) )
}
TEST( comparisons_a_equals_b, Alter )
{
    IAlterUPtr a = unique_ptr<Alter>( new Alter() );
    IAlterUPtr b = unique_ptr<Alter>( new Alter() );
    a->setValue( 3 );
    b->setValue( 3 );
    CHECK( ! a->lessThan   ( *b ) )
    CHECK( ! b->lessThan   ( *a ) )
    CHECK( ! a->greaterThan( *b ) )
    CHECK( ! b->greaterThan( *a ) )
    CHECK(   a->equals     ( *b ) )
    CHECK(   b->equals     ( *a ) )
}
TEST( increment01, Alter )
{
    IAlterUPtr a = unique_ptr<Alter>( new Alter() );
    a->setValue( 1 );
    a->increment();
    CHECK_EQUAL( 2, a->getValue() )
}
TEST( increment02, Alter )
{
    IAlterUPtr a = unique_ptr<Alter>( new Alter() );
    a->setValue( 2 );
    a->increment();
    CHECK_EQUAL( 3, a->getValue() )
    a->increment();
    CHECK_EQUAL( 4, a->getValue() )
    a->increment();
    CHECK_EQUAL( 5, a->getValue() )
    a->increment();
    CHECK_EQUAL( 6, a->getValue() )
    a->increment();
    CHECK_EQUAL( 0, a->getValue() )
    a->increment();
    CHECK_EQUAL( 1, a->getValue() )
    a->increment();
    CHECK_EQUAL( 2, a->getValue() )
}
TEST( decrement01, Alter )
{
    IAlterUPtr a = unique_ptr<Alter>( new Alter() );
    a->setValue( 2 );
    a->decrement();
    CHECK_EQUAL( 1, a->getValue() )
}
TEST( decrement02, Alter )
{
    IAlterUPtr a = unique_ptr<Alter>( new Alter() );
    a->setValue( 2 );
    a->decrement();
    CHECK_EQUAL( 1, a->getValue() )
    a->decrement();
    CHECK_EQUAL( 0, a->getValue() )
    a->decrement();
    CHECK_EQUAL( 6, a->getValue() )
    a->decrement();
    CHECK_EQUAL( 5, a->getValue() )
    a->decrement();
    CHECK_EQUAL( 4, a->getValue() )
    a->decrement();
    CHECK_EQUAL( 3, a->getValue() )
    a->decrement();
    CHECK_EQUAL( 2, a->getValue() )
}
TEST( checkAllStringAndAlterValueOutputs, Alter )
{
    auto a = unique_ptr<Alter>( new Alter() );
    a->setValue( 0 );
    CHECK_EQUAL( "C", a->toString() )
    a->increment();
    CHECK_EQUAL( "D", a->toString() )
    a->increment();
    CHECK_EQUAL( "E", a->toString() )
    a->increment();
    CHECK_EQUAL( "F", a->toString() )
    a->increment();
    CHECK_EQUAL( "G", a->toString() )
    a->increment();
    CHECK_EQUAL( "A", a->toString() )
    a->increment();
    CHECK_EQUAL( "B", a->toString() )
    a->increment();
    CHECK_EQUAL( "C", a->toString() )
}
TEST( checkAllStringInputs, Alter )
{
    auto a = unique_ptr<Alter>( new Alter() );
    a->setValue( 0 );
    a->parse( "D" );
    CHECK_EQUAL( 1, a->getValue() )
    a->parse( "E" );
    CHECK_EQUAL( 2, a->getValue() )
    a->parse( "F" );
    CHECK_EQUAL( 3, a->getValue() )
    a->parse( "G" );
    CHECK_EQUAL( 4, a->getValue() )
    a->parse( "A" );
    CHECK_EQUAL( 5, a->getValue() )
    a->parse( "B" );
    CHECK_EQUAL( 6, a->getValue() )
    a->parse( "C" );
    CHECK_EQUAL( 0, a->getValue() )
}