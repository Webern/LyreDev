//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IPartFactory.h"
#include "Lyre/IPart.h"
#include "Lyre/IInstrumentFactory.h"
#include "Lyre/IRangeFactory.h"
#include "Lyre/IMasterTrackFactory.h"
#include "Lyre/ITimeSignatureFactory.h"

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
        ITimeSignatureFactoryUPC timeSignatureFactory;
        
        InstrumentName name1;
        IRangeUPC range1;
        IInstrumentUPC instrument1;
        
        Factories()
        :partFactory( createPartFactory() )
        ,instrumentFactory( createInstrumentFactory() )
        ,rangeFactory( createRangeFactory() )
        ,masterTrackFactory( createMasterTrackFactory() )
        ,timeSignatureFactory( createTimeSignatureFactory() )
        ,name1( "Instrument 1", "Instr 1" )
        ,range1( rangeFactory->create( "A2", "C7" ) )
        ,instrument1( instrumentFactory->create( name1, range1->clone() ) )
        {}
    };
}

TEST( ctorWorks, Part )
{
    Factories f;
	MasterTrackParams params;
	params.measureCount = 10;
    params.timeTrack[0] = f.timeSignatureFactory->create( 4, 4 );
    params.timeTrack[5] = f.timeSignatureFactory->create( 7, 8 );
    IMasterTrackSPC masterTrack = f.masterTrackFactory->create( std::move( params ) );
	auto i = f.instrument1->clone();
    IPartUP part = f.partFactory->create( 1, std::move( i ), masterTrack );
    CHECK( part != nullptr )
}
T_END


TEST( ax, Part )
{
	Factories f;
	MasterTrackParams params;
	params.measureCount = 10;
	params.timeTrack[0] = f.timeSignatureFactory->create( 4, 4 );
	params.timeTrack[5] = f.timeSignatureFactory->create( 7, 8 );
	IMasterTrackSPC masterTrack = f.masterTrackFactory->create( std::move( params ) );
	auto i = f.instrument1->clone();
	IPartUP part = f.partFactory->create( 1, std::move( i ), masterTrack );
	CHECK( part != nullptr )
}
T_END
