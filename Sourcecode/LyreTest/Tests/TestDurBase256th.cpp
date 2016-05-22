//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBase256th.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 64 };
    String name{ STR_256TH };
}

TEST( getValue, DurBase256th )
{
    DurBase256th d;
    CHECK_EQUAL( value, d.getValue() )
}
T_END

TEST( toStream, DurBase256th )
{
    DurBase256th d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( streamingOperator, DurBase256th )
{
    DurBase256th d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( toString, DurBase256th )
{
    DurBase256th d;
    CHECK_EQUAL( name, d.toString() )
}
T_END

