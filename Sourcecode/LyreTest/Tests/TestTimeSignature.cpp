//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/ITimeSignatureFactory.h"
#include "Lyre/ITimeSignature.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IBeatPattern.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static ITimeSignatureFactoryUP factory =
	createTimeSignatureFactory();
}

TEST( toStream, TimeSignature )
{
    ITimeSignatureUP ts = factory->create( 7, 16 );
    std::stringstream ss;
    ts->toStream( ss );
    String expected = "TimeSignature[7/16(BeatPattern<Quarter,Eighth,16th>)]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getBeatPattern, TimeSignature )
{
    auto beatPatternFactory = createBeatPatternFactory();
    auto durationFactory = createDurationFactory( DurationFactoryType::Standard );
    IBeatPatternUP beatPattern = beatPatternFactory->create( 2, durationFactory->createDuration( STR_QUARTER, 1 ) );
    ITimeSignatureUP ts = factory->create( std::move( beatPattern ), 3, 4 );
    String expected = "TimeSignature[3/4(BeatPattern<Quarter.,Quarter.>)]";
    String actual = ts->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTop, TimeSignature )
{
    auto beatPatternFactory = createBeatPatternFactory();
    auto durationFactory = createDurationFactory( DurationFactoryType::Standard );
    ITimeSignatureUP ts = factory->create( 3, 4 );
    int expected = 3;
    int actual = ts->getTop();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getBottom, TimeSignature )
{
    auto beatPatternFactory = createBeatPatternFactory();
    auto durationFactory = createDurationFactory( DurationFactoryType::Standard );
    ITimeSignatureUP ts = factory->create( 37, 8 );
    int expected = 8;
    int actual = ts->getBottom();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalDuration01, TimeSignature )
{
    ITimeSignatureUP ts = factory->create( 9, 8 );
    Rational expected{ 9, 2 };
    Rational actual = ts->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalDuration02, TimeSignature )
{
    auto beatPatternFactory = createBeatPatternFactory();
    auto durationFactory = createDurationFactory( DurationFactoryType::Standard );
    ITimeSignatureUP ts = factory->create( 13, 8 );
    Rational expected{ 13, 2 };
    Rational actual = ts->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END
