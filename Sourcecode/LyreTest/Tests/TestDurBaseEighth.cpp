//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBaseEighth.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 1, 2 };
    String name{ STR_EIGHTH };
}

TEST( getValue, DurBaseEighth )
{
    DurBaseEighth d;
    CHECK_EQUAL( value, d.getValue() )
}
T_END

TEST( toStream, DurBaseEighth )
{
    DurBaseEighth d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( streamingOperator, DurBaseEighth )
{
    DurBaseEighth d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( toString, DurBaseEighth )
{
    DurBaseEighth d;
    CHECK_EQUAL( name, d.toString() )
}
T_END

