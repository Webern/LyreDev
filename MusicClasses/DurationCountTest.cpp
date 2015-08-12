#include "TestHarness.h"
#include "DurationCount.h"

using namespace music;

TEST( Constructor01, DucationCount )
{
    DurationCount x;
    CHECK_EQUAL( x.getCount(), 1 )
    CHECK( x.getDurationBase().getDurationName() == DurationName::Quarter )
    CHECK( x.getDurationBase().getRational().getNumerator() == 1 )
    CHECK( x.getDurationBase().getRational().getDenominator() == 1 )
}
TEST( Constructor02, DucationCount )
{
    DurationBase base;
    base.setDurationName( DurationName::Half );
    DurationCount x{ base, 3 };
    CHECK_EQUAL( x.getCount(), 3 )
    CHECK( x.getDurationBase().getDurationName() == DurationName::Half )
    CHECK( x.getDurationBase().getRational().getNumerator() == 2 )
    CHECK( x.getDurationBase().getRational().getDenominator() == 1 )
}
TEST( Set01, DucationCount )
{
    DurationBase base;
    base.setDurationName( DurationName::ThirtySecond );
    DurationCount x{ base, 10 };
    x.setDurationBase( DurationBase{ DurationName::Sixteenth } );
    x.setCount( 2 );
    CHECK_EQUAL( 2, x.getCount() )
    CHECK( x.getDurationBase().getDurationName() == DurationName::Sixteenth )
    CHECK( x.getDurationBase().getRational().getNumerator() == 1 )
    CHECK( x.getDurationBase().getRational().getDenominator() == 4 )
}