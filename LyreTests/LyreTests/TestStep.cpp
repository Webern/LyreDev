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
    IStepSP p = std::make_shared<Step>();
    CHECK( true )
}
TEST( UniquePtr, Step )
{
    IStepUP p = unique_ptr<Step>( new Step() );
    CHECK( true )
}

TEST( Constructor01a, Step )
{
    Step s{ 5 };
    CHECK_EQUAL( 5, s.getValue() )
}
TEST( Constructor01b, Step )
{
    Step s{ INT_MIN };
    CHECK_EQUAL( 0, s.getValue() )
}
TEST( Constructor01c, Step )
{
    Step s{ INT_MAX };
    CHECK_EQUAL( 6, s.getValue() )
}
TEST( Constructor02, Step )
{
    Step s{ StepValue::D };
    CHECK_EQUAL( 1, s.getValue() )
}
TEST( Constructor03a, Step )
{
    Step s{ String{ "F" } };
    CHECK_EQUAL( 3, s.getValue() )
}
TEST( Constructor03b, Step )
{
    Step s{ String{ "BADINPUT" } };
    CHECK_EQUAL( 0, s.getValue() )
}
TEST( CopyConstructor01, Step )
{
    Step a{ 1 };
    Step b{ a };
    CHECK_EQUAL( 1, a.getValue() )
    CHECK_EQUAL( 1, b.getValue() )
    a.setValue( 2 );
    b.setValue( 5 );
    CHECK_EQUAL( 2, a.getValue() )
    CHECK_EQUAL( 5, b.getValue() )
}
TEST( MoveConstructor01, Step )
{
    Step a{ 1 };
    Step b{ std::move( a ) };
    CHECK_EQUAL( 1, b.getValue() )
    b.setValue( 5 );
    CHECK_EQUAL( 5, b.getValue() )
}
TEST( AssignmentOperator, Step )
{
    Step a{ 1 };
    Step b{ 4 };
    b = a;
    CHECK_EQUAL( 1, a.getValue() )
    CHECK_EQUAL( 1, b.getValue() )
    a.setValue( 2 );
    b.setValue( 5 );
    CHECK_EQUAL( 2, a.getValue() )
    CHECK_EQUAL( 5, b.getValue() )
}
TEST( MoveAssignment, Step )
{
    Step a{ 1 };
    Step b{ 4 };
    b = std::move( a );
    CHECK_EQUAL( 1, b.getValue() )
    b.setValue( 5 );
    CHECK_EQUAL( 5, b.getValue() )
}
TEST( clone, Step )
{
    IStepSP p1 = std::make_shared<Step>();
    p1->setValue( 4 );
    IStepSP p2 = p1->clone();
    CHECK( p1.get() != p2.get() )
    CHECK_EQUAL( 4, p1->getValue() );
    CHECK_EQUAL( 4, p2->getValue() );
    p2->setValue( 2 );
    CHECK_EQUAL( 4, p1->getValue() );
    CHECK_EQUAL( 2, p2->getValue() );
}
TEST( copyTo, Step )
{
    std::shared_ptr<Step> p1 = std::make_shared<Step>();
    p1->setValue( -1 );
    std::unique_ptr<Step> p2;
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
    IStepUP p = unique_ptr<Step>( new Step() );
    CHECK_EQUAL( 0, p->getMin() )
}
TEST( getMax, Step )
{
    IStepUP p = unique_ptr<Step>( new Step() );
    CHECK_EQUAL( 6, p->getMax() )
}
TEST( parse, Step )
{
    IStepUP p = unique_ptr<Step>( new Step() );
    p->setValue( 2 );
    CHECK_EQUAL( "E", p->toString() )
    CHECK( ! p->parse( "f" ) )
    CHECK_EQUAL( "E", p->toString() )
    CHECK( p->parse( "F" ) )
    CHECK_EQUAL( "F", p->toString() )
}
TEST( toStream, Step )
{
    IStepUP p = unique_ptr<Step>( new Step() );
    p->setValue( 1 );
    stringstream ss;
    p->toStream( ss );
    String expected = "D";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( toString, Step )
{
    IStepUP p = unique_ptr<Step>( new Step() );
    p->setValue( 6 );
    String expected = "B";
    String actual{ p->toString() };
    CHECK_EQUAL( expected, actual )
}
TEST( streamingOperator, Step )
{
    IStepUP p = unique_ptr<Step>( new Step() );
    p->setValue( 4 );
    stringstream ss;
    ss << ( *p );
    String expected = "G";
    String actual{ ss.str() };
    CHECK_EQUAL( expected, actual )
}
TEST( comparisons_a_isLessThan_b, Step )
{
    IStepUP a = unique_ptr<Step>( new Step() );
    IStepUP b = unique_ptr<Step>( new Step() );
    a->setValue( 1 );
    b->setValue( 2 );
    CHECK(   a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK(   b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
TEST( comparisons_a_isGreaterThan_b, Step )
{
    IStepUP a = unique_ptr<Step>( new Step() );
    IStepUP b = unique_ptr<Step>( new Step() );
    a->setValue( 2 );
    b->setValue( 1 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK(   b->isLessThan   ( *a ) )
    CHECK(   a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK( ! a->isEqualTo     ( *b ) )
    CHECK( ! b->isEqualTo     ( *a ) )
}
TEST( comparisons_a_isEqualTo_b, Step )
{
    IStepUP a = unique_ptr<Step>( new Step() );
    IStepUP b = unique_ptr<Step>( new Step() );
    a->setValue( 3 );
    b->setValue( 3 );
    CHECK( ! a->isLessThan   ( *b ) )
    CHECK( ! b->isLessThan   ( *a ) )
    CHECK( ! a->isGreaterThan( *b ) )
    CHECK( ! b->isGreaterThan( *a ) )
    CHECK(   a->isEqualTo     ( *b ) )
    CHECK(   b->isEqualTo     ( *a ) )
}
TEST( increment01, Step )
{
    IStepUP a = unique_ptr<Step>( new Step() );
    a->setValue( 1 );
    a->increment();
    CHECK_EQUAL( 2, a->getValue() )
}
TEST( increment02, Step )
{
    IStepUP a = unique_ptr<Step>( new Step() );
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
    IStepUP a = unique_ptr<Step>( new Step() );
    a->setValue( 2 );
    a->decrement();
    CHECK_EQUAL( 1, a->getValue() )
}
TEST( decrement02, Step )
{
    IStepUP a = unique_ptr<Step>( new Step() );
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
TEST( checkAllStringAndStepValueOutputs, Step )
{
    auto a = unique_ptr<Step>( new Step() );
    a->setValue( 0 );
    CHECK_EQUAL( "C", a->toString() )
    CHECK( a->getStepValue() == StepValue::C )
    a->increment();
    CHECK_EQUAL( "D", a->toString() )
    CHECK( a->getStepValue() == StepValue::D )
    a->increment();
    CHECK_EQUAL( "E", a->toString() )
    CHECK( a->getStepValue() == StepValue::E )
    a->increment();
    CHECK_EQUAL( "F", a->toString() )
    CHECK( a->getStepValue() == StepValue::F )
    a->increment();
    CHECK_EQUAL( "G", a->toString() )
    CHECK( a->getStepValue() == StepValue::G )
    a->increment();
    CHECK_EQUAL( "A", a->toString() )
    CHECK( a->getStepValue() == StepValue::A )
    a->increment();
    CHECK_EQUAL( "B", a->toString() )
    CHECK( a->getStepValue() == StepValue::B )
    a->increment();
    CHECK_EQUAL( "C", a->toString() )
    CHECK( a->getStepValue() == StepValue::C )
}
TEST( checkAllStringInputs, Step )
{
    auto a = unique_ptr<Step>( new Step() );
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
TEST( checkAllStepValueInputs, Step )
{
    auto a = unique_ptr<Step>( new Step() );
    a->setValue( 0 );
    a->setValue( StepValue::D );
    CHECK_EQUAL( 1, a->getValue() )
    a->setValue( StepValue::E );
    CHECK_EQUAL( 2, a->getValue() )
    a->setValue( StepValue::F );
    CHECK_EQUAL( 3, a->getValue() )
    a->setValue( StepValue::G );
    CHECK_EQUAL( 4, a->getValue() )
    a->setValue( StepValue::A );
    CHECK_EQUAL( 5, a->getValue() )
    a->setValue( StepValue::B );
    CHECK_EQUAL( 6, a->getValue() )
    a->setValue( StepValue::C );
    CHECK_EQUAL( 0, a->getValue() )
}
TEST( getPitchClassValue, Step )
{
    StepUP a = unique_ptr<Step>( new Step() );
    a->setValue( 0 );
    a->increment();
    CHECK_EQUAL( 2, a->getPitchClassValue() )
    a->increment();
    CHECK_EQUAL( 4, a->getPitchClassValue() )
    a->increment();
    CHECK_EQUAL( 5, a->getPitchClassValue() )
    a->increment();
    CHECK_EQUAL( 7, a->getPitchClassValue() )
    a->increment();
    CHECK_EQUAL( 9, a->getPitchClassValue() )
    a->increment();
    CHECK_EQUAL( 11, a->getPitchClassValue() )
    a->increment();
    CHECK_EQUAL( 0, a->getPitchClassValue() )
}
TEST( isIdenticalTo_true01, Step )
{
    StepUP a = unique_ptr<Step>( new Step( "A" ) );
    StepUP b = unique_ptr<Step>( new Step( "A" ) );
    CHECK( a->isIdenticalTo( *b ) )
}
TEST( isIdenticalTo_true02, Step )
{
    class MockStepA : public IStep
    {
    public:
        IStepUP clone() const
        {
            IStepUP value{ new MockStepA{ *this } };
            return value;
        }
        Integer getValue() const { return 5; }
        void setValue( const Integer val ) {}
        virtual bool isIdenticalTo( const IStep& other ) const { return true; }
        Integer getMin() const { return 0; }
        Integer getMax() const { return 6; }
        bool parse( const String& str ) { return true; }
        std::ostream& toStream( std::ostream& os ) const { return os << "A"; }
        bool extendedFunction() const { return true; }
        void increment() {}
        void decrement() {}
    };
    
    StepUP a = unique_ptr<Step>( new Step( "A" ) );
    std::unique_ptr<MockStepA> b{ new MockStepA{} };
    CHECK( a->isIdenticalTo( *b ) )
}
TEST( isIdenticalTo_false01, Step )
{
    StepUP a = unique_ptr<Step>( new Step( "A" ) );
    StepUP b = unique_ptr<Step>( new Step( "B" ) );
    CHECK( ! a->isIdenticalTo( *b ) )
}
TEST( isIdenticalTo_false02, Step )
{
    class MockStepX : public IStep
    {
    public:
        IStepUP clone() const
        {
            IStepUP value{ new MockStepX{ *this } };
            return value;
        }
        Integer getValue() const { return 5; }
        void setValue( const Integer val ) {}
        virtual bool isIdenticalTo( const IStep& other ) const { return true; }
        Integer getMin() const { return 0; }
        Integer getMax() const { return 6; }
        bool parse( const String& str ) { return true; }
        std::ostream& toStream( std::ostream& os ) const { return os << "X"; }
        bool extendedFunction() const { return true; }
        void increment() {}
        void decrement() {}
    };
    
    StepUP a = unique_ptr<Step>( new Step( "A" ) );
    std::unique_ptr<MockStepX> b{ new MockStepX{} };
    CHECK( ! a->isIdenticalTo( *b ) )
}