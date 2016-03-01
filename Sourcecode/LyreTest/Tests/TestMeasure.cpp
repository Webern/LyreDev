//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IMeasureFactory.h"
#include "Lyre/IMeasure.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IMeasureFactoryUP factory =
	createMeasureFactory();
}

TEST( toStream, Measure )
{
    IMeasureUP ts = factory->create();
    std::stringstream ss;
    ts->toStream( ss );
    String expected = "Measure not implemented";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
