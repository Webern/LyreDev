#include "TestHarness.h"
#include "Duration.h"

using namespace music;

TEST( Constructor01, Duration )
{
    Duration d;
    CHECK_EQUAL( Rational( 1, 1 ), d.getRational() )
    CHECK( d.getDurationBase().getDurationName() == DurationName::Quarter )
    CHECK_EQUAL( d.getDotCount(), 0 )
    auto t = d.getTupletRatio();
    CHECK_EQUAL( Rational( 1, 1 ), t.getRational() )
}
TEST( Constructor02, Duration )
{
    Duration d{ DurationBase{ DurationName::Half } };
    CHECK_EQUAL( Rational( 2, 1 ), d.getRational() )
    CHECK( d.getDurationBase().getDurationName() == DurationName::Half )
    CHECK_EQUAL( d.getDotCount(), 0 )
    auto t = d.getTupletRatio();
    CHECK_EQUAL( Rational( 1, 1 ), t.getRational() )
}
TEST( Constructor03, Duration )
{
    Duration d{ DurationBase{ DurationName::Eighth }, 1 };
    CHECK_EQUAL( Rational( 3, 4 ), d.getRational() )
    CHECK( d.getDurationBase().getDurationName() == DurationName::Eighth )
    CHECK_EQUAL( d.getDotCount(), 1 )
    auto t = d.getTupletRatio();
    CHECK_EQUAL( Rational( 1, 1 ), t.getRational() )
}
TEST( Constructor04, Duration )
{
    DurationCount two( DurationBase( DurationName::Eighth ), 2 );
    DurationCount thr( DurationBase( DurationName::Eighth ), 3 );
    
    TupletRatio triplet( thr, two );
    
    Duration d{ DurationBase{ DurationName::Eighth }, 0, triplet };
    CHECK_EQUAL( Rational( 1, 3 ), d.getRational() )
    CHECK( d.getDurationBase().getDurationName() == DurationName::Eighth )
    CHECK_EQUAL( d.getDotCount(), 0 )
    auto t = d.getTupletRatio();
    CHECK_EQUAL( Rational( 3, 2 ), t.getRational() )
}
TEST( Constructor05, Duration )
{
    DurationCount sevn( DurationBase( DurationName::Sixteenth ), 7 );
    DurationCount four( DurationBase( DurationName::Sixteenth ), 4 );
    TupletRatio septuplet( sevn, four );
    Duration d{ DurationBase{ DurationName::Sixteenth }, 0, septuplet };
    CHECK_EQUAL( Rational( 1, 7 ), d.getRational() )
    CHECK( d.getDurationBase().getDurationName() == DurationName::Sixteenth )
    CHECK_EQUAL( d.getDotCount(), 0 )
    auto t = d.getTupletRatio();
    CHECK_EQUAL( Rational( 7, 4 ), t.getRational() )
}
TEST( Constructor06, Duration )
{
    DurationCount five( DurationBase( DurationName::Quarter ), 5 );
    DurationCount four( DurationBase( DurationName::Quarter ), 4 );
    TupletRatio quint( five, four );
    Duration d{ DurationBase{ DurationName::Quarter }, 0, quint };
    CHECK_EQUAL( Rational( 4, 5 ), d.getRational() )
    CHECK( d.getDurationBase().getDurationName() == DurationName::Quarter )
    CHECK_EQUAL( d.getDotCount(), 0 )
    auto t = d.getTupletRatio();
    CHECK_EQUAL( Rational( 5, 4 ), t.getRational() )
}

TEST( Constructor07, Duration )
{
    DurationCount five( DurationBase( DurationName::Quarter ), 5 );
    DurationCount four( DurationBase( DurationName::Quarter ), 4 );
    TupletRatio quint( five, four );
    Duration d{ DurationBase{ DurationName::Quarter }, 5, quint };
    CHECK_EQUAL( Rational( 243, 40 ), d.getRational() )
    CHECK( d.getDurationBase().getDurationName() == DurationName::Quarter )
    CHECK_EQUAL( d.getDotCount(), 5 )
    auto t = d.getTupletRatio();
    CHECK_EQUAL( Rational( 5, 4 ), t.getRational() )
}

TEST( Constructor08, Duration )
{
    DurationCount thr( DurationBase( DurationName::Eighth ), 3 );
    DurationCount two( DurationBase( DurationName::Eighth ), 2 );
    TupletRatio duple( two, thr );
    Duration d{ DurationBase{ DurationName::Eighth }, duple };
    CHECK_EQUAL( Rational( 3, 4 ), d.getRational() )
    CHECK( d.getDurationBase().getDurationName() == DurationName::Eighth )
    CHECK_EQUAL( d.getDotCount(), 0 )
    auto t = d.getTupletRatio();
    CHECK_EQUAL( Rational( 3, 2 ), t.getRational() )
}