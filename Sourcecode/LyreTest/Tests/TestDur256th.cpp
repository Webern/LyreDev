//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/Dur256th.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 64 };
    String name{ "256th" };
}

TEST( getValue, Dur256th )
{
    Dur256th d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, Dur256th )
{
    Dur256th d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, Dur256th )
{
    Dur256th d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, Dur256th )
{
    Dur256th d;
    CHECK_EQUAL( name, d.toString() )
}
