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
        : myInstrument( instrument->clone() )
        , myMasterTrack( masterTrack )
        , myStaves( static_cast<size_t>( numStaves ) )
        , myContext()
		{
            initializeMeasures();
		}

		Part::Part( const Part& other )
        : myInstrument( other.myInstrument->clone() )
        , myMasterTrack( other.myMasterTrack )
        , myStaves()
        , myContext( other.myContext )
		{
            cloneStaves( other.myStaves );
            myContext.isStaffDirty = true;
            myContext.isMeasureDirty = true;
		}

		Part::Part( Part&& other ) noexcept
        : myInstrument( std::move( other.myInstrument ) )
        , myMasterTrack( std::move( other.myMasterTrack ) )
        , myStaves( std::move( other.myStaves ) )
        , myContext( std::move( other.myContext ) )
		{
            myContext.isStaffDirty = true;
            myContext.isMeasureDirty = true;
		}

		Part& Part::operator=( const Part& other )
		{
			myInstrument = other.myInstrument->clone();
            myMasterTrack = other.myMasterTrack;
            myStaves.clear();
            cloneStaves( other.myStaves );
            myContext = other.myContext;
            myContext.isStaffDirty = true;
            myContext.isMeasureDirty = true;
            return *this;
		}

		Part& Part::operator=( Part&& other ) noexcept
		{
			myInstrument = std::move( other.myInstrument->clone() );
            myMasterTrack = std::move( other.myMasterTrack );
            myStaves = std::move( other.myStaves );
            myContext = std::move( other.myContext );
            myContext.isStaffDirty = true;
            myContext.isMeasureDirty = true;
            return *this;
		}

		IPartUP Part::clone() const
		{
			return IPartUP( new Part( *this ) );
		}

		IPartUP Part::move() noexcept
		{
            Part* newPart = new Part( );
            newPart->myInstrument = std::move( this->myInstrument->clone() );
            newPart->myMasterTrack = std::move( this->myMasterTrack );
            newPart->myStaves = std::move( this->myStaves );
            newPart->myContext = std::move( this->myContext );
            newPart->myContext.isStaffDirty = true;
            newPart->myContext.isMeasureDirty = true;
			return IPartUP( newPart );
		}

		std::ostream & Part::toStream( std::ostream & os ) const
		{
			return os << "not implemented";
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

        Part::Part()
        : myInstrument( nullptr )
        , myMasterTrack( nullptr )
        , myStaves()
        , myContext()
        {
            
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
                // TODO myContext.staffIter = myStaves.begin();//( myStaves.begin() + myContext.staffIndex );
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
        
        void Part::cloneStaves( const Staves& otherStaves )
        {
            for ( auto staff = otherStaves.cbegin();
                  staff != otherStaves.cend(); ++staff )
            {
                Measures copiedMeasures{};
                for ( auto measure = staff->cbegin();
                      measure != staff->cend(); ++measure )
                {
                    copiedMeasures.push_back( (*measure)->clone() );
                }
                myStaves.push_back( std::move( copiedMeasures ) );
            }
        }
    }
}
