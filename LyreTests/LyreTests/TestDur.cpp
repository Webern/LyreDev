#include "cpulTestHarness.h"
#include "Dur.h"

using namespace lyre;

TEST( Compiles, Dur )
{
    Dur d = Dur::Quarter;
    CHECK( d == Dur::Quarter )
}
TEST( reminder, Dur )
{
    Dur d = Dur::Quarter;
    CHECK_EQUAL( "write tests for the Dur enum and functions", "" )
}
