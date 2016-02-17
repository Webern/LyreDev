//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockAlter.h"
#include <sstream>

using namespace Lyre;
using namespace Lyre::Mock;
using namespace std;

TEST( Compiles, IAlter )
{
    MockAlter m;
    CHECK( true )
}
T_END

TEST( SharedPtr, IAlter )
{
    IAlterSP p = std::make_shared<MockAlter>();
    CHECK( true )
}
T_END

TEST( UniquePtr, IAlter )
{
    IAlterUP p = unique_ptr<MockAlter>( new MockAlter() );
    CHECK( true )
}
T_END

TEST( clone, IAlter )
{
    IAlterSP p1 = std::make_shared<MockAlter>();
    p1->setValue( 100 );
    IAlterSP p2 = p1->clone();
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 100, p2->getValue() );
    p2->setValue( 200 );
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 200, p2->getValue() );
}
T_END

TEST( getMin, IAlter )
{
    IAlterUP p = unique_ptr<MockAlter>( new MockAlter() );
    CHECK_EQUAL( 0, p->getMin() )
}
T_END

TEST( getMax, IAlter )
{
    IAlterUP p = unique_ptr<MockAlter>( new MockAlter() );
    CHECK_EQUAL( 1, p->getMax() )
}
T_END

TEST( parse, IAlter )
{
    IAlterUP p = unique_ptr<MockAlter>( new MockAlter() );
    CHECK( p->parse( "" ) )
}
T_END

TEST( toStream, IAlter )
{
    IAlterUP p = unique_ptr<MockAlter>( new MockAlter() );
    p->setValue( 13 );
    stringstream ss;
    p->toStream( ss );
    String expected = "13";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString, IAlter )
{
    IAlterUP p = unique_ptr<MockAlter>( new MockAlter() );
    p->setValue( 13 );
    String expected = "13";
    String actual{ p->toString() };
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator, IAlter )
{
    IAlterUP p = unique_ptr<MockAlter>( new MockAlter() );
    p->setValue( 13 );
    stringstream ss;
    ss << ( *p );
    String expected = "13";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( comparisons_a_isLessThan_b, IAlter )
{
    IAlterUP a = unique_ptr<MockAlter>( new MockAlter() );
    IAlterUP b = unique_ptr<IAlter>( new MockAlter() );
    a->setValue( 1 );
    b->setValue( 2 );
    CHECK(   a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK(   b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
T_END

TEST( comparisons_a_isGreaterThan_b, IAlter )
{
    IAlterUP a = unique_ptr<IAlter>( new MockAlter() );
    IAlterUP b = unique_ptr<MockAlter>( new MockAlter() );
    a->setValue( 2 );
    b->setValue( 1 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK(   b->isLessThan   ( *a ) )
    CHECK(   a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
T_END

TEST( comparisons_a_isEqualTo_b, IAlter )
{
    IAlterUP a = unique_ptr<IAlter>( new MockAlter() );
    IAlterUP b = unique_ptr<MockAlter>( new MockAlter() );
    a->setValue( 21 );
    b->setValue( 21 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK(   a->isEqualTo     ( *b ) )
    CHECK(   b->isEqualTo     ( *a ) )
}
T_END

TEST( increment, IAlter )
{
    IAlterUP a = unique_ptr<IAlter>( new MockAlter() );
    a->setValue( 100 );
    a->increment();
    CHECK_EQUAL( 101, a->getValue() )
}
T_END

TEST( decrement, IAlter )
{
    IAlterUP a = unique_ptr<IAlter>( new MockAlter() );
    a->setValue( 100 );
    a->decrement();
    CHECK_EQUAL( 99, a->getValue() )
}
T_END

TEST( isIdenticalTo, IAlter )
{
    IAlterUP a = unique_ptr<IAlter>( new MockAlter() );
    CHECK( a->isIdenticalTo( *a ) )
}
T_END
