//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/Private/IEnumerable.h"

using namespace Lyre;
using namespace Lyre::Private;
using namespace std;

namespace
{
    FORWARD_DECLARE( FakeTestClass )

    class FakeTestClass
    {
    public:
        virtual ~FakeTestClass() {}
        FakeTestClass() : myValue( 0 ) {}
        FakeTestClass( Integer value ) : myValue( value ) {}
        FakeTestClassUP clone() const
        {
            return FakeTestClassUP{ new FakeTestClass{ this->getValue() } };
        }
        Integer getValue() const { return myValue; }
        void setValue( Integer value ) { myValue = value; }
    private:
        Integer myValue;
    };
}

TEST( DefaultCtor, IEnumerable )
{
    IEnumerable<FakeTestClass> fakes;
    CHECK( fakes.getIsEmpty() )
}

TEST( OtherCtor, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    CHECK( ! fakes.getIsEmpty() )
    CHECK_EQUAL( 3, fakes.getCount() )
    for ( int i = 0; i < fakes.getCount(); ++i )
    {
        CHECK_EQUAL( i, fakes.getCurrent()->getValue() )
        fakes.next();
    }
    CHECK( fakes.getIsEnd() )
}

TEST( getCount, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    CHECK_EQUAL( 2, fakes.getCount() )
}

TEST( getIsEmpty, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    CHECK( ! fakes.getIsEmpty() )
}

TEST( getCurrent, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
}

TEST( getCurrentThrowEmpty, IEnumerable )
{
    IEnumerable<FakeTestClass> fakes;
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getCurrent()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( getCurrentThrowEnd, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    fakes.last();
    fakes.next();
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getCurrent()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( getNext, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 3, fakes.getNext()->getValue() )
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
}

TEST( getNextThrowEmpty, IEnumerable )
{
    IEnumerable<FakeTestClass> fakes;
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getNext()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( getNextThrowLast, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    fakes.last();
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getNext()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( getNextThrowEnd, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    fakes.last();
    fakes.next();
    CHECK( fakes.getIsEnd() )
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getNext()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( getPrevious, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 1, fakes.getPrevious()->getValue() )
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
}

TEST( getPreviousThrowEmpty, IEnumerable )
{
    IEnumerable<FakeTestClass> fakes;
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getPrevious()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( getPreviousThrowFirst, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    fakes.first();
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getPrevious()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( getPreviousThrowEnd, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    fakes.last();
    fakes.next();
    CHECK( fakes.getIsEnd() )
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getPrevious()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( getIsEnd, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    fakes.last();
    fakes.next();
    CHECK( fakes.getIsEnd() )
}

TEST( last, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    fakes.last();
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
}

TEST( lastEmpty, IEnumerable )
{
    IEnumerable<FakeTestClass> fakes;
    fakes.last();
    CHECK( fakes.getIsEnd() )
}

TEST( next, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    int counter = 0;
    for ( FakeTestClassUPC item = fakes.getCurrent();
          ! fakes.getIsEnd();
          fakes.next(), ++counter, item = fakes.getCurrent() )
    {
        CHECK_EQUAL( counter, item->getValue() )
    }
    CHECK( fakes.getIsEnd() )
    CHECK( ! fakes.next() )
}

TEST( previous, IEnumerable )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    IEnumerable<FakeTestClass> fakes{ vec };
    fakes.last();
    for ( int i = 3; i >= 0; --i )
    {
        FakeTestClassUPC e = fakes.getCurrent()->clone();
        CHECK_EQUAL( i, fakes.getCurrent()->getValue() )
        if ( i > 0 )
        {
            CHECK( fakes.previous() );
        }
    }
    
    CHECK( ! fakes.previous() )
}



TEST( jump, IEnumerable )
{
    
    CHECK_EQUAL( "", "continue with tests of IEnumerable" )
}

