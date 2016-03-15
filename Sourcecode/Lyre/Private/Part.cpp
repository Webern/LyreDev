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
			const IMasterTrackSPC & masterTrack )
		{

		}

		Part::Part( const Part& other )
		{
		}

		Part::Part( Part&& other ) noexcept
		{
		}

		Part& Part::operator=( const Part& other )
		{
			// TODO: insert return statement here
		}

		Part& Part::operator=( Part&& other ) noexcept
		{
			// TODO: insert return statement here
		}

		IPartUP Part::clone() const
		{
			return IPartUP();
		}

		IPartUP Part::move() noexcept
		{
			return IPartUP();
		}

		std::ostream & Part::toStream( std::ostream & os ) const
		{
			// TODO: insert return statement here
		}

		void Part::setStaffContext( int staffIndex )
		{
			myContext.staffIndex = staffIndex;
			myContext.isStaffDirty = true;
		}

		int Part::getStaffContext() const
		{
			return myContext.staffIndex;;
		}

		int Part::getMeasureCount() const
		{
			return static_cast<int>( getStaffIter()->size() );
		}

		const IMeasureUP& Part::getMeasure( int measureIndex ) const
		{
			if ( myContext.measureIndex != measureIndex )
			{
				myContext.measureIndex = measureIndex;
				myContext.isMeasureDirty = true;
			}
			return *getMeasureIter();
		}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		void Part::initializeStaves( int numStaves )
		{
			for ( int i = 0; i < numStaves; ++i )
			{
				myStaves.push_back( Measures{} );
			}
		}

		void Part::initializeMeasures()
		{
			for ( auto staff = myStaves.begin();
				  staff != myStaves.end(); ++staff )
			{
				*staff = std::move( myMasterTrack->createMeasures() );
			}
		}

		Part::StaffIter Part::getStaffIter() const
		{
			if ( myContext.isStaffDirty )
			{
				myContext.staffIter = ( myStaves.begin() + myContext.staffIndex );
				myContext.isStaffDirty = false;
				myContext.isMeasureDirty = true;
			}
			return myContext.staffIter;
		}

		Part::MeasureIter Part::getMeasureIter() const
		{
			auto staff = getStaffIter();
			if ( myContext.isMeasureDirty )
			{
				myContext.measureIter = ( staff->begin() + myContext.measureIndex );
				myContext.isMeasureDirty = false;
			}
			return myContext.measureIter;
		}
    }
}
