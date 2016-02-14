//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/ITimeSignatureFactory.h"
#include "Lyre/ITimeSignature.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static ITimeSignatureFactoryUP factory =
	createTimeSignatureFactory();
}

TEST( TODO, TimeSignature )
{
    ITimeSignatureUP ts = factory->create( 7, 16 );
    std::cout << *ts << std::endl;
    String expected = "write more tests";
    String actual = ts->toString();
    CHECK_EQUAL( expected, actual )
}