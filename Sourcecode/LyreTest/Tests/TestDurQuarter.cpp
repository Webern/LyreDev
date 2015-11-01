//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurQuarter.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 1 };
    String name{ "Quarter" };
}

TEST( getValue, DurQuarter )
{
    DurQuarter d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurQuarter )
{
    DurQuarter d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurQuarter )
{
    DurQuarter d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurQuarter )
{
    DurQuarter d;
    CHECK_EQUAL( name, d.toString() )
}
