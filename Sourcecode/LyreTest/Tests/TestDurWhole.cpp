//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurWhole.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 4, 1 };
    String name{ "Whole" };
}

TEST( getValue, DurWhole )
{
    DurWhole d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurWhole )
{
    DurWhole d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurWhole )
{
    DurWhole d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurWhole )
{
    DurWhole d;
    CHECK_EQUAL( name, d.toString() )
}
