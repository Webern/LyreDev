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
		, myStaffContext( 0 )
		{
            initializeMeasures();
		}

		Part::Part( const Part& other )
        : myInstrument( other.myInstrument->clone() )
        , myMasterTrack( other.myMasterTrack )
        , myStaves()
		, myStaffContext( other.myStaffContext )
		{
            cloneStaves( other.myStaves );
		}

		Part::Part( Part&& other ) noexcept
        : myInstrument( std::move( other.myInstrument ) )
        , myMasterTrack( std::move( other.myMasterTrack ) )
        , myStaves( std::move( other.myStaves ) )
		, myStaffContext( std::move( other.myStaffContext ) )
		{

		}

		Part& Part::operator=( const Part& other )
		{
			myInstrument = other.myInstrument->clone();
            myMasterTrack = other.myMasterTrack;
            myStaves.clear();
            cloneStaves( other.myStaves );
			myStaffContext = other.myStaffContext;
            return *this;
		}

		Part& Part::operator=( Part&& other ) noexcept
		{
			myInstrument = std::move( other.myInstrument->clone() );
            myMasterTrack = std::move( other.myMasterTrack );
            myStaves = std::move( other.myStaves );
			myStaffContext = std::move( other.myStaffContext );
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
			newPart->myStaffContext = std::move( this->myStaffContext );
			// this becomes an unusable object
			return IPartUP( newPart );
		}

		std::ostream & Part::toStream( std::ostream & os ) const
		{
			return os << "not implemented";
		}

		void Part::setStaffContext( int staffIndex )
		{
			THROW_IF_BAD_VALUE( staffIndex, 0, static_cast<int>( myStaves.size() - 1 ) );
			myStaffContext = staffIndex;
		}

		int Part::getStaffContext() const
		{
			return myStaffContext;
		}

		int Part::getMeasureCount() const
		{
			return static_cast<int>( (myStaves.cbegin() + myStaffContext)->size() );
		}

		IMeasure* const Part::getMeasure( int measureIndex )
		{
			THROW_IF_BAD_VALUE( measureIndex, 0, myMasterTrack->getMeasureCount() );
			StaffIter staffIter = myStaves.begin() + myStaffContext;
			MeasureIter iter = staffIter->begin() + measureIndex;
			return iter->get();
		}

		const IMeasure* const Part::getMeasure( int measureIndex ) const
		{
			THROW_IF_BAD_VALUE( measureIndex, 0, myMasterTrack->getMeasureCount() );
			StaffIterConst staffIter = myStaves.cbegin() + myStaffContext;
			MeasureIterConst iter = staffIter->cbegin() + measureIndex;
			return iter->get();
		}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Part::Part()
        : myInstrument( nullptr )
        , myMasterTrack( nullptr )
        , myStaves()
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
