//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IBeatPattern.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IBeatPatternFactoryUP factory =
	createBeatPatternFactory();
}

TEST( TODO, BeatPattern )
{
    IBeatPatternUP ts = factory->create( 4, 4 );
    String expected = "write more tests";
    String actual = ts->toString();
    CHECK_EQUAL( expected, actual )
}
