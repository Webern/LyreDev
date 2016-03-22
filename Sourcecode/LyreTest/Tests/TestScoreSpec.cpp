//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IScoreSpecFactory.h"
#include "Lyre/IScoreSpec.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IScoreSpecFactoryUP factory =
	createScoreSpecFactory();
}

TEST( toStream, ScoreSpec )
{
    IScoreSpecUP ts = factory->create();
    std::stringstream ss;
    ts->toStream( ss );
    String expected = "ScoreSpec not implemented";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
