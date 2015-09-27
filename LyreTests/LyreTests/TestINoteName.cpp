#include "cpulTestHarness.h"
#include "INoteName.h"
#include <sstream>

using namespace lyre;
using namespace std;

class TestNoteName;
using TestNoteNameUPtr = unique_ptr<TestNoteName>;
class TestNoteName : public INoteName
{
public:
    virtual ~TestNoteName() {}
    virtual INoteNameUPtr clone() const { return TestNoteNameUPtr{ new TestNoteName{} }; }
    /* template <typename T>
       void copyTo( std::unique_ptr<T>& output ) const */
    virtual Integer getValue() const { return 0; }
    virtual bool parse( const String& str ) { return true; }
    virtual std::ostream& toStream( std::ostream& os ) const { return os; }
    /* virtual String toString() const;
       virtual bool lessThan( const NoteName& other ) const;
       virtual bool greaterThan( const NoteName& other ) const;
       virtual bool equals( const NoteName& other ) const; */
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

TEST( compiles, INoteName )
{
    INoteNameUPtr p{ new TestNoteName{} };
    auto c = p->clone();
    TestNoteNameUPtr x;
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