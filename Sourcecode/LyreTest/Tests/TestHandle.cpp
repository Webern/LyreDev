//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Handle.h"
#include <memory>

using namespace Lyre;
using namespace std;

namespace
{
    class TestObject
    {
    public:
        TestObject() : publicValue( 0 ), myValue( 0 ) {}
        int publicValue;
        int getPrivateValue() const { return myValue; }
        void setPrivateValue( const int value ) { myValue = value; }
    private:
        int myValue;
    };
}

TEST( mutablePtrInt, Handle )
{
    int* x = new int{ 1 };
    Handle<int> h{ x };
    *h = 5;
    CHECK_EQUAL( 5, *h )
    delete x;
}
T_END

TEST( mutablePtrObj, Handle )
{
    std::unique_ptr<TestObject> uptr{ new TestObject{} };
    Handle<TestObject> h{ uptr.get() };
    h->publicValue = 10;
    h->setPrivateValue( 11 );
    CHECK_EQUAL( 10, h->publicValue )
    CHECK_EQUAL( 11, h->getPrivateValue() )
}
T_END