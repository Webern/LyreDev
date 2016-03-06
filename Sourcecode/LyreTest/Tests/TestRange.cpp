//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IRangeFactory.h"
#include "Lyre/IRange.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IRangeFactoryUP factory =
	createRangeFactory();
}

TEST( toStream, Range )
{
    IRangeUP ts = factory->create();
    std::stringstream ss;
    ts->toStream( ss );
    String expected = "Range not implemented";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
