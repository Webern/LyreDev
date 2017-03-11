//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBaseBreve.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 8, 1 };
    String name{ STR_BREVE };
    int maxBeams{ DUR_MAX_BEAMS_BREVE };
}

TEST( getValue, DurBaseBreve )
{
    DurBaseBreve d;
    CHECK_EQUAL( value, d.getValue() )
}
T_END

TEST( toStream, DurBaseBreve )
{
    DurBaseBreve d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( streamingOperator, DurBaseBreve )
{
    DurBaseBreve d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( toString, DurBaseBreve )
{
    DurBaseBreve d;
    CHECK_EQUAL( name, d.toString() )
}
T_END

TEST( getMaxBeams, DurBaseBreve )
{
    DurBaseBreve d;
    CHECK_EQUAL( maxBeams, d.getMaxBeams() )
}
T_END

