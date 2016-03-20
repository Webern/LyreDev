//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IPartFactory.h"
#include "Lyre/IPart.h"
#include "Lyre/IInstrumentFactory.h"
#include "Lyre/IRangeFactory.h"
#include "Lyre/IMasterTrackFactory.h"
#include "Lyre/ITimeSignatureFactory.h"
#include "Lyre/IPitchFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/INoteFactory.h"

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
		IPitchFactoryUP pitchFactory;
		IDurationFactoryUPC durationFactory;
		INoteFactoryUPC noteFactory;

        InstrumentName name1;
        IRangeUPC range1;
        IInstrumentUPC instrument1;
        
		INoteUP createNote( std::string pitchName, std::string durName ) const
		{
			auto p = pitchFactory->createPitch( pitchName );
			auto d = durationFactory->createDuration( durName );
			return noteFactory->createNote( p, d );
		}

        Factories()
        : partFactory( createPartFactory() )
        , instrumentFactory( createInstrumentFactory() )
        , rangeFactory( createRangeFactory() )
        , masterTrackFactory( createMasterTrackFactory() )
        , timeSignatureFactory( createTimeSignatureFactory() )
        , pitchFactory( createPitchFactory() )
		, durationFactory( createDurationFactory() )
		, noteFactory( createNoteFactory() )
		, name1( "Instrument 1", "Instr 1" )
        , range1( rangeFactory->create( "A2", "C7" ) )
        , instrument1( instrumentFactory->create( name1, range1->clone() ) )

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


TEST( staffContextGetSet, Part )
{
	Factories f;
	MasterTrackParams params;
	params.measureCount = 10;
	params.timeTrack[0] = f.timeSignatureFactory->create( 4, 4 );
	params.timeTrack[5] = f.timeSignatureFactory->create( 7, 8 );
	IMasterTrackSPC masterTrack = f.masterTrackFactory->create( std::move( params ) );
	IPartUP part = f.partFactory->create( 3, f.instrument1->clone(), masterTrack );
	part->setStaffContext( 1 );
    CHECK_EQUAL( 1, part->getStaffContext() )
}
T_END


TEST( staffContextThrowOutOfRangeHigh, Part )
{
	Factories f;
	MasterTrackParams params;
	params.measureCount = 10;
	params.timeTrack[0] = f.timeSignatureFactory->create( 4, 4 );
	params.timeTrack[5] = f.timeSignatureFactory->create( 7, 8 );
	IMasterTrackSPC masterTrack = f.masterTrackFactory->create( std::move( params ) );
	IPartUP part = f.partFactory->create( 3, f.instrument1->clone(), masterTrack );
	bool isExceptionThrown = false;
    part->setStaffContext( 2 );
    try
    {
        part->setStaffContext( 3 );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
    CHECK_EQUAL( 2, part->getStaffContext() )
}
T_END


TEST( staffContextThrowOutOfRangeLow, Part )
{
	Factories f;
	MasterTrackParams params;
	params.measureCount = 10;
	params.timeTrack[0] = f.timeSignatureFactory->create( 4, 4 );
	params.timeTrack[5] = f.timeSignatureFactory->create( 7, 8 );
	IMasterTrackSPC masterTrack = f.masterTrackFactory->create( std::move( params ) );
	IPartUP part = f.partFactory->create( 3, f.instrument1->clone(), masterTrack );
	bool isExceptionThrown = false;
    part->setStaffContext( 2 );
    try
    {
        part->setStaffContext( -1 );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
    CHECK_EQUAL( 2, part->getStaffContext() )
}
T_END


TEST( getMeasureCount, Part )
{
	Factories f;
	MasterTrackParams params;
	params.measureCount = 1;
	params.timeTrack[0] = f.timeSignatureFactory->create( 4, 4 );
	IMasterTrackSPC masterTrack = f.masterTrackFactory->create( std::move( params ) );
	IPartUP part = f.partFactory->create( 3, f.instrument1->clone(), masterTrack );
    CHECK_EQUAL( 1, part->getMeasureCount() )
}
T_END


TEST( getMeasureNonCost, Part )
{
	Factories f;
	MasterTrackParams params;
	params.measureCount = 10;
	params.timeTrack[0] = f.timeSignatureFactory->create( 4, 4 );
	params.timeTrack[5] = f.timeSignatureFactory->create( 7, 8 );
	IMasterTrackSPC masterTrack = f.masterTrackFactory->create( std::move( params ) );
	IPartUP part = f.partFactory->create( 3, f.instrument1->clone(), masterTrack );
	part->setStaffContext( 2 );
	auto measure = part->getMeasure( 5 );
	measure->addNote( f.createNote( "C4", "Half" ) );
	int expected = 1;
	int actual = part->getMeasure( 5 )->getCount();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( getMeasureConst, Part )
{
	Factories f;
	MasterTrackParams params;
	params.measureCount = 10;
	params.timeTrack[0] = f.timeSignatureFactory->create( 4, 4 );
	params.timeTrack[5] = f.timeSignatureFactory->create( 7, 8 );
	IMasterTrackSPC masterTrack = f.masterTrackFactory->create( std::move( params ) );
	IPartUP part = f.partFactory->create( 3, f.instrument1->clone(), masterTrack );
	part->setStaffContext( 1 );
    auto measure = part->getMeasureConst( 3 );
    CHECK_EQUAL( Rational(4,1), measure->getUnusedRemaining() )
}
T_END