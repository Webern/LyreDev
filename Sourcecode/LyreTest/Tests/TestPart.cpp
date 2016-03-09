//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IPartFactory.h"
#include "Lyre/IPart.h"
#include "Lyre/IInstrumentFactory.h"
#include "Lyre/IRangeFactory.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IPartFactoryUPC factory =
	createPartFactory();

    static IInstrumentFactoryUPC instrumentFactory =
        createInstrumentFactory();

    static IRangeFactoryUPC rangeFactory =
        createRangeFactory();

    static const InstrumentName name1 = { "Instrument 1", "Inst. 1" };
    static const IRangeUPC range1 = rangeFactory->create( "C3", "C7" );
    static const IInstrumentUPC instrument1 = instrumentFactory->create( name1, range1->clone() );
}

TEST( toStream, Part )
{
    IPartUP ts = factory->create( 1, 2, instrument1->clone() );
    std::stringstream ss;
    ts->toStream( ss );
    String expected = "Part not implemented";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
