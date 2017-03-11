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
    String name = "Crazy Trumpet";
    String shortName = "Cr. Trp";
    auto i = f.instrumentFactory->create( name, shortName, r );
    auto ps = f.partSpecFactory->create( 3, i );
    ps->setName( "Crazy Trumpet 1" );
    ps->autoGenerateUniqueIdFromName();
    std::stringstream ss;
    ps->toStream( ss );
    //{ Crazy Trumpet 1: CRAZY_TRUMPET_1_100008: Crazy Trumpet }
    String expected = "{ Crazy Trumpet 1: CRAZY_TRUMPET_1_100008: Crazy Trumpet }";
    String actual = ss.str();
    CHECK_EQUAL( expected.substr( 0, 34), actual.substr( 0, 34 ) )
    CHECK_EQUAL( expected.substr( expected.size() - 17 ), actual.substr( actual.size() - 17 ) )
}
T_END
