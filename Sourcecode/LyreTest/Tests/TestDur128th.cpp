//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/Dur128th.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 32 };
    String name{ "128th" };
}

TEST( getValue, Dur128th )
{
    Dur128th d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, Dur128th )
{
    Dur128th d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, Dur128th )
{
    Dur128th d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, Dur128th )
{
    Dur128th d;
    CHECK_EQUAL( name, d.toString() )
}
