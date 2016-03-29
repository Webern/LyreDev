//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IMusicFactoryFactory.h"
#include "Lyre/IMusicFactory.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IMusicFactoryFactoryUP factory =
	createMusicFactoryFactory();
}

TEST( toStream, MusicFactory )
{
    IMusicFactoryUP ts = factory->create();
    std::stringstream ss;
    ts->toStream( ss );
    String expected = "MusicFactory not implemented";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
