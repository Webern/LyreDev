#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IMovementFactory.h"
#include "Lyre/IMovement.h"
#include "Lyre/IPartSpecFactory.h"
#include "Lyre/IPartFactory.h"
#include "Lyre/IPart.h"
#include "Lyre/IInstrumentFactory.h"
#include "Lyre/IRangeFactory.h"
#include "Lyre/IMasterTrackFactory.h"
#include "Lyre/ITimeSignatureFactory.h"
#include "Lyre/IPitchFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/INoteFactory.h"
#include "Lyre/IMovementSpecFactory.h"

#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	struct Factories
    {
    public:
        IMovementSpecFactoryUPC movementSpecFactory;
        IMovementFactoryUPC movementFactory;
        IPartFactoryUPC partFactory;
        IInstrumentFactoryUPC instrumentFactory;
        IRangeFactoryUPC rangeFactory;
        IMasterTrackFactoryUPC masterTrackFactory;
        ITimeSignatureFactoryUPC timeSignatureFactory;
		IPitchFactoryUP pitchFactory;
		IDurationFactoryUPC durationFactory;
		INoteFactoryUPC noteFactory;
        IPartSpecFactoryUPC partSpecFactory;
        
        String name1;
        String shortName1;
        
        IRangeUPC range1;
        IInstrumentUPC instrument1;
        
		INoteUP createNote( std::string pitchName, std::string durName ) const
		{
			auto p = pitchFactory->createPitch( pitchName );
			auto d = durationFactory->createDuration( durName );
			return noteFactory->createNote( p, d );
		}
        
        IInstrumentUP createInstrument(
            const String& name,
            const String& shortName,
            const String& low,
            const String& high ) const
        {
            auto range = rangeFactory->create( low, high );
            return std::move( instrumentFactory->create( name, shortName, range ) );
        }
        
        VecIPartSpecUP createPartSpecs() const
        {
            VecIPartSpecUP parts;
			auto p1 = partSpecFactory->create( 1, this->createInstrument( "Flute 1", "Fl 1", "C4", "C7" ) );
			p1->setUniqueId( "FLUTE_1" );
            parts.push_back( std::move( p1 ) );
			auto p2 = partSpecFactory->create( 1, this->createInstrument( "Flute 2", "Fl 2", "C4", "C7" ) );
			p2->setUniqueId( "FLUTE_2" );
			parts.push_back( std::move( p2 ) );
			auto p3 = partSpecFactory->create( 2, this->createInstrument( "Harp", "Hp", "C2", "C7" ) );
			p3->setUniqueId( "HARP" );
			parts.push_back( std::move( p3 ) );
            return parts;
        }
        
        IMovementSpecUP createMovementSpec( int num, String title ) const
        {
            auto mspec = movementSpecFactory->create( num );
            mspec->setTitle( title );
            return std::move( mspec );
        }
        
        IMovementUP createMovement( int num, String title ) const
        {
            auto mspec = createMovementSpec( num, std::move( title ) );
            auto parts = createPartSpecs();
            MasterTrackParams masterTrackParams;
            masterTrackParams.measureCount = 10;
            masterTrackParams.timeTrack[0] = timeSignatureFactory->create( 4, 4 );
            masterTrackParams.timeTrack[5] = timeSignatureFactory->create( 7, 8 );
            IMasterTrackSPC masterTrack = masterTrackFactory->create( masterTrackParams );
            return std::move( movementFactory->create( mspec, parts, masterTrack, createPartFactory() ) );
        }
        
        INoteUP createNote( const String& pitch, const String& dur, int dots = 0 )
        {
            auto p = pitchFactory->createPitch( pitch );
            auto d = durationFactory->createDuration( dur, dots );
            return noteFactory->createNote( p, d );
        }
        
        Factories()
        : movementSpecFactory( createMovementSpecFactory() )
        , movementFactory( createMovementFactory() )
        , partFactory( createPartFactory() )
        , instrumentFactory( createInstrumentFactory() )
        , rangeFactory( createRangeFactory() )
        , masterTrackFactory( createMasterTrackFactory() )
        , timeSignatureFactory( createTimeSignatureFactory() )
        , pitchFactory( createPitchFactory() )
		, durationFactory( createDurationFactory() )
		, noteFactory( createNoteFactory() )
        , partSpecFactory( createPartSpecFactory() )
		, name1( "Instrument 1" )
        , shortName1( "Instr 1" )
        , range1( rangeFactory->create( "A2", "C7" ) )
        , instrument1( instrumentFactory->create( name1, shortName1, range1->clone() ) )
        
        {}
    };
}