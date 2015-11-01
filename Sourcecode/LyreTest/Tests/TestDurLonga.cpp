//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "Lyre/Private/DurLonga.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    Rational value{ 16, 1 };
    String name{ "Longa" };
}

TEST( getValue, DurLonga )
{
    DurLonga d;
    CHECK_EQUAL( value, d.getValue() )
}
TEST( toStream, DurLonga )
{
    DurLonga d;
    std::stringstream ss;
    d.toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, DurLonga )
{
    DurLonga d;
    std::stringstream ss;
    ss << d;
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, DurLonga )
{
    DurLonga d;
    CHECK_EQUAL( name, d.toString() )
}
