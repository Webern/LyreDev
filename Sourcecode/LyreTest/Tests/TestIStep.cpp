//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockStep.h"

#include "Lyre/IStep.h"

#include <sstream>

using namespace Lyre;
using namespace Lyre::Mock;
using namespace std;

TEST( Compiles, IStep )
{
    MockStep m;
    CHECK( true )
}
T_END

TEST( SharedPtr, IStep )
{
    IStepSP p = std::make_shared<MockStep>();
    CHECK( true )
}
T_END

TEST( UniquePtr, IStep )
{
    IStepUP p = unique_ptr<MockStep>( new MockStep() );
    CHECK( true )
}
T_END

TEST( clone, IStep )
{
    IStepSP p1 = std::make_shared<MockStep>();
    p1->setValue( 100 );
    IStepSP p2 = p1->clone();
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 100, p2->getValue() );
    p2->setValue( 200 );
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 200, p2->getValue() );
}
T_END

TEST( getMin, IStep )
{
    IStepUP p = unique_ptr<MockStep>( new MockStep() );
    CHECK_EQUAL( 0, p->getMin() )
}
T_END

TEST( getMax, IStep )
{
    IStepUP p = unique_ptr<MockStep>( new MockStep() );
    CHECK_EQUAL( 1, p->getMax() )
}
T_END

TEST( parse, IStep )
{
    IStepUP p = unique_ptr<MockStep>( new MockStep() );
    CHECK( p->parse( "" ) )
}
T_END

TEST( toStream, IStep )
{
    IStepUP p = unique_ptr<MockStep>( new MockStep() );
    p->setValue( 13 );
    stringstream ss;
    p->toStream( ss );
    String expected = "13";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString, IStep )
{
    IStepUP p = unique_ptr<MockStep>( new MockStep() );
    p->setValue( 13 );
    String expected = "13";
    String actual{ p->toString() };
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator, IStep )
{
    IStepUP p = unique_ptr<MockStep>( new MockStep() );
    p->setValue( 13 );
    stringstream ss;
    ss << ( *p );
    String expected = "13";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( comparisons_a_isLessThan_b, IStep )
{
    IStepUP a = unique_ptr<MockStep>( new MockStep() );
    IStepUP b = unique_ptr<IStep>( new MockStep() );
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

TEST( comparisons_a_isGreaterThan_b, IStep )
{
    IStepUP a = unique_ptr<IStep>( new MockStep() );
    IStepUP b = unique_ptr<MockStep>( new MockStep() );
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

TEST( comparisons_a_isEqualTo_b, IStep )
{
    IStepUP a = unique_ptr<IStep>( new MockStep() );
    IStepUP b = unique_ptr<MockStep>( new MockStep() );
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

TEST( increment, IStep )
{
    IStepUP a = unique_ptr<IStep>( new MockStep() );
    a->setValue( 100 );
    a->increment();
    CHECK_EQUAL( 101, a->getValue() )
}
T_END

TEST( decrement, IStep )
{
    IStepUP a = unique_ptr<IStep>( new MockStep() );
    a->setValue( 100 );
    a->decrement();
    CHECK_EQUAL( 99, a->getValue() )
}
T_END

TEST( isIdenticalTo, IStep )
{
    IStepUP x = unique_ptr<IStep>( new MockStep() );
    CHECK( x->isIdenticalTo( *x ) )
}
T_END