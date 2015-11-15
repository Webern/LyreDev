//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockDurBase.h"
#include "Lyre/IDurBase.h"

using namespace Lyre;
using namespace Lyre::Mock;
using namespace std;

TEST( createMockDur, IDurBase )
{
    Rational val{ 3, 4 };
    String name{ "Test01" };
    IDurBaseUP d = createMockDurBase( val, name );
    CHECK( d != nullptr )
}
TEST( getValue, IDurBase )
{
    Rational val{ 4, 3 };
    String name{ "Test02" };
    IDurBaseUP d = createMockDurBase( val, name );
    CHECK_EQUAL( val, d->getValue() )
}
TEST( toStream, IDurBase )
{
    Rational val{ 9, 7 };
    String name{ "Test03" };
    IDurBaseUP d = createMockDurBase( val, name );
    stringstream ss;
    d->toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, IDurBase )
{
    Rational val{ 9, 7 };
    String name{ "Test04" };
    IDurBaseUP d = createMockDurBase( val, name );
    stringstream ss;
    ss << (*d);
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, IDurBase )
{
    Rational val{ 12, 13 };
    String name{ "Test05" };
    IDurBaseUP d = createMockDurBase( val, name );
    CHECK_EQUAL( name, d->toString() )
}
