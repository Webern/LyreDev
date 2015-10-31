//PRIVATE
#include "LyreUnitTests/cpulTestHarness.h"
#include "Lyre/IPitchName.h"
#include <sstream>

using namespace lyre;
using namespace std;

class TestPitchName;
using TestPitchNameUP = unique_ptr<TestPitchName>;
class TestPitchName : public IPitchName
{
public:
    virtual ~TestPitchName() {}
    virtual IPitchNameUP clone() const { return TestPitchNameUP{ new TestPitchName{} }; }
    /* template <typename T>
       void copyTo( std::unique_ptr<T>& output ) const */
    virtual Integer getValue() const { return 0; }
    virtual bool parse( const String& str ) { return true; }
    virtual std::ostream& toStream( std::ostream& os ) const { return os; }
    /* virtual String toString() const;
       virtual bool isLessThan( const PitchName& other ) const;
       virtual bool isGreaterThan( const PitchName& other ) const;
       virtual bool isEqualTo( const PitchName& other ) const; */
    virtual bool isIdenticalTo( const IPitchName& other ) const { return true; }
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
    IPitchNameUP p{ new TestPitchName{} };
    auto c = p->clone();
    TestPitchNameUP x;
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
    p->isIdenticalTo( *p );
}