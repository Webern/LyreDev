//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IMovementFactory.h"
#include "Lyre/IMovement.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IMovementFactoryUP factory =
	createMovementFactory();
}

TEST( toStream, Movement )
{
    IMovementUP ts = factory->create();
    std::stringstream ss;
    ts->toStream( ss );
    String expected = "Movement not implemented";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
