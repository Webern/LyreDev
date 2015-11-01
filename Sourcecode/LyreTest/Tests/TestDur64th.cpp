//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/Dur64th.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 16 };
    String name{ "64th" };
}

TEST( getValue, Dur64th )
{
    Dur64th d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, Dur64th )
{
    Dur64th d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, Dur64th )
{
    Dur64th d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, Dur64th )
{
    Dur64th d;
    CHECK_EQUAL( name, d.toString() )
}
