//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/Dur16th.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 4 };
    String name{ "16th" };
}

TEST( getValue, Dur16th )
{
    Dur16th d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, Dur16th )
{
    Dur16th d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, Dur16th )
{
    Dur16th d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, Dur16th )
{
    Dur16th d;
    CHECK_EQUAL( name, d.toString() )
}
