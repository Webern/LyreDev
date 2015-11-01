//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBreve.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 8, 1 };
    String name{ "Breve" };
}

TEST( getValue, DurBreve )
{
    DurBreve d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurBreve )
{
    DurBreve d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurBreve )
{
    DurBreve d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurBreve )
{
    DurBreve d;
    CHECK_EQUAL( name, d.toString() )
}
