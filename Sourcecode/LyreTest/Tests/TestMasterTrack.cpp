//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IMasterTrackFactory.h"
#include "Lyre/IMasterTrack.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IMasterTrackFactoryUP factory =
	createMasterTrackFactory();
}

TEST( toStream, MasterTrack )
{
    IMasterTrackUP ts = factory->create();
    std::stringstream ss;
    ts->toStream( ss );
    String expected = "MasterTrack not implemented";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
