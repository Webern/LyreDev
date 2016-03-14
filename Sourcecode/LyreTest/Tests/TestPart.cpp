//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IPartFactory.h"
#include "Lyre/IPart.h"
#include "Lyre/IInstrumentFactory.h"
#include "Lyre/IRangeFactory.h"
#include "Lyre/IMasterTrackFactory.h"

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
        IMasterTrackFactoryUPC masterTrackFactory;
        
        InstrumentName name1;
        IRangeUPC range1;
        IInstrumentUPC instrument1;
        
        Factories()
        :partFactory( createPartFactory() )
        ,instrumentFactory( createInstrumentFactory() )
        ,rangeFactory( createRangeFactory() )
        ,masterTrackFactory( createMasterTrackFactory() )
        ,name1( "Instrument 1", "Instr 1" )
        ,range1( rangeFactory->create( "A2", "C7" ) )
        ,instrument1( instrumentFactory->create( name1, range1->clone() ) )
        {}
    };
}

TEST( abortProblemOnVisualStudio, Part )
{

    Factories f;

	MasterTrackParams params;
	params.measureCount = 10;
    IMasterTrackSPC masterTrack = f.masterTrackFactory->create( std::move( params ) );
	auto i = f.instrument1->clone();
    IPartUP part = f.partFactory->create( 1, std::move( i ), masterTrack );

}
T_END
