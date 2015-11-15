//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBase8th.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 2 };
    String name{ "Eighth" };
}

TEST( getValue, DurBase8th )
{
    DurBase8th d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurBase8th )
{
    DurBase8th d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurBase8th )
{
    DurBase8th d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurBase8th )
{
    DurBase8th d;
    CHECK_EQUAL( name, d.toString() )
}
