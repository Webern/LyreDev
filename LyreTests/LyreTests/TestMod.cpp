#include "cpulTestHarness.h"
#include "Mod.h"
#include "TypeDefs.h"

using namespace lyre;
using namespace lyre::p;

TEST( Constructor01, Nod)
{
    Mod<Integer, 10> m;
	CHECK_EQUAL( 0 , m.getValue() );
}
TEST( Constructor02, Nod)
{
    Mod<long long, 1000000> m{ 500000 };
	CHECK_EQUAL( 500000 , m.getValue() );
}
TEST( Constructor03, Nod)
{
    Mod<char, 13> m{ 13 };
	CHECK_EQUAL( 0 , m.getValue() );
}
TEST( Constructor04, Nod)
{
    Mod<short, 76> m{ 103 };
	CHECK_EQUAL( 27 , m.getValue() );
}
