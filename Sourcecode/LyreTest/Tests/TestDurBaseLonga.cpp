//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurBaseLonga.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 16, 1 };
    String name{ "Longa" };
}

TEST( getValue, DurBaseLonga )
{
    DurBaseLonga d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurBaseLonga )
{
    DurBaseLonga d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurBaseLonga )
{
    DurBaseLonga d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurBaseLonga )
{
    DurBaseLonga d;
    CHECK_EQUAL( name, d.toString() )
}
