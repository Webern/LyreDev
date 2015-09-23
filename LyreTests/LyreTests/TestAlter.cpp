#include "cpulTestHarness.h"
#include "Alter.h"
#include <sstream>

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
    Alter s{ INT_MIN };
    CHECK_EQUAL( 0, s.getValue() )
}
TEST( Constructor01c, Alter )
{
    Alter s{ INT_MAX };
    CHECK_EQUAL( 6, s.getValue() )
}
TEST( Constructor02, Alter )
{
    Alter s{ AlterValue::D };
    CHECK_EQUAL( 1, s.getValue() )
}
TEST( Constructor03a, Alter )
{
    Alter s{ String{ "F" } };
    CHECK_EQUAL( 3, s.getValue() )
}
TEST( Constructor03b, Alter )
{
    Alter s{ String{ "BADINPUT" } };
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
    CHECK_EQUAL( 6, p2->getValue() );
}
TEST( getMin, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    CHECK_EQUAL( 0, p->getMin() )
}
TEST( getMax, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    CHECK_EQUAL( 6, p->getMax() )
}
TEST( parse, Alter )
{
    IAlterUPtr p = unique_ptr<Alter>( new Alter() );
    p->setValue( 2 );
    CHECK_EQUAL( "E", p->toString() )
    CHECK( ! p->parse( "f" ) )
    CHECK_EQUAL( "E", p->toString() )
    CHECK( p->parse( "F" ) )
    CHECK_EQUAL( "F", p->toString() )
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
    CHECK( a->getAlterValue() == AlterValue::C )
    a->increment();
    CHECK_EQUAL( "D", a->toString() )
    CHECK( a->getAlterValue() == AlterValue::D )
    a->increment();
    CHECK_EQUAL( "E", a->toString() )
    CHECK( a->getAlterValue() == AlterValue::E )
    a->increment();
    CHECK_EQUAL( "F", a->toString() )
    CHECK( a->getAlterValue() == AlterValue::F )
    a->increment();
    CHECK_EQUAL( "G", a->toString() )
    CHECK( a->getAlterValue() == AlterValue::G )
    a->increment();
    CHECK_EQUAL( "A", a->toString() )
    CHECK( a->getAlterValue() == AlterValue::A )
    a->increment();
    CHECK_EQUAL( "B", a->toString() )
    CHECK( a->getAlterValue() == AlterValue::B )
    a->increment();
    CHECK_EQUAL( "C", a->toString() )
    CHECK( a->getAlterValue() == AlterValue::C )
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
TEST( checkAllAlterValueInputs, Alter )
{
    auto a = unique_ptr<Alter>( new Alter() );
    a->setValue( 0 );
    a->setValue( AlterValue::D );
    CHECK_EQUAL( 1, a->getValue() )
    a->setValue( AlterValue::E );
    CHECK_EQUAL( 2, a->getValue() )
    a->setValue( AlterValue::F );
    CHECK_EQUAL( 3, a->getValue() )
    a->setValue( AlterValue::G );
    CHECK_EQUAL( 4, a->getValue() )
    a->setValue( AlterValue::A );
    CHECK_EQUAL( 5, a->getValue() )
    a->setValue( AlterValue::B );
    CHECK_EQUAL( 6, a->getValue() )
    a->setValue( AlterValue::C );
    CHECK_EQUAL( 0, a->getValue() )
}