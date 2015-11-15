//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBase32nd.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 8 };
    String name{ "32nd" };
}

TEST( getValue, DurBase32nd )
{
    DurBase32nd d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurBase32nd )
{
    DurBase32nd d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurBase32nd )
{
    DurBase32nd d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurBase32nd )
{
    DurBase32nd d;
    CHECK_EQUAL( name, d.toString() )
}
