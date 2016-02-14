//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/ITimeSignatureFactory.h"
#include "Lyre/ITimeSignature.h"
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

TEST( getTotalDuration, TimeSignature )
{
    ITimeSignatureUP ts = factory->create( 9, 8 );
    Rational expected{ 9, 2 };
    Rational actual = ts->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}