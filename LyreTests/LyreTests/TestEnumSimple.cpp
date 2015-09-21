#include "cpulTestHarness.h"
#include "EnumSimple.h"
#include <sstream>

using namespace lyre;
using namespace std;

const static std::shared_ptr<Strings> mockenumstrings = std::make_shared<Strings>( Strings{"Bones","Bishop","Mabel"} );

class MockStringsEnum : public EnumSimple
{
public:
    MockStringsEnum()
    :EnumSimple( 0, mockenumstrings, 1 )
    {}
};

TEST( Compiles, EnumSimple )
{
    MockStringsEnum m;
    CHECK( true )
}
TEST( SharedPtr, EnumSimple )
{
    EnumPtr p = std::make_shared<MockStringsEnum>();
    CHECK( true )
}
TEST( UniquePtr, EnumSimple )
{
    EnumUPtr p = unique_ptr<MockStringsEnum>( new MockStringsEnum() );
    CHECK( true )
}
TEST( clone, EnumSimple )
{
    EnumPtr p1 = std::make_shared<MockStringsEnum>();
    p1->setValue( 4 );
    EnumPtr p2 = p1->clone();
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 3, p1->getValue() );
    CHECK_EQUAL( 3, p2->getValue() );
    p2->setValue( 2 );
    CHECK_EQUAL( 3, p1->getValue() );
    CHECK_EQUAL( 2, p2->getValue() );
}
TEST( covariantClone, EnumSimple )
{
    std::shared_ptr<MockStringsEnum> p1 = std::make_shared<MockStringsEnum>();
    p1->setValue( -1 );
    std::shared_ptr<MockStringsEnum> p2;
    p1->copyTo( p2 );
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 1, p1->getValue() );
    CHECK_EQUAL( 1, p2->getValue() );
    p2->setValue( 200 );
    CHECK_EQUAL( 1, p1->getValue() );
    CHECK_EQUAL( 3, p2->getValue() );
}
TEST( getMin, EnumSimple )
{
    EnumUPtr p = unique_ptr<MockStringsEnum>( new MockStringsEnum() );
    CHECK_EQUAL( 1, p->getMin() )
}
TEST( getMax, EnumSimple )
{
    EnumUPtr p = unique_ptr<MockStringsEnum>( new MockStringsEnum() );
    CHECK_EQUAL( 3, p->getMax() )
}
TEST( parse, EnumSimple )
{
    EnumUPtr p = unique_ptr<MockStringsEnum>( new MockStringsEnum() );
    p->setValue( 3 );
    CHECK_EQUAL( "Mabel", p->toString() )
    CHECK( ! p->parse( "BONES" ) )
    CHECK_EQUAL( "Mabel", p->toString() )
    CHECK( p->parse( "Bones" ) )
    CHECK_EQUAL( "Bones", p->toString() )
}
TEST( toStream, EnumSimple )
{
    EnumUPtr p = unique_ptr<MockStringsEnum>( new MockStringsEnum() );
    p->setValue( 2 );
    stringstream ss;
    p->toStream( ss );
    String expected = "Bishop";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString, EnumSimple )
{
    EnumUPtr p = unique_ptr<MockStringsEnum>( new MockStringsEnum() );
    p->setValue( 1 );
    String expected = "Bones";
    String actual{ p->toString() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator, EnumSimple )
{
    EnumUPtr p = unique_ptr<MockStringsEnum>( new MockStringsEnum() );
    p->setValue( 3 );
    stringstream ss;
    ss << ( *p );
    String expected = "Mabel";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( comparisons_a_lessThan_b, EnumSimple )
{
    EnumUPtr a = unique_ptr<MockStringsEnum>( new MockStringsEnum() );
    EnumUPtr b = unique_ptr<EnumSimple>( new MockStringsEnum() );
    a->setValue( 1 );
    b->setValue( 2 );
    CHECK(   a->lessThan   ( *b ) )
    CHECK( ! b->lessThan   ( *a ) )
    CHECK( ! a->greaterThan( *b ) )
    CHECK(   b->greaterThan( *a ) )
    CHECK( ! a->equals     ( *b ) )
    CHECK( ! b->equals     ( *a ) )
}
TEST( comparisons_a_greaterThan_b, EnumSimple )
{
    EnumUPtr a = unique_ptr<EnumSimple>( new MockStringsEnum() );
    EnumUPtr b = unique_ptr<MockStringsEnum>( new MockStringsEnum() );
    a->setValue( 2 );
    b->setValue( 1 );
    CHECK( ! a->lessThan   ( *b ) )
    CHECK(   b->lessThan   ( *a ) )
    CHECK(   a->greaterThan( *b ) )
    CHECK( ! b->greaterThan( *a ) )
    CHECK( ! a->equals     ( *b ) )
    CHECK( ! b->equals     ( *a ) )
}
TEST( comparisons_a_equals_b, EnumSimple )
{
    EnumUPtr a = unique_ptr<EnumSimple>( new MockStringsEnum() );
    EnumUPtr b = unique_ptr<MockStringsEnum>( new MockStringsEnum() );
    a->setValue( 3 );
    b->setValue( 3 );
    CHECK( ! a->lessThan   ( *b ) )
    CHECK( ! b->lessThan   ( *a ) )
    CHECK( ! a->greaterThan( *b ) )
    CHECK( ! b->greaterThan( *a ) )
    CHECK(   a->equals     ( *b ) )
    CHECK(   b->equals     ( *a ) )
}
TEST( increment01, EnumSimple )
{
    EnumUPtr a = unique_ptr<EnumSimple>( new MockStringsEnum() );
    a->setValue( 1 );
    a->increment();
    CHECK_EQUAL( 2, a->getValue() )
}
TEST( increment02, EnumSimple )
{
    EnumUPtr a = unique_ptr<EnumSimple>( new MockStringsEnum() );
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
TEST( decrement01, EnumSimple )
{
    EnumUPtr a = unique_ptr<EnumSimple>( new MockStringsEnum() );
    a->setValue( 2 );
    a->decrement();
    CHECK_EQUAL( 1, a->getValue() )
}
TEST( decrement02, EnumSimple )
{
    EnumUPtr a = unique_ptr<EnumSimple>( new MockStringsEnum() );
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