//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/ILayerFactory.h"
#include "Lyre/ILayer.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static ILayerFactoryUP factory =
	createLayerFactory();
}

TEST( toStream, Layer )
{
    ILayerUP ts = factory->create();
    std::stringstream ss;
    ts->toStream( ss );
    String expected = "";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
