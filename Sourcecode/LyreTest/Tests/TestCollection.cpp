//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/Private/Collection.h"

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
        FakeTestClass( int value ) : myValue( value ) {}
        FakeTestClassUP clone() const
        {
            return FakeTestClassUP{ new FakeTestClass{ this->getValue() } };
        }
        int getValue() const { return myValue; }
        void setValue( int value ) { myValue = value; }
    private:
        int myValue;
    };
    
    using FakeTestClassVector = std::vector<FakeTestClass>;
}

/*******************************************************************************
Test with stack objects
*******************************************************************************/

TEST( SO_DefaultCtor, Collection )
{
    Collection<FakeTestClass> fakes;
    CHECK( fakes.getIsEmpty() )
}
T_END

TEST( SO_OtherCtor, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    Collection<FakeTestClass> fakes{ vec };
    CHECK( ! fakes.getIsEmpty() )
    CHECK_EQUAL( 3, fakes.getCount() )
    for ( int i = 0; i < fakes.getCount(); ++i )
    {
        CHECK_EQUAL( i, fakes.getCurrent().getValue() )
        fakes.next();
    }
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SO_getCount, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    Collection<FakeTestClass> fakes{ vec };
    CHECK_EQUAL( 2, fakes.getCount() )
}
T_END

TEST( SO_getIsEmpty, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    Collection<FakeTestClass> fakes{ vec };
    CHECK( ! fakes.getIsEmpty() )
}
T_END

TEST( SO_getCurrent, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 2, fakes.getCurrent().getValue() )
}
T_END

TEST( SO_getCurrentThrowEmpty, Collection )
{
    Collection<FakeTestClass> fakes;
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getCurrent().getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_getCurrentThrowEnd, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.last();
    fakes.next();
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getCurrent().getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_getNext, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 3, fakes.getNext().getValue() )
    CHECK_EQUAL( 2, fakes.getCurrent().getValue() )
}
T_END

TEST( SO_getNextThrowEmpty, Collection )
{
    Collection<FakeTestClass> fakes;
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getNext().getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_getNextThrowLast, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.last();
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getNext().getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_getNextThrowEnd, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.last();
    fakes.next();
    CHECK( fakes.getIsEnd() )
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getNext().getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_getPrevious, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 1, fakes.getPrevious().getValue() )
    CHECK_EQUAL( 2, fakes.getCurrent().getValue() )
}
T_END

TEST( SO_getPreviousThrowEmpty, Collection )
{
    Collection<FakeTestClass> fakes;
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getPrevious().getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_getPreviousThrowFirst, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.first();
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getPrevious().getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_getPreviousThrowEnd, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.last();
    fakes.next();
    CHECK( fakes.getIsEnd() )
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getPrevious().getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_getIsEnd, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.last();
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SO_last, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.last();
    CHECK_EQUAL( 3, fakes.getCurrent().getValue() )
}
T_END

TEST( SO_lastEmpty, Collection )
{
    Collection<FakeTestClass> fakes;
    fakes.last();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SO_next, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    int counter = 0;
    for ( auto item = fakes.getCurrent();
         ! fakes.getIsEnd();
         fakes.next(), ++counter )
    {
        item = fakes.getCurrent();
        CHECK_EQUAL( counter, item.getValue() )
    }
    CHECK( fakes.getIsEnd() )
    CHECK( ! fakes.next() )
}
T_END

TEST( SO_previous, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.last();
    for ( int i = 3; i >= 0; --i )
    {
        auto e = fakes.getCurrent().clone();
        CHECK_EQUAL( i, fakes.getCurrent().getValue() )
        if ( i > 0 )
        {
            CHECK( fakes.previous() );
        }
    }
    
    CHECK( ! fakes.previous() )
}
T_END

TEST( SO_jumpThrowEmpty, Collection )
{
    Collection<FakeTestClass> fakes;
    fakes.last();
    CHECK( fakes.getIsEnd() )
    bool isExceptionThrown = false;
    try
    {
        fakes.jump( 0 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_jumpThrowNegative, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.jump( -1 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_jumpThrowTooBig, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.jump( 4 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_jump, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 2, fakes.getCurrent().getValue() )
    fakes.jump( 0 );
    CHECK_EQUAL( 0, fakes.getCurrent().getValue() )
    fakes.jump( 3 );
    CHECK_EQUAL( 3, fakes.getCurrent().getValue() )
}
T_END

TEST( SO_add, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.add( FakeTestClass{ 4 } );
    fakes.jump( 4 );
    CHECK_EQUAL( 4, fakes.getCurrent().getValue() )
}
T_END

TEST( SO_remove_afterCurrent, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.jump( 2 );
    fakes.remove( 3 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 2, fakes.getCurrent().getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK_EQUAL( 1, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK_EQUAL( 2, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SO_remove_current, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.jump( 2 );
    fakes.remove( 2 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 3, fakes.getCurrent().getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK_EQUAL( 1, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK_EQUAL( 3, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SO_remove_beforeCurrent, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.jump( 2 );
    fakes.remove( 1 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 2, fakes.getCurrent().getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK_EQUAL( 2, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK_EQUAL( 3, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SO_remove_first, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.remove( 0 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 1, fakes.getCurrent().getValue() )
    fakes.first();
    CHECK_EQUAL( 1, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK_EQUAL( 2, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK_EQUAL( 3, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SO_remove_last, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.remove( 3 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 0, fakes.getCurrent().getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK_EQUAL( 1, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK_EQUAL( 2, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SO_remove_throwLow, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.remove( -1 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_remove_throwHigh, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.remove( 4 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_removeCurrent, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    fakes.jump( 2 );
    fakes.removeCurrent();
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 3, fakes.getCurrent().getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK_EQUAL( 1, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK_EQUAL( 3, fakes.getCurrent().getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SO_getExceptionEmpty, Collection )
{
    Collection<FakeTestClass> fakes;
    bool isExceptionThrown = false;
    try
    {
        fakes.get( 0 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_getExceptionLow, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.get( -1 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_getExceptionHigh, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.get( 4 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SO_get, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    auto retreived = fakes.get( 2 );
    int expected = 2;
    int actual = retreived.getValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getCurrentIndex_ExceptionEmpty, Collection )
{
    Collection<FakeTestClass> fakes;
    bool isExceptionThrown = false;
    try
    {
        fakes.getCurrentIndex();
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( getCurrentIndex, Collection )
{
    FakeTestClassVector vec;
    vec.push_back( FakeTestClass{ 0 } );
    vec.push_back( FakeTestClass{ 1 } );
    vec.push_back( FakeTestClass{ 2 } );
    vec.push_back( FakeTestClass{ 3 } );
    Collection<FakeTestClass> fakes{ vec };
    CHECK_EQUAL( 0, fakes.getCurrentIndex() )
    fakes.jump( 2 );
    CHECK_EQUAL( 2, fakes.getCurrentIndex() )
    fakes.jump( 1 );
    CHECK_EQUAL( 1, fakes.getCurrentIndex() )
    fakes.jump( 3 );
    CHECK_EQUAL( 3, fakes.getCurrentIndex() )
}
T_END

/*******************************************************************************
Test with unique pointers
*******************************************************************************/

TEST( UP_DefaultCtor, Collection )
{
    Collection<FakeTestClassUP> fakes;
    CHECK( fakes.getIsEmpty() )
}
T_END

TEST( UP_OtherCtor, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    CHECK( ! fakes.getIsEmpty() )
    CHECK_EQUAL( 3, fakes.getCount() )
    for ( int i = 0; i < fakes.getCount(); ++i )
    {
        CHECK_EQUAL( i, fakes.getCurrent()->getValue() )
        fakes.next();
    }
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( UP_getCount, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    CHECK_EQUAL( 2, fakes.getCount() )
}
T_END

TEST( UP_getIsEmpty, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    CHECK( ! fakes.getIsEmpty() )
}
T_END

TEST( UP_getCurrent, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
}
T_END

TEST( UP_getCurrentThrowEmpty, Collection )
{
    Collection<FakeTestClassUP> fakes;
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getCurrent()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_getCurrentThrowEnd, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
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
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_getNext, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 3, fakes.getNext()->getValue() )
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
}
T_END

TEST( UP_getNextThrowEmpty, Collection )
{
    Collection<FakeTestClassUP> fakes;
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getNext()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_getNextThrowLast, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.last();
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getNext()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_getNextThrowEnd, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
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
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_getPrevious, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 1, fakes.getPrevious()->getValue() )
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
}
T_END

TEST( UP_getPreviousThrowEmpty, Collection )
{
    Collection<FakeTestClassUP> fakes;
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getPrevious()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_getPreviousThrowFirst, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.first();
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getPrevious()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_getPreviousThrowEnd, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
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
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_getIsEnd, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.last();
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( UP_last, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.last();
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
}
T_END

TEST( UP_lastEmpty, Collection )
{
    Collection<FakeTestClassUP> fakes;
    fakes.last();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( UP_next, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    int counter = 0;
    for ( FakeTestClassUPC item = fakes.getCurrent();
          ! fakes.getIsEnd();
          fakes.next(), ++counter )
    {
        item = fakes.getCurrent();
        CHECK_EQUAL( counter, item->getValue() )
    }
    CHECK( fakes.getIsEnd() )
    CHECK( ! fakes.next() )
}
T_END

TEST( UP_previous, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
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
T_END

TEST( UP_jumpThrowEmpty, Collection )
{
    Collection<FakeTestClassUP> fakes;
    fakes.last();
    CHECK( fakes.getIsEnd() )
    bool isExceptionThrown = false;
    try
    {
        fakes.jump( 0 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_jumpThrowNegative, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.jump( -1 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_jumpThrowTooBig, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.jump( 4 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_jump, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.jump( 0 );
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.jump( 3 );
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
}
T_END

TEST( UP_add, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.add( FakeTestClassUP{ new FakeTestClass{ 4 } } );
    fakes.jump( 4 );
    CHECK_EQUAL( 4, fakes.getCurrent()->getValue() )
}
T_END

TEST( UP_addThrowNull, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.add( FakeTestClassUP{ nullptr } );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_remove_afterCurrent, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.jump( 2 );
    fakes.remove( 3 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 1, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( UP_remove_current, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.jump( 2 );
    fakes.remove( 2 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 1, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( UP_remove_beforeCurrent, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.jump( 2 );
    fakes.remove( 1 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( UP_remove_first, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.remove( 0 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 1, fakes.getCurrent()->getValue() )
    fakes.first();
    CHECK_EQUAL( 1, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( UP_remove_last, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.remove( 3 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 1, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( UP_remove_throwLow, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.remove( -1 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_remove_throwHigh, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.remove( 4 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_removeCurrent, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    fakes.jump( 2 );
    fakes.removeCurrent();
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 1, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( UP_getExceptionEmpty, Collection )
{
    Collection<FakeTestClassUP> fakes;
    bool isExceptionThrown = false;
    try
    {
        fakes.get( 0 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_getExceptionLow, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.get( -1 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_getExceptionHigh, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.get( 4 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_get, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    auto retreived = fakes.get( 2 );
    int expected = 2;
    int actual = retreived->getValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( UP_getCurrentIndex_ExceptionEmpty, Collection )
{
    Collection<FakeTestClass> fakes;
    bool isExceptionThrown = false;
    try
    {
        fakes.getCurrentIndex();
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( UP_getCurrentIndex, Collection )
{
    VecFakeTestClassUP vec;
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassUP { new FakeTestClass{ 3 } } );
    Collection<FakeTestClassUP> fakes{ vec };
    CHECK_EQUAL( 0, fakes.getCurrentIndex() )
    fakes.jump( 2 );
    CHECK_EQUAL( 2, fakes.getCurrentIndex() )
    fakes.jump( 1 );
    CHECK_EQUAL( 1, fakes.getCurrentIndex() )
    fakes.jump( 3 );
    CHECK_EQUAL( 3, fakes.getCurrentIndex() )
}
T_END


/*******************************************************************************
Test with shared pointers
*******************************************************************************/

TEST( SP_DefaultCtor, Collection )
{
    Collection<FakeTestClassSP> fakes;
    CHECK( fakes.getIsEmpty() )
}
T_END

TEST( SP_OtherCtor, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    CHECK( ! fakes.getIsEmpty() )
    CHECK_EQUAL( 3, fakes.getCount() )
    for ( int i = 0; i < fakes.getCount(); ++i )
    {
        CHECK_EQUAL( i, fakes.getCurrent()->getValue() )
        fakes.next();
    }
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SP_getCount, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    CHECK_EQUAL( 2, fakes.getCount() )
}
T_END

TEST( SP_getIsEmpty, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    CHECK( ! fakes.getIsEmpty() )
}
T_END

TEST( SP_getCurrent, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
}
T_END

TEST( SP_getCurrentThrowEmpty, Collection )
{
    Collection<FakeTestClassSP> fakes;
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getCurrent()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_getCurrentThrowEnd, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
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
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_getNext, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 3, fakes.getNext()->getValue() )
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
}
T_END

TEST( SP_getNextThrowEmpty, Collection )
{
    Collection<FakeTestClassSP> fakes;
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getNext()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_getNextThrowLast, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.last();
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getNext()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_getNextThrowEnd, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
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
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_getPrevious, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 1, fakes.getPrevious()->getValue() )
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
}
T_END

TEST( SP_getPreviousThrowEmpty, Collection )
{
    Collection<FakeTestClassSP> fakes;
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getPrevious()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_getPreviousThrowFirst, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.first();
    bool isExceptionThrown = false;
    try
    {
        int i = fakes.getPrevious()->getValue();
        ++i;
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_getPreviousThrowEnd, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
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
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_getIsEnd, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.last();
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SP_last, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.last();
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
}
T_END

TEST( SP_lastEmpty, Collection )
{
    Collection<FakeTestClassSP> fakes;
    fakes.last();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SP_next, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    int counter = 0;
    for ( FakeTestClassSPC item = fakes.getCurrent();
         ! fakes.getIsEnd();
         fakes.next(), ++counter )
    {
        item = fakes.getCurrent();
        CHECK_EQUAL( counter, item->getValue() )
    }
    CHECK( fakes.getIsEnd() )
    CHECK( ! fakes.next() )
}
T_END

TEST( SP_previous, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.last();
    for ( int i = 3; i >= 0; --i )
    {
        FakeTestClassSPC e = fakes.getCurrent()->clone();
        CHECK_EQUAL( i, fakes.getCurrent()->getValue() )
        if ( i > 0 )
        {
            CHECK( fakes.previous() );
        }
    }
    
    CHECK( ! fakes.previous() )
}
T_END

TEST( SP_jumpThrowEmpty, Collection )
{
    Collection<FakeTestClassSP> fakes;
    fakes.last();
    CHECK( fakes.getIsEnd() )
    bool isExceptionThrown = false;
    try
    {
        fakes.jump( 0 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_jumpThrowNegative, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.jump( -1 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_jumpThrowTooBig, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.jump( 4 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_jump, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.jump( 2 );
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.jump( 0 );
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.jump( 3 );
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
}
T_END

TEST( SP_add, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.add( FakeTestClassSP{ new FakeTestClass{ 4 } } );
    fakes.jump( 4 );
    CHECK_EQUAL( 4, fakes.getCurrent()->getValue() )
}
T_END

TEST( SP_addThrowNull, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.add( FakeTestClassSP{ nullptr } );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_remove_afterCurrent, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.jump( 2 );
    fakes.remove( 3 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 1, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SP_remove_current, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.jump( 2 );
    fakes.remove( 2 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 1, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SP_remove_beforeCurrent, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.jump( 2 );
    fakes.remove( 1 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SP_remove_first, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.remove( 0 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 1, fakes.getCurrent()->getValue() )
    fakes.first();
    CHECK_EQUAL( 1, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SP_remove_last, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.remove( 3 );
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 1, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 2, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SP_remove_throwLow, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.remove( -1 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_remove_throwHigh, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.remove( 4 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_removeCurrent, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP{ new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    fakes.jump( 2 );
    fakes.removeCurrent();
    CHECK_EQUAL( 3, fakes.getCount() )
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
    fakes.first();
    CHECK_EQUAL( 0, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 1, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK_EQUAL( 3, fakes.getCurrent()->getValue() )
    fakes.next();
    CHECK( fakes.getIsEnd() )
}
T_END

TEST( SP_getExceptionEmpty, Collection )
{
    Collection<FakeTestClassSP> fakes;
    bool isExceptionThrown = false;
    try
    {
        fakes.get( 0 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_getExceptionLow, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.get( -1 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_getExceptionHigh, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    bool isExceptionThrown = false;
    try
    {
        fakes.get( 4 );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_get, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    auto retreived = fakes.get( 2 );
    int expected = 2;
    int actual = retreived->getValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( SP_getCurrentIndex_ExceptionEmpty, Collection )
{
    Collection<FakeTestClass> fakes;
    bool isExceptionThrown = false;
    try
    {
        fakes.getCurrentIndex();
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( SP_getCurrentIndex, Collection )
{
    VecFakeTestClassSP vec;
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 0 } } );
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 1 } } );
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 2 } } );
    vec.push_back( FakeTestClassSP { new FakeTestClass{ 3 } } );
    Collection<FakeTestClassSP> fakes{ vec };
    CHECK_EQUAL( 0, fakes.getCurrentIndex() )
    fakes.jump( 2 );
    CHECK_EQUAL( 2, fakes.getCurrentIndex() )
    fakes.jump( 1 );
    CHECK_EQUAL( 1, fakes.getCurrentIndex() )
    fakes.jump( 3 );
    CHECK_EQUAL( 3, fakes.getCurrentIndex() )
}
T_END

