//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBase256th.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 64 };
    String name{ "256th" };
}

TEST( getValue, DurBase256th )
{
    DurBase256th d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurBase256th )
{
    DurBase256th d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurBase256th )
{
    DurBase256th d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurBase256th )
{
    DurBase256th d;
    CHECK_EQUAL( name, d.toString() )
}
