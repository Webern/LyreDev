#include "cpulTestHarness.h"
#include "IPitchName.h"
#include <sstream>

using namespace lyre;
using namespace std;

class TestPitchName;
using TestPitchNameUPtr = unique_ptr<TestPitchName>;
class TestPitchName : public IPitchName
{
public:
    virtual ~TestPitchName() {}
    virtual IPitchNameUPtr clone() const { return TestPitchNameUPtr{ new TestPitchName{} }; }
    /* template <typename T>
       void copyTo( std::unique_ptr<T>& output ) const */
    virtual Integer getValue() const { return 0; }
    virtual bool parse( const String& str ) { return true; }
    virtual std::ostream& toStream( std::ostream& os ) const { return os; }
    /* virtual String toString() const;
       virtual bool lessThan( const PitchName& other ) const;
       virtual bool greaterThan( const PitchName& other ) const;
       virtual bool equals( const PitchName& other ) const; */
    virtual Integer getStepValue() const { return 0; }
    virtual void setStepValue( const Integer val ) {}
    virtual Integer getMinStepValue() const { return 0; }
    virtual Integer getMaxStepValue() const { return 0; }
    virtual void incrementStep() {}
    virtual void decrementStep() {}
    virtual Integer getAlterValue() const { return 0; }
    virtual void setAlterValue( const Integer val ) {}
    virtual Integer getMinAlterValue() const { return 0; }
    virtual Integer getMaxAlterValue() const { return 0; }
    virtual void incrementAlter() {}
    virtual void decrementAlter() {}
};

TEST( compiles, IPitchName )
{
    IPitchNameUPtr p{ new TestPitchName{} };
    auto c = p->clone();
    TestPitchNameUPtr x;
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
    CHECK( ! p->lessThan( *x ) )
    CHECK( p->equals( *x ) )
    CHECK( ! p->greaterThan( *c ) )
    CHECK_EQUAL( 0, p->getStepValue() )
    p->setStepValue( 0 );
    CHECK_EQUAL( 0, p->getMinStepValue() )
    CHECK_EQUAL( 0, p->getMaxStepValue() )
    p->incrementStep();
    p->decrementStep();
    CHECK_EQUAL( 0, p->getAlterValue() )
    p->setAlterValue( 0 );
    CHECK_EQUAL( 0, p->getMinAlterValue() )
    CHECK_EQUAL( 0, p->getMaxAlterValue() )
    p->incrementAlter();
    p->decrementAlter();
}