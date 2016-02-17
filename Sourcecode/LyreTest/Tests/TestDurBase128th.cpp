//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBase128th.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 32 };
    String name{ "128th" };
}

TEST( getValue, DurBase128th )
{
    DurBase128th d;
    CHECK_EQUAL( value, d.getValue() )
}
T_END

TEST( toStream, DurBase128th )
{
    DurBase128th d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( streamingOperator, DurBase128th )
{
    DurBase128th d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( toString, DurBase128th )
{
    DurBase128th d;
    CHECK_EQUAL( name, d.toString() )
}
T_END

