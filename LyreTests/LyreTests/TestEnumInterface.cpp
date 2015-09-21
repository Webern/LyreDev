#include "cpulTestHarness.h"
#include "EnumInterface.h"
#include <sstream>

using namespace lyre;
using namespace std;

class MockEnum : public EnumInterface
{
public:
    EnumPtr clone() const { return std::make_shared<MockEnum>( *this ); }
    Integer getValue() const { return myValue; }
    void setValue( const Integer val ) { myValue = val; }
    Integer getMin() const { return 0; }
    Integer getMax() const { return 1; }
    bool parse( const String& str ) { return true; }
    std::ostream& toStream( std::ostream& os ) const { return os << myValue; }
    bool extendedFunction() const { return true; }
    void increment() { myValue++; }
    void decrement() { myValue--; }
private:
    Integer myValue;
};

TEST( Compiles, EnumInterface )
{
    MockEnum m;
    CHECK( true )
}
TEST( SharedPtr, EnumInterface )
{
    EnumPtr p = std::make_shared<MockEnum>();
    CHECK( true )
}
TEST( UniquePtr, EnumInterface )
{
    EnumUPtr p = unique_ptr<MockEnum>( new MockEnum() );
    CHECK( true )
}
TEST( clone, EnumInterface )
{
    EnumPtr p1 = std::make_shared<MockEnum>();
    p1->setValue( 100 );
    EnumPtr p2 = p1->clone();
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 100, p2->getValue() );
    p2->setValue( 200 );
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 200, p2->getValue() );
}
TEST( covariantClone, EnumInterface )
{
    std::shared_ptr<MockEnum> p1 = std::make_shared<MockEnum>();
    p1->setValue( 100 );
    std::shared_ptr<MockEnum> p2;
    p1->copyTo( p2 );
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 100, p2->getValue() );
    CHECK( p1->extendedFunction() )
    CHECK( p2->extendedFunction() )
    p2->setValue( 200 );
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 200, p2->getValue() );
    CHECK( p1->extendedFunction() )
    CHECK( p2->extendedFunction() )
}
TEST( getMin, EnumInterface )
{
    EnumUPtr p = unique_ptr<MockEnum>( new MockEnum() );
    CHECK_EQUAL( 0, p->getMin() )
}
TEST( getMax, EnumInterface )
{
    EnumUPtr p = unique_ptr<MockEnum>( new MockEnum() );
    CHECK_EQUAL( 1, p->getMax() )
}
TEST( parse, EnumInterface )
{
    EnumUPtr p = unique_ptr<MockEnum>( new MockEnum() );
    CHECK( p->parse( "" ) )
}
TEST( toStream, EnumInterface )
{
    EnumUPtr p = unique_ptr<MockEnum>( new MockEnum() );
    p->setValue( 13 );
    stringstream ss;
    p->toStream( ss );
    String expected = "13";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString, EnumInterface )
{
    EnumUPtr p = unique_ptr<MockEnum>( new MockEnum() );
    p->setValue( 13 );
    String expected = "13";
    String actual{ p->toString() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator, EnumInterface )
{
    EnumUPtr p = unique_ptr<MockEnum>( new MockEnum() );
    p->setValue( 13 );
    stringstream ss;
    ss << ( *p );
    String expected = "13";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( comparisons_a_lessThan_b, EnumInterface )
{
    EnumUPtr a = unique_ptr<MockEnum>( new MockEnum() );
    EnumUPtr b = unique_ptr<EnumInterface>( new MockEnum() );
    a->setValue( 1 );
    b->setValue( 2 );
    CHECK(   a->lessThan   ( *b ) )
    CHECK( ! b->lessThan   ( *a ) )
    CHECK( ! a->greaterThan( *b ) )
    CHECK(   b->greaterThan( *a ) )
    CHECK( ! a->equals     ( *b ) )
    CHECK( ! b->equals     ( *a ) )
}
TEST( comparisons_a_greaterThan_b, EnumInterface )
{
    EnumUPtr a = unique_ptr<EnumInterface>( new MockEnum() );
    EnumUPtr b = unique_ptr<MockEnum>( new MockEnum() );
    a->setValue( 2 );
    b->setValue( 1 );
    CHECK( ! a->lessThan   ( *b ) )
    CHECK(   b->lessThan   ( *a ) )
    CHECK(   a->greaterThan( *b ) )
    CHECK( ! b->greaterThan( *a ) )
    CHECK( ! a->equals     ( *b ) )
    CHECK( ! b->equals     ( *a ) )
}
TEST( comparisons_a_equals_b, EnumInterface )
{
    EnumUPtr a = unique_ptr<EnumInterface>( new MockEnum() );
    EnumUPtr b = unique_ptr<MockEnum>( new MockEnum() );
    a->setValue( 21 );
    b->setValue( 21 );
    CHECK( ! a->lessThan   ( *b ) )
    CHECK( ! b->lessThan   ( *a ) )
    CHECK( ! a->greaterThan( *b ) )
    CHECK( ! b->greaterThan( *a ) )
    CHECK(   a->equals     ( *b ) )
    CHECK(   b->equals     ( *a ) )
}
TEST( increment, EnumInterface )
{
    EnumUPtr a = unique_ptr<EnumInterface>( new MockEnum() );
    a->setValue( 100 );
    a->increment();
    CHECK_EQUAL( 101, a->getValue() )
}
TEST( decrement, EnumInterface )
{
    EnumUPtr a = unique_ptr<EnumInterface>( new MockEnum() );
    a->setValue( 100 );
    a->decrement();
    CHECK_EQUAL( 99, a->getValue() )
}