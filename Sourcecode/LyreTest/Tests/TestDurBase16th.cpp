//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBase16th.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 4 };
    String name{ STR_16TH };
}

TEST( getValue, DurBase16th )
{
    DurBase16th d;
    CHECK_EQUAL( value, d.getValue() )
}
T_END

TEST( toStream, DurBase16th )
{
    DurBase16th d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( streamingOperator, DurBase16th )
{
    DurBase16th d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( toString, DurBase16th )
{
    DurBase16th d;
    CHECK_EQUAL( name, d.toString() )
}
T_END

