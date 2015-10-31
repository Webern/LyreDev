//PUBLIC
#include "LyreUnitTests/cpulTestHarness.h"
#include "Lyre/IPitch.h"
#include <sstream>

using namespace lyre;
using namespace std;

class TestPitchMock;
using TestPitchMockUP = unique_ptr<TestPitchMock>;
class TestPitchMock : public IPitch
{
public:
    virtual ~TestPitchMock() {}
    virtual IPitchUP clone() const { return TestPitchMockUP{ new TestPitchMock{} }; }
    /* void copyTo( std::unique_ptr<T>& output ) const */
    virtual Integer getValue() const { return 0; }
    virtual bool parse( const String& str ) { return true; }
    virtual std::ostream& toStream( std::ostream& os ) const { return os; }
    /* virtual String toString() const;
       virtual bool isLessThan( const Pitch& other ) const;
       virtual bool isGreaterThan( const Pitch& other ) const;
       virtual bool isEqualTo( const Pitch& other ) const; */
    virtual bool isIdenticalTo( const IPitch& other ) const { return true; }
    virtual Integer getStepValue() const { return 0; }
    virtual void setStepValue( const Integer val ) {}
    virtual void incrementStep() {}
    virtual void decrementStep() {}
    virtual Integer getAlterValue() const { return 0; }
    virtual void setAlterValue( const Integer val ) {}
    virtual void incrementAlter() {}
    virtual void decrementAlter() {}
    virtual Integer getOctaveValue() const { return 0; }
    virtual void setOctaveValue( const Integer val ) {}
    virtual void incrementOctave() {}
    virtual void decrementOctave() {}
};

TEST( compiles, IPitch )
{
    IPitchUP p{ new TestPitchMock{} };
    auto c = p->clone();
    TestPitchMockUP x;
    p->copyTo( x );
    CHECK( p != c )
    CHECK( p != x )
    CHECK( x != c )
    CHECK( (p) )
    CHECK( (c) )
    CHECK( (x) )
    CHECK_EQUAL( 0, p->getValue() )
    CHECK( p->parse( "" ) )
    stringstream ss;
    p->toStream( ss );
    CHECK_EQUAL( "", ss.str() )
    CHECK_EQUAL( "", p->toString() )
    ss << (*p);
    CHECK_EQUAL( "", ss.str() )
    CHECK( ! p->isLessThan( *x ) )
    CHECK( p->isEqualTo( *x ) )
    CHECK( ! p->isGreaterThan( *c ) )
    CHECK_EQUAL( 0, p->getStepValue() )
    p->setStepValue( 0 );
    p->incrementStep();
    p->decrementStep();
    CHECK_EQUAL( 0, p->getAlterValue() )
    p->setAlterValue( 0 );
    p->incrementAlter();
    p->decrementAlter();
    CHECK_EQUAL( 0, p->getOctaveValue() )
    p->setOctaveValue( 0 );
    p->incrementOctave();
    p->decrementOctave();
    p->isIdenticalTo( *p );
}