#include "cpulTestHarness.h"
#include "Mod.h"
#include "TypeDefs.h"

using namespace lyre;

TEST( Constructor01, Mod)
{
    Mod<Integer, 10> m;
	CHECK_EQUAL( 0 , m.getValue() );
}
TEST( Constructor02, Mod)
{
    Mod<long long, 1000000> m{ 500000 };
	CHECK_EQUAL( 500000 , m.getValue() );
}
TEST( Constructor03, Mod)
{
    Mod<char, 13> m{ 13 };
	CHECK_EQUAL( 0 , m.getValue() );
}
TEST( Constructor04, Mod)
{
    Mod<short, 76> m{ 103 };
	CHECK_EQUAL( 27 , m.getValue() );
}
TEST( Constructor05, Mod)
{
    Mod<short, 30> m{ -1 };
	CHECK_EQUAL( 29 , m.getValue() );
}
TEST( Constructor06, Mod)
{
    Mod<short, 31> m{ -31 };
	CHECK_EQUAL( 0 , m.getValue() );
}
TEST( Constructor07, Mod)
{
    Mod<short, 32> m{ -66 };
	CHECK_EQUAL( 30 , m.getValue() );
}
TEST( SetValue01, Mod)
{
    Mod<short, 32> m{ -66 };
    m.setValue( 99 );
	CHECK_EQUAL( 3 , m.getValue() );
}
TEST( SetValue02, Mod)
{
    Mod<short, 13> m{ -1 };
    m.setValue( -2 );
	CHECK_EQUAL( 11 , m.getValue() );
}
TEST( SetValue03, Mod)
{
    Mod<short, 5> m{ -4 };
    m.setValue( 5 );
	CHECK_EQUAL( 0 , m.getValue() );
}
TEST( SetValue04, Mod)
{
    Mod<short, 15> m{ 3 };
    m.setValue( 14 );
	CHECK_EQUAL( 14 , m.getValue() );
}
TEST( add01, Mod)
{
    Mod<short, 15> m{ 3 };
    m.add( 5 );
	CHECK_EQUAL( 8 , m.getValue() );
}
TEST( add02, Mod)
{
    Mod<Integer, 12> m{ 3 };
    m.add( -4 );
	CHECK_EQUAL( 11 , m.getValue() );
}
TEST( add03, Mod)
{
    Mod<Integer, 12> m{ 12 };
    m.add( 13 );
	CHECK_EQUAL( 1 , m.getValue() );
}
TEST( subtract01, Mod)
{
    Mod<Integer, 12> m{ 12 };
    m.subtract( 5 );
	CHECK_EQUAL( 7 , m.getValue() );
}
TEST( subtract02, Mod)
{
    Mod<Integer, 100> m{ 12 };
    m.subtract( -10 );
	CHECK_EQUAL( 22 , m.getValue() );
}
TEST( subtract03, Mod)
{
    Mod<long long, 100> m{ 12 };
    m.subtract( 30 );
	CHECK_EQUAL( 82 , m.getValue() );
}
TEST( subtract04, Mod)
{
    Mod<long long, 100> m{ 90 };
    m.subtract( -10 );
	CHECK_EQUAL( 0 , m.getValue() );
}
TEST( plusPlus01, Mod)
{
    Mod<long long, 100> m{ 98 };
	CHECK_EQUAL( 98 , m.getValue() );
    auto returned = (++m).getValue();
    CHECK_EQUAL( 99, returned );
    CHECK_EQUAL( 99, m.getValue() );
    returned = (++m).getValue();
    CHECK_EQUAL( 0, returned );
    CHECK_EQUAL( 0, m.getValue() );
    returned = (++m).getValue();
    CHECK_EQUAL( 1, returned );
    CHECK_EQUAL( 1, m.getValue() );
}
TEST( plusPlus02, Mod)
{
    Mod<unsigned char, 100> m{ 98 };
	CHECK_EQUAL( 98 , m.getValue() );
    auto returned = (m++).getValue();
    CHECK_EQUAL( 98, returned );
    CHECK_EQUAL( 99, m.getValue() );
    returned = (m++).getValue();
    CHECK_EQUAL( 99, returned );
    CHECK_EQUAL( 0, m.getValue() );
    returned = (m++).getValue();
    CHECK_EQUAL( 0, returned );
    CHECK_EQUAL( 1, m.getValue() );
}
TEST( minusMinus01, Mod)
{
    Mod<int_fast16_t, 100> m{ 2 };
	CHECK_EQUAL( 2 , m.getValue() );
    long long returned = (--m).getValue();
    CHECK_EQUAL( 1, returned );
    CHECK_EQUAL( 1, m.getValue() );
    returned = (--m).getValue();
    CHECK_EQUAL( 0, returned );
    CHECK_EQUAL( 0, m.getValue() );
    returned = (--m).getValue();
    CHECK_EQUAL( 99, returned );
    CHECK_EQUAL( 99, m.getValue() );
}
TEST( minusMinus02, Mod)
{
    Mod<int_fast64_t, 100> m{ 2 };
	CHECK_EQUAL( 2 , m.getValue() );
    long long returned = (m--).getValue();
    CHECK_EQUAL( 2, returned );
    CHECK_EQUAL( 1, m.getValue() );
    returned = (m--).getValue();
    CHECK_EQUAL( 1, returned );
    CHECK_EQUAL( 0, m.getValue() );
    returned = (m--).getValue();
    CHECK_EQUAL( 0, returned );
    CHECK_EQUAL( 99, m.getValue() );
}
TEST( comparisons01_LgreaterThanR, Mod)
{
    Mod<long long int, 100> l{ 3 };
    Mod<long long int, 100> r{ 2 };
    CHECK( ! ( l == r ) )
    CHECK(   ( l != r ) )
    CHECK(   ( l >  r ) )
    CHECK( ! ( l <  r ) )
    CHECK(   ( l >= r ) )
    CHECK( ! ( l <= r ) )
}
TEST( comparisons01_LequalsR, Mod)
{
    Mod<long long int, 77> l{ 3 };
    Mod<long long int, 77> r{ 80 };
    CHECK(   ( l == r ) )
    CHECK( ! ( l != r ) )
    CHECK( ! ( l >  r ) )
    CHECK( ! ( l <  r ) )
    CHECK(   ( l >= r ) )
    CHECK(   ( l <= r ) )
}
TEST( comparisons01_LlessThanR, Mod)
{
    Mod<long long int, 77> l{ 2 };
    Mod<long long int, 77> r{ 3 };
    CHECK( ! ( l == r ) )
    CHECK(   ( l != r ) )
    CHECK( ! ( l >  r ) )
    CHECK(   ( l <  r ) )
    CHECK( ! ( l >= r ) )
    CHECK(   ( l <= r ) )
}