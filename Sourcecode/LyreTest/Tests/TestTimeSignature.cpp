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

TEST( getTotalDuration, TimeSignature )
{
    ITimeSignatureUP ts = factory->create( 9, 8 );
    Rational expected{ 9, 2 };
    Rational actual = ts->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getBeatPattern, TimeSignature )
{
    auto beatPatternFactory = createBeatPatternFactory();
    auto durationFactory = createDurationFactory( DurationFactoryType::Standard );
    IBeatPatternUP beatPattern = beatPatternFactory->create( 2, durationFactory->createDuration( "Quarter", 1 ) );
    ITimeSignatureUP ts = factory->create( std::move( beatPattern ), 6, 4 );
    String expected = "";
    String actual = ".";// = ts->getBeatPattern()->toString();
    CHECK_EQUAL( expected, actual )
}
T_END