//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBase64th.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 16 };
    String name{ "64th" };
}

TEST( getValue, DurBase64th )
{
    DurBase64th d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurBase64th )
{
    DurBase64th d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurBase64th )
{
    DurBase64th d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurBase64th )
{
    DurBase64th d;
    CHECK_EQUAL( name, d.toString() )
}
