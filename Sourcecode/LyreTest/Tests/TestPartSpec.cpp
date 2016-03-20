//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IPartSpecFactory.h"
#include "Lyre/IPartSpec.h"
#include "Lyre/IInstrumentFactory.h"
#include "lyre/IRangeFactory.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	struct Factories
    {
        IPartSpecFactoryUPC partSpecFactory;
        IInstrumentFactoryUPC instrumentFactory;
        IRangeFactoryUPC rangeFactory;
        
        Factories()
        : partSpecFactory( createPartSpecFactory() )
        , instrumentFactory( createInstrumentFactory() )
        , rangeFactory( createRangeFactory() )
        {}
        
    };
}

TEST( toStream, PartSpec )
{
    Factories f;
    auto r = f.rangeFactory->create( "C#1", "Fb2" );
    InstrumentName name;
    name.Name = "Crazy Trumpet";
    name.ShortName = "Cr. Trp";
    auto i = f.instrumentFactory->create( name, r );
    auto ps = f.partSpecFactory->create( i );
    ps->setName( "Crazy Trumpet Part" );
    ps->setUniqueId( "CRTRP1" );
    std::stringstream ss;
    ps->toStream( ss );
    String expected = "{ Crazy Trumpet Part: CRTRP1: Crazy Trumpet }";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
