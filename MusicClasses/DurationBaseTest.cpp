#include "TestHarness.h"
#include "DurationBase.h"

using namespace music;

TEST( Constructor01, DurationBase )
{
    DurationBase db;
    CHECK( DurationName::Quarter == db.getDurationName() )
}
TEST( Constructor02, DurationBase )
{
    DurationBase db{ DurationName::Quarter };
    CHECK( DurationName::Quarter == db.getDurationName() )
}
TEST( Constructor03, DurationBase )
{
    DurationBase db{ DurationName::Longa };
    CHECK( DurationName::Longa == db.getDurationName() )
}

TEST( getRational01, DurationBase )
{
    DurationBase db{ DurationName::Eighth };
    db.setDurationName( DurationName::ThirtySecond );
    CHECK_EQUAL( Rational( 1, 8 ), db.getRational() )
}
TEST( getRational02, DurationBase )
{
    DurationBase db{ DurationName::Longa };
    db.setDurationName( DurationName::Whole );
    CHECK_EQUAL( Rational( 4,1 ), db.getRational() )
}
TEST( getRational03, DurationBase )
{
    DurationBase db{ DurationName::OneTwentyEighth };
    db.setDurationName( DurationName::SixtyFourth );
    CHECK_EQUAL( Rational( 1, 16 ), db.getRational() )
}