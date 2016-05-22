//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBaseHalf.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 2, 1 };
    String name{ STR_HALF };
}

TEST( getValue, DurBaseHalf )
{
    DurBaseHalf d;
    CHECK_EQUAL( value, d.getValue() )
}
T_END

TEST( toStream, DurBaseHalf )
{
    DurBaseHalf d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( streamingOperator, DurBaseHalf )
{
    DurBaseHalf d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( toString, DurBaseHalf )
{
    DurBaseHalf d;
    CHECK_EQUAL( name, d.toString() )
}
T_END

