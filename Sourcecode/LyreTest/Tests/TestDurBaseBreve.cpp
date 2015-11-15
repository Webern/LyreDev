//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBaseBreve.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 8, 1 };
    String name{ "Breve" };
}

TEST( getValue, DurBaseBreve )
{
    DurBaseBreve d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurBaseBreve )
{
    DurBaseBreve d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurBaseBreve )
{
    DurBaseBreve d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurBaseBreve )
{
    DurBaseBreve d;
    CHECK_EQUAL( name, d.toString() )
}
