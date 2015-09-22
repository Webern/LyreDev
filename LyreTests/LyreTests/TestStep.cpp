#include "cpulTestHarness.h"
#include "Step.h"
#include <sstream>

using namespace lyre;
using namespace std;

TEST( Compiles, Step )
{
    Step o;
    CHECK( true )
}
TEST( SharedPtr, Step )
{
    IStepPtr p = std::make_shared<Step>();
    CHECK( true )
}
TEST( UniquePtr, Step )
{
    IStepUPtr p = unique_ptr<Step>( new Step() );
    CHECK( true )
}
TEST( clone, Step )
{
    IStepPtr p1 = std::make_shared<Step>();
    p1->setValue( 4 );
    IStepPtr p2 = p1->clone();
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 4, p1->getValue() );
    CHECK_EQUAL( 4, p2->getValue() );
    p2->setValue( 2 );
    CHECK_EQUAL( 4, p1->getValue() );
    CHECK_EQUAL( 2, p2->getValue() );
}
TEST( covariantClone, Step )
{
    std::shared_ptr<Step> p1 = std::make_shared<Step>();
    p1->setValue( -1 );
    std::shared_ptr<Step> p2;
    p1->copyTo( p2 );
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 0, p1->getValue() );
    CHECK_EQUAL( 0, p2->getValue() );
    p2->setValue( 200 );
    CHECK_EQUAL( 0, p1->getValue() );
    CHECK_EQUAL( 6, p2->getValue() );
}
TEST( getMin, Step )
{
    IStepUPtr p = unique_ptr<Step>( new Step() );
    CHECK_EQUAL( 0, p->getMin() )
}
TEST( getMax, Step )
{
    IStepUPtr p = unique_ptr<Step>( new Step() );
    CHECK_EQUAL( 6, p->getMax() )
}
TEST( parse, Step )
{
    IStepUPtr p = unique_ptr<Step>( new Step() );
    p->setValue( 2 );
    CHECK_EQUAL( "E", p->toString() )
    CHECK( ! p->parse( "f" ) )
    CHECK_EQUAL( "E", p->toString() )
    CHECK( p->parse( "F" ) )
    CHECK_EQUAL( "F", p->toString() )
}
TEST( toStream, Step )
{
    IStepUPtr p = unique_ptr<Step>( new Step() );
    p->setValue( 1 );
    stringstream ss;
    p->toStream( ss );
    String expected = "D";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString, Step )
{
    IStepUPtr p = unique_ptr<Step>( new Step() );
    p->setValue( 6 );
    String expected = "B";
    String actual{ p->toString() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator, Step )
{
    IStepUPtr p = unique_ptr<Step>( new Step() );
    p->setValue( 4 );
    stringstream ss;
    ss << ( *p );
    String expected = "G";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( comparisons_a_lessThan_b, Step )
{
    IStepUPtr a = unique_ptr<Step>( new Step() );
    IStepUPtr b = unique_ptr<Step>( new Step() );
    a->setValue( 1 );
    b->setValue( 2 );
    CHECK(   a->lessThan   ( *b ) )
    CHECK( ! b->lessThan   ( *a ) )
    CHECK( ! a->greaterThan( *b ) )
    CHECK(   b->greaterThan( *a ) )
    CHECK( ! a->equals     ( *b ) )
    CHECK( ! b->equals     ( *a ) )
}
TEST( comparisons_a_greaterThan_b, Step )
{
    IStepUPtr a = unique_ptr<Step>( new Step() );
    IStepUPtr b = unique_ptr<Step>( new Step() );
    a->setValue( 2 );
    b->setValue( 1 );
    CHECK( ! a->lessThan   ( *b ) )
    CHECK(   b->lessThan   ( *a ) )
    CHECK(   a->greaterThan( *b ) )
    CHECK( ! b->greaterThan( *a ) )
    CHECK( ! a->equals     ( *b ) )
    CHECK( ! b->equals     ( *a ) )
}
TEST( comparisons_a_equals_b, Step )
{
    IStepUPtr a = unique_ptr<Step>( new Step() );
    IStepUPtr b = unique_ptr<Step>( new Step() );
    a->setValue( 3 );
    b->setValue( 3 );
    CHECK( ! a->lessThan   ( *b ) )
    CHECK( ! b->lessThan   ( *a ) )
    CHECK( ! a->greaterThan( *b ) )
    CHECK( ! b->greaterThan( *a ) )
    CHECK(   a->equals     ( *b ) )
    CHECK(   b->equals     ( *a ) )
}
TEST( increment01, Step )
{
    IStepUPtr a = unique_ptr<Step>( new Step() );
    a->setValue( 1 );
    a->increment();
    CHECK_EQUAL( 2, a->getValue() )
}
TEST( increment02, Step )
{
    IStepUPtr a = unique_ptr<Step>( new Step() );
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
TEST( decrement01, Step )
{
    IStepUPtr a = unique_ptr<Step>( new Step() );
    a->setValue( 2 );
    a->decrement();
    CHECK_EQUAL( 1, a->getValue() )
}
TEST( decrement02, Step )
{
    IStepUPtr a = unique_ptr<Step>( new Step() );
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