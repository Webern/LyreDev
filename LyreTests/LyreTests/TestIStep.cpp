#include "cpulTestHarness.h"
#include "IStep.h"
#include <sstream>

using namespace lyre;
using namespace std;

class MockStep : public IStep
{
public:
    IStepUPtr clone() const
    {
        IStepUPtr value{ new MockStep{ *this } };
        return value;
    }
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

TEST( Compiles, IStep )
{
    MockStep m;
    CHECK( true )
}
TEST( SharedPtr, IStep )
{
    IStepPtr p = std::make_shared<MockStep>();
    CHECK( true )
}
TEST( UniquePtr, IStep )
{
    IStepUPtr p = unique_ptr<MockStep>( new MockStep() );
    CHECK( true )
}
TEST( clone, IStep )
{
    IStepPtr p1 = std::make_shared<MockStep>();
    p1->setValue( 100 );
    IStepPtr p2 = p1->clone();
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 100, p2->getValue() );
    p2->setValue( 200 );
    CHECK_EQUAL( 100, p1->getValue() );
    CHECK_EQUAL( 200, p2->getValue() );
}
TEST( covariantClone, IStep )
{
    std::shared_ptr<MockStep> p1 = std::make_shared<MockStep>();
    p1->setValue( 100 );
    std::unique_ptr<MockStep> p2;
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
TEST( getMin, IStep )
{
    IStepUPtr p = unique_ptr<MockStep>( new MockStep() );
    CHECK_EQUAL( 0, p->getMin() )
}
TEST( getMax, IStep )
{
    IStepUPtr p = unique_ptr<MockStep>( new MockStep() );
    CHECK_EQUAL( 1, p->getMax() )
}
TEST( parse, IStep )
{
    IStepUPtr p = unique_ptr<MockStep>( new MockStep() );
    CHECK( p->parse( "" ) )
}
TEST( toStream, IStep )
{
    IStepUPtr p = unique_ptr<MockStep>( new MockStep() );
    p->setValue( 13 );
    stringstream ss;
    p->toStream( ss );
    String expected = "13";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString, IStep )
{
    IStepUPtr p = unique_ptr<MockStep>( new MockStep() );
    p->setValue( 13 );
    String expected = "13";
    String actual{ p->toString() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator, IStep )
{
    IStepUPtr p = unique_ptr<MockStep>( new MockStep() );
    p->setValue( 13 );
    stringstream ss;
    ss << ( *p );
    String expected = "13";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( comparisons_a_isLessThan_b, IStep )
{
    IStepUPtr a = unique_ptr<MockStep>( new MockStep() );
    IStepUPtr b = unique_ptr<IStep>( new MockStep() );
    a->setValue( 1 );
    b->setValue( 2 );
    CHECK(   a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK(   b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
TEST( comparisons_a_isGreaterThan_b, IStep )
{
    IStepUPtr a = unique_ptr<IStep>( new MockStep() );
    IStepUPtr b = unique_ptr<MockStep>( new MockStep() );
    a->setValue( 2 );
    b->setValue( 1 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK(   b->isLessThan   ( *a ) )
    CHECK(   a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
TEST( comparisons_a_isEqualTo_b, IStep )
{
    IStepUPtr a = unique_ptr<IStep>( new MockStep() );
    IStepUPtr b = unique_ptr<MockStep>( new MockStep() );
    a->setValue( 21 );
    b->setValue( 21 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK(   a->isEqualTo     ( *b ) )
    CHECK(   b->isEqualTo     ( *a ) )
}
TEST( increment, IStep )
{
    IStepUPtr a = unique_ptr<IStep>( new MockStep() );
    a->setValue( 100 );
    a->increment();
    CHECK_EQUAL( 101, a->getValue() )
}
TEST( decrement, IStep )
{
    IStepUPtr a = unique_ptr<IStep>( new MockStep() );
    a->setValue( 100 );
    a->decrement();
    CHECK_EQUAL( 99, a->getValue() )
}