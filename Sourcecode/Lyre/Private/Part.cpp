#include "Lyre/Private/Part.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"
#include "Lyre/IInstrument.h"
#include "Lyre/Private/Instrument.h"
#include "Lyre/Private/Range.h"
#include "Lyre/Private/Measure.h"

namespace Lyre
{
	namespace Private
	{

		Part::~Part()
		{

		}

		Part::Part(
			int numStaves,
			const IInstrumentUP& instrument,
			const IMasterTrackSPC& masterTrack )
			: myNumStaves( 1 )
			, myInstrument( nullptr )
			, myMasterTrack( nullptr )
			, myStaves()
			, myCurrentStaffIndex( 0 )
			, myCurrentStaff()
			, myCurrentMeasureIndex( 0 )
			, myCurrentMeasure()
		{
			THROW_IF_BAD_VALUE( numStaves, 0, INT_MAX )
				myNumStaves = numStaves;
			THROW_IF_NULL( instrument )
				myInstrument = instrument->clone();
			THROW_IF_NULL( masterTrack )
				myMasterTrack = masterTrack;
			initializeMeasures();
			// myCurrentStaff = myStaves.begin();
			// myCurrentMeasure = myCurrentStaff->begin();
		}


		IPartUP Part::clone() const
		{
			throw "not implemented";
		}


		IPartUP Part::move() noexcept
		{
			throw "not implemented";
		}


		std::ostream& Part::toStream( std::ostream& os ) const
		{
			UNUSED_PARAMETER( os );
			throw "not implemented";
		}


		void Part::setStaffContext( int staffIndex )
		{
			UNUSED_PARAMETER( staffIndex );
			throw "not implemented";
		}


		int Part::getStaffContext() const
		{
			throw "not implemented";
		}


		int Part::getMeasureCount() const
		{
			throw "not implemented";
		}


		const IMeasureUP& Part::getMeasure( int measureIndex ) const
		{
			UNUSED_PARAMETER( measureIndex );
			throw "not implemented";
		}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		void Part::initializeMeasures()
		{
			for ( int i = 0; i < myNumStaves; ++i )
			{
				// this line crashes in visual studio
				myStaves.push_back( std::move( myMasterTrack->createMeasures() ) );
			}
		}

    }
}
