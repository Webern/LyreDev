//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBaseLonga.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 16, 1 };
    String name{ STR_LONGA };
}

TEST( getValue, DurBaseLonga )
{
    DurBaseLonga d;
    CHECK_EQUAL( value, d.getValue() )
}
T_END

TEST( toStream, DurBaseLonga )
{
    DurBaseLonga d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( streamingOperator, DurBaseLonga )
{
    DurBaseLonga d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( toString, DurBaseLonga )
{
    DurBaseLonga d;
    CHECK_EQUAL( name, d.toString() )
}
T_END

