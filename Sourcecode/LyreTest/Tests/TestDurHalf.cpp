//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurHalf.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 2, 1 };
    String name{ "Half" };
}

TEST( getValue, DurHalf )
{
    DurHalf d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurHalf )
{
    DurHalf d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurHalf )
{
    DurHalf d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurHalf )
{
    DurHalf d;
    CHECK_EQUAL( name, d.toString() )
}
