//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBaseQuarter.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 1 };
    String name{ "Quarter" };
}

TEST( getValue, DurBaseQuarter )
{
    DurBaseQuarter d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurBaseQuarter )
{
    DurBaseQuarter d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurBaseQuarter )
{
    DurBaseQuarter d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurBaseQuarter )
{
    DurBaseQuarter d;
    CHECK_EQUAL( name, d.toString() )
}
