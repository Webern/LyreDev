//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockDur.h"
#include "Lyre/IDur.h"

using namespace Lyre;
using namespace Lyre::Mock;
using namespace std;

TEST( createMockDur, IDur )
{
    Rational val{ 3, 4 };
    String name{ "Test01" };
    IDurUP d = createMockDur( val, name );
    CHECK( d != nullptr )
}
TEST( getValue, IDur )
{
    Rational val{ 4, 3 };
    String name{ "Test02" };
    IDurUP d = createMockDur( val, name );
    CHECK_EQUAL( val, d->getValue() )
}
TEST( toStream, IDur )
{
    Rational val{ 9, 7 };
    String name{ "Test03" };
    IDurUP d = createMockDur( val, name );
    stringstream ss;
    d->toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, IDur )
{
    Rational val{ 9, 7 };
    String name{ "Test04" };
    IDurUP d = createMockDur( val, name );
    stringstream ss;
    ss << (*d);
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, IDur )
{
    Rational val{ 12, 13 };
    String name{ "Test05" };
    IDurUP d = createMockDur( val, name );
    CHECK_EQUAL( name, d->toString() )
}
