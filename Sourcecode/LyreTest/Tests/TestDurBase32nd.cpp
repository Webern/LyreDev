//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBase32nd.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 8 };
    String name{ STR_32ND };
}

TEST( getValue, DurBase32nd )
{
    DurBase32nd d;
    CHECK_EQUAL( value, d.getValue() )
}
T_END

TEST( toStream, DurBase32nd )
{
    DurBase32nd d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( streamingOperator, DurBase32nd )
{
    DurBase32nd d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( toString, DurBase32nd )
{
    DurBase32nd d;
    CHECK_EQUAL( name, d.toString() )
}
T_END

