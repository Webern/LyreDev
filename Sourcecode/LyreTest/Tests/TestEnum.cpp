//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockEnumCats.h"
#include <sstream>

using namespace Lyre;
using namespace Lyre::Private;
using namespace Lyre::Mock;
using namespace std;

TEST( Compiles, Enum )
{
    MockEnumCats m;
    CHECK( true )
}
TEST( SharedPtr, Enum )
{
    IEnumSP p = std::make_shared<MockEnumCats>();
    CHECK( true )
}
TEST( UniquePtr, Enum )
{
    IEnumUP p = unique_ptr<MockEnumCats>( new MockEnumCats() );
    CHECK( true )
}
TEST( clone, Enum )
{
    IEnumSP p1 = std::make_shared<MockEnumCats>();
    p1->setValue( 4 );
    IEnumSP p2 = p1->clone();
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 3, p1->getValue() );
    CHECK_EQUAL( 3, p2->getValue() );
    p2->setValue( 2 );
    CHECK_EQUAL( 3, p1->getValue() );
    CHECK_EQUAL( 2, p2->getValue() );
}
TEST( covariantClone, Enum )
{
    std::shared_ptr<MockEnumCats> p1 = std::make_shared<MockEnumCats>();
    p1->setValue( -1 );
    std::unique_ptr<MockEnumCats> p2;
    p1->copyTo( p2 );
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 1, p1->getValue() );
    CHECK_EQUAL( 1, p2->getValue() );
    p2->setValue( 200 );
    CHECK_EQUAL( 1, p1->getValue() );
    CHECK_EQUAL( 3, p2->getValue() );
}
TEST( getMin, Enum )
{
    IEnumUP p = unique_ptr<MockEnumCats>( new MockEnumCats() );
    CHECK_EQUAL( 1, p->getMin() )
}
TEST( getMax, Enum )
{
    IEnumUP p = unique_ptr<MockEnumCats>( new MockEnumCats() );
    CHECK_EQUAL( 3, p->getMax() )
}
TEST( parse, Enum )
{
    IEnumUP p = unique_ptr<MockEnumCats>( new MockEnumCats() );
    p->setValue( 3 );
    CHECK_EQUAL( "Mabel", p->toString() )
    CHECK( ! p->parse( "BONES" ) )
    CHECK_EQUAL( "Mabel", p->toString() )
    CHECK( p->parse( "Bones" ) )
    CHECK_EQUAL( "Bones", p->toString() )
}
TEST( toStream, Enum )
{
    IEnumUP p = unique_ptr<MockEnumCats>( new MockEnumCats() );
    p->setValue( 2 );
    stringstream ss;
    p->toStream( ss );
    String expected = "Bishop";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString, Enum )
{
    IEnumUP p = unique_ptr<MockEnumCats>( new MockEnumCats() );
    p->setValue( 1 );
    String expected = "Bones";
    String actual{ p->toString() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator, Enum )
{
    IEnumUP p = unique_ptr<MockEnumCats>( new MockEnumCats() );
    p->setValue( 3 );
    stringstream ss;
    ss << ( *p );
    String expected = "Mabel";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( comparisons_a_isLessThan_b, Enum )
{
    IEnumUP a = unique_ptr<MockEnumCats>( new MockEnumCats() );
    IEnumUP b = unique_ptr<Enum>( new MockEnumCats() );
    a->setValue( 1 );
    b->setValue( 2 );
    CHECK(   a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK(   b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
TEST( comparisons_a_isGreaterThan_b, Enum )
{
    IEnumUP a = unique_ptr<Enum>( new MockEnumCats() );
    IEnumUP b = unique_ptr<MockEnumCats>( new MockEnumCats() );
    a->setValue( 2 );
    b->setValue( 1 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK(   b->isLessThan   ( *a ) )
    CHECK(   a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
TEST( comparisons_a_isEqualTo_b, Enum )
{
    IEnumUP a = unique_ptr<Enum>( new MockEnumCats() );
    IEnumUP b = unique_ptr<MockEnumCats>( new MockEnumCats() );
    a->setValue( 3 );
    b->setValue( 3 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK(   a->isEqualTo     ( *b ) )
    CHECK(   b->isEqualTo     ( *a ) )
}
TEST( increment01, Enum )
{
    IEnumUP a = unique_ptr<Enum>( new MockEnumCats() );
    a->setValue( 1 );
    a->increment();
    CHECK_EQUAL( 2, a->getValue() )
}
TEST( increment02, Enum )
{
    IEnumUP a = unique_ptr<Enum>( new MockEnumCats() );
    a->setValue( 2 );
    a->increment();
    CHECK_EQUAL( 3, a->getValue() )
    a->increment();
    CHECK_EQUAL( 1, a->getValue() )
    a->increment();
    CHECK_EQUAL( 2, a->getValue() )
    a->increment();
    CHECK_EQUAL( 3, a->getValue() )
    a->increment();
    CHECK_EQUAL( 1, a->getValue() )
}
TEST( decrement01, Enum )
{
    IEnumUP a = unique_ptr<Enum>( new MockEnumCats() );
    a->setValue( 2 );
    a->decrement();
    CHECK_EQUAL( 1, a->getValue() )
}
TEST( decrement02, Enum )
{
    IEnumUP a = unique_ptr<Enum>( new MockEnumCats() );
    a->setValue( 1 );
    a->decrement();
    CHECK_EQUAL( 3, a->getValue() )
    a->decrement();
    CHECK_EQUAL( 2, a->getValue() )
    a->decrement();
    CHECK_EQUAL( 1, a->getValue() )
    a->decrement();
    CHECK_EQUAL( 3, a->getValue() )
}