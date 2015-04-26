#include "TestHarness.h"
#include "Definitions.h"
#include "RangeInt.h"

using namespace music;

TEST( Test01, Range )
{
    RangeInt<Integer, 5, 10> r;
    CHECK_EQUAL( 5, r.getValue() );
}
TEST( Test02, Range )
{
    RangeInt<Integer, 5, 10> r{ 11 };
    CHECK_EQUAL( 10, r.getValue() );
}
TEST( Test03, Range )
{
    RangeInt<Integer, -10, 10> r;
    CHECK_EQUAL( 0, r.getValue() );
}
TEST( Test04, Range )
{
    RangeInt<Integer, -10, 10> r{ 9 };
    r.add( 2 );
    CHECK_EQUAL( 10, r.getValue() );
}
TEST( Test05, Range )
{
    RangeInt<Integer, -10, 10> r{ -9 };
    r.add( -2 );
    CHECK_EQUAL( -10, r.getValue() );
}
TEST( Test06, Range )
{
    RangeInt<Integer, -10, 10> r{ 9 };
    r.subtract( 2 );
    CHECK_EQUAL( 7, r.getValue() );
}
TEST( Test07, Range )
{
    RangeInt<Integer, -10, 10> r{ -9 };
    r.subtract( -2 );
    CHECK_EQUAL( -7, r.getValue() );
}
TEST( Test08, Range )
{
    RangeInt<Integer, -10, 10> r{ 1 };
    r.add( 2 ).add( 2 );
    CHECK_EQUAL( 5, r.getValue() );
}
TEST( Test09, Range )
{
    RangeInt<Integer, -10, 10> r{ 1 };
    r.subtract( 2 ).subtract( 2 );
    CHECK_EQUAL( -3, r.getValue() );
}