#include "cpulTestHarness.h"
#include "IAlter.h"
#include <sstream>

using namespace lyre;
using namespace std;

class MockAlter : public IAlter
{
public:
    IAlterUPtr clone() const
    {
        IAlterUPtr value{ new MockAlter{ *this } };
        return value;
    }
    Integer getValue() const { return myValue; }
    void setValue( const Integer val ) { myValue = val; }
    Integer getMin() const { return 0; }
    Integer getMax() const { return 1; }
    bool parse( const String& str ) { return true; }
    std::ostream& toStream( std::ostream& os ) const { return os << myValue; }
    bool extendedFunction() const { return true; }
    virtual bool isIdenticalTo( const IAlter& other ) const { return true; }
    void increment() { myValue++; }
    void decrement() { myValue--; }
private:
    Integer myValue;
};

TEST( Compiles, IAlter )
{
    MockAlter m;
    CHECK( true )
}
TEST( SharedPtr, IAlter )
{
    IAlterPtr p = std::make_shared<MockAlter>();
    CHECK( true )
}
TEST( UniquePtr, IAlter )
{
    IAlterUPtr p = unique_ptr<MockAlter>( new MockAlter() );
    CHECK( true )
}
TEST( clone, IAlter )
{
    IAlterPtr p1 = std::make_shared<MockAlter>();
    p1->setValue( 100 );
    IAlterPtr p2 = p1->clone();
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 100, p2->getValue() );
    p2->setValue( 200 );
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 200, p2->getValue() );
}
TEST( covariantClone, IAlter )
{
    std::shared_ptr<MockAlter> p1 = std::make_shared<MockAlter>();
    p1->setValue( 100 );
    std::unique_ptr<MockAlter> p2;
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
TEST( getMin, IAlter )
{
    IAlterUPtr p = unique_ptr<MockAlter>( new MockAlter() );
    CHECK_EQUAL( 0, p->getMin() )
}
TEST( getMax, IAlter )
{
    IAlterUPtr p = unique_ptr<MockAlter>( new MockAlter() );
    CHECK_EQUAL( 1, p->getMax() )
}
TEST( parse, IAlter )
{
    IAlterUPtr p = unique_ptr<MockAlter>( new MockAlter() );
    CHECK( p->parse( "" ) )
}
TEST( toStream, IAlter )
{
    IAlterUPtr p = unique_ptr<MockAlter>( new MockAlter() );
    p->setValue( 13 );
    stringstream ss;
    p->toStream( ss );
    String expected = "13";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString, IAlter )
{
    IAlterUPtr p = unique_ptr<MockAlter>( new MockAlter() );
    p->setValue( 13 );
    String expected = "13";
    String actual{ p->toString() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator, IAlter )
{
    IAlterUPtr p = unique_ptr<MockAlter>( new MockAlter() );
    p->setValue( 13 );
    stringstream ss;
    ss << ( *p );
    String expected = "13";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( comparisons_a_isLessThan_b, IAlter )
{
    IAlterUPtr a = unique_ptr<MockAlter>( new MockAlter() );
    IAlterUPtr b = unique_ptr<IAlter>( new MockAlter() );
    a->setValue( 1 );
    b->setValue( 2 );
    CHECK(   a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK(   b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
TEST( comparisons_a_isGreaterThan_b, IAlter )
{
    IAlterUPtr a = unique_ptr<IAlter>( new MockAlter() );
    IAlterUPtr b = unique_ptr<MockAlter>( new MockAlter() );
    a->setValue( 2 );
    b->setValue( 1 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK(   b->isLessThan   ( *a ) )
    CHECK(   a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
TEST( comparisons_a_isEqualTo_b, IAlter )
{
    IAlterUPtr a = unique_ptr<IAlter>( new MockAlter() );
    IAlterUPtr b = unique_ptr<MockAlter>( new MockAlter() );
    a->setValue( 21 );
    b->setValue( 21 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK(   a->isEqualTo     ( *b ) )
    CHECK(   b->isEqualTo     ( *a ) )
}
TEST( increment, IAlter )
{
    IAlterUPtr a = unique_ptr<IAlter>( new MockAlter() );
    a->setValue( 100 );
    a->increment();
    CHECK_EQUAL( 101, a->getValue() )
}
TEST( decrement, IAlter )
{
    IAlterUPtr a = unique_ptr<IAlter>( new MockAlter() );
    a->setValue( 100 );
    a->decrement();
    CHECK_EQUAL( 99, a->getValue() )
}
TEST( isIdenticalTo, IAlter )
{
    IAlterUPtr a = unique_ptr<IAlter>( new MockAlter() );
    CHECK( a->isIdenticalTo( *a ) )
}