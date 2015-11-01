//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurEighth.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 2 };
    String name{ "Eighth" };
}

TEST( getValue, DurEighth )
{
    DurEighth d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurEighth )
{
    DurEighth d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurEighth )
{
    DurEighth d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurEighth )
{
    DurEighth d;
    CHECK_EQUAL( name, d.toString() )
}
