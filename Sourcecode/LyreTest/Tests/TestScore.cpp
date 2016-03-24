//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IScoreFactory.h"
#include "Lyre/IScore.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IScoreFactoryUP factory =
	createScoreFactory();
}

TEST( toStream, Score )
{
    IScoreUP ts = factory->create();
    std::stringstream ss;
    ts->toStream( ss );
    String expected = "Score not implemented";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
