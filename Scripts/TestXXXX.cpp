//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IXXXXFactory.h"
#include "Lyre/IXXXX.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IXXXXFactoryUP factory =
	createXXXXFactory();
}

TEST( toStream, XXXX )
{
    IXXXXUP ts = factory->create();
    std::stringstream ss;
    ts->toStream( ss );
    String expected = "XXXX not implemented";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
