//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBaseWhole.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 4, 1 };
    String name{ STR_WHOLE };
}

TEST( getValue, DurBaseWhole )
{
    DurBaseWhole d;
    CHECK_EQUAL( value, d.getValue() )
}
T_END

TEST( toStream, DurBaseWhole )
{
    DurBaseWhole d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( streamingOperator, DurBaseWhole )
{
    DurBaseWhole d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( toString, DurBaseWhole )
{
    DurBaseWhole d;
    CHECK_EQUAL( name, d.toString() )
}
T_END
