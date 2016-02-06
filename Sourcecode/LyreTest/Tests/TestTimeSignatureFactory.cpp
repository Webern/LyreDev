//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/ITimeSignatureFactory.h"

using namespace Lyre;
using namespace std;

namespace
{
	static ITimeSignatureFactoryUP factory =
	createTimeSignatureFactory();
}

TEST( TODO, TimeSignatureFactory )
{
    ITimeSignatureUP ts = factory->create( 4, 4 );
    CHECK( ts )
    String expected = "write more tests";
    String actual = ts->toString();
    CHECK_EQUAL( expected, actual )
}
