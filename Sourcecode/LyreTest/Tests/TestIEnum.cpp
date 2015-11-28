//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockEnum.h"
#include <sstream>

using namespace Lyre;
using namespace Lyre::Mock;
using namespace std;



TEST( Compiles, IEnum )
{
    MockEnum m;
    CHECK( true )
}
TEST( SharedPtr, IEnum )
{
    IEnumSP p = std::make_shared<MockEnum>();
    CHECK( true )
}
TEST( UniquePtr, IEnum )
{
    IEnumUP p = unique_ptr<MockEnum>( new MockEnum() );
    CHECK( true )
}
TEST( clone, IEnum )
{
    IEnumSP p1 = std::make_shared<MockEnum>();
    p1->setValue( 100 );
    IEnumSP p2 = p1->clone();
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 100, p2->getValue() );
    p2->setValue( 200 );
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 200, p2->getValue() );
}
//TEST( covariantClone, IEnum )
//{
//    std::shared_ptr<MockEnum> p1 = std::make_shared<MockEnum>();
//    p1->setValue( 100 );
//    std::unique_ptr<MockEnum> p2;
//    p1->copyTo( p2 );
//    CHECK( p1.get() != p2.get() )
//    CHECK_EQUAL( 100, p1->getValue() );
//    CHECK_EQUAL( 100, p2->getValue() );
//    CHECK( p1->extendedFunction() )
//    CHECK( p2->extendedFunction() )
//    p2->setValue( 200 );
//    CHECK_EQUAL( 100, p1->getValue() );
//    CHECK_EQUAL( 200, p2->getValue() );
//    CHECK( p1->extendedFunction() )
//    CHECK( p2->extendedFunction() )
//}
TEST( getMin, IEnum )
{
    IEnumUP p = unique_ptr<MockEnum>( new MockEnum() );
    CHECK_EQUAL( 0, p->getMin() )
}
TEST( getMax, IEnum )
{
    IEnumUP p = unique_ptr<MockEnum>( new MockEnum() );
    CHECK_EQUAL( 1, p->getMax() )
}
TEST( parse, IEnum )
{
    IEnumUP p = unique_ptr<MockEnum>( new MockEnum() );
    CHECK( p->parse( "" ) )
}
TEST( toStream, IEnum )
{
    IEnumUP p = unique_ptr<MockEnum>( new MockEnum() );
    p->setValue( 13 );
    stringstream ss;
    p->toStream( ss );
    String expected = "13";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString, IEnum )
{
    IEnumUP p = unique_ptr<MockEnum>( new MockEnum() );
    p->setValue( 13 );
    String expected = "13";
    String actual{ p->toString() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator, IEnum )
{
    IEnumUP p = unique_ptr<MockEnum>( new MockEnum() );
    p->setValue( 13 );
    stringstream ss;
    ss << ( *p );
    String expected = "13";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( comparisons_a_isLessThan_b, IEnum )
{
    IEnumUP a = unique_ptr<MockEnum>( new MockEnum() );
    IEnumUP b = unique_ptr<IEnum>( new MockEnum() );
    a->setValue( 1 );
    b->setValue( 2 );
    CHECK(   a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK(   b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
TEST( comparisons_a_isGreaterThan_b, IEnum )
{
    IEnumUP a = unique_ptr<IEnum>( new MockEnum() );
    IEnumUP b = unique_ptr<MockEnum>( new MockEnum() );
    a->setValue( 2 );
    b->setValue( 1 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK(   b->isLessThan   ( *a ) )
    CHECK(   a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
TEST( comparisons_a_isEqualTo_b, IEnum )
{
    IEnumUP a = unique_ptr<IEnum>( new MockEnum() );
    IEnumUP b = unique_ptr<MockEnum>( new MockEnum() );
    a->setValue( 21 );
    b->setValue( 21 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK(   a->isEqualTo     ( *b ) )
    CHECK(   b->isEqualTo     ( *a ) )
}
TEST( increment, IEnum )
{
    IEnumUP a = unique_ptr<IEnum>( new MockEnum() );
    a->setValue( 100 );
    a->increment();
    CHECK_EQUAL( 101, a->getValue() )
}
TEST( decrement, IEnum )
{
    IEnumUP a = unique_ptr<IEnum>( new MockEnum() );
    a->setValue( 100 );
    a->decrement();
    CHECK_EQUAL( 99, a->getValue() )
}