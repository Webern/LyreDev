//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBaseQuarter.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 1 };
    String name{ STR_QUARTER };
    int maxBeams{ DUR_MAX_BEAMS_QUARTER };
}

TEST( getValue, DurBaseQuarter )
{
    DurBaseQuarter d;
    CHECK_EQUAL( value, d.getValue() )
}
T_END

TEST( toStream, DurBaseQuarter )
{
    DurBaseQuarter d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( streamingOperator, DurBaseQuarter )
{
    DurBaseQuarter d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( toString, DurBaseQuarter )
{
    DurBaseQuarter d;
    CHECK_EQUAL( name, d.toString() )
}
T_END

TEST( getMaxBeams, DurBaseQuarter )
{
    DurBaseQuarter d;
    CHECK_EQUAL( maxBeams, d.getMaxBeams() )
}
T_END
