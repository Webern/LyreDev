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
    struct Factories
    {
    public:
        IPartFactoryUPC partFactory;
        IInstrumentFactoryUPC instrumentFactory;
        IRangeFactoryUPC rangeFactory;
        
        InstrumentName name1;
        IRangeUPC range1;
        IInstrumentUPC instrument1;
        
        Factories()
        :partFactory( createPartFactory() )
        ,instrumentFactory( createInstrumentFactory() )
        ,rangeFactory( createRangeFactory() )
        ,name1( "Instrument 1", "Instr 1" )
        ,range1( rangeFactory->create( "A2", "C7" ) )
        ,instrument1( instrumentFactory->create( name1, range1->clone() ) )
        {}
    };
}

TEST( toStream, Part )
{
    Factories f;
    IPartUP part = f.partFactory->create( 1, f.instrument1->clone() );
    std::stringstream ss;
    part->toStream( ss );
    String expected = "//////////   Instrument 1   //////////";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
