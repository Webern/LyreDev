//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBaseWhole.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 4, 1 };
    String name{ "Whole" };
}

TEST( getValue, DurBaseWhole )
{
    DurBaseWhole d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurBaseWhole )
{
    DurBaseWhole d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurBaseWhole )
{
    DurBaseWhole d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurBaseWhole )
{
    DurBaseWhole d;
    CHECK_EQUAL( name, d.toString() )
}
