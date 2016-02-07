//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IBeatPatternFactory.h"

using namespace Lyre;
using namespace std;

namespace
{
	static IBeatPatternFactoryUP factory =
	createBeatPatternFactory();
}

TEST( TODO, BeatPatternFactory )
{
    //IBeatPatternUP ts = factory->create( 4, 4 );
    //CHECK( ts )
    String expected = "write more tests";
    String actual = "";//ts->toString();
    CHECK_EQUAL( expected, actual )
}
