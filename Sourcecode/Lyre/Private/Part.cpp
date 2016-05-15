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
			const IPartSpecUP& spec,
			const IMasterTrackSPC & masterTrack )
        : myPartSpec( nullptr )
        , myMasterTrack( masterTrack )
        , myStaves()
		, myStaffContext( 0 )
		{
            THROW_IF_NULL( spec )
            THROW_IF_NULL( masterTrack )
            myPartSpec = spec->clone();
            initializeMeasures( myPartSpec->getNumStaves() );
		}

        
		Part::Part( const Part& other )
        : myPartSpec( other.myPartSpec->clone() )
        , myMasterTrack( other.myMasterTrack )
        , myStaves()
		, myStaffContext( other.myStaffContext )
		{
            cloneStaves( other.myStaves );
		}

        
		Part::Part( Part&& other ) noexcept
        : myPartSpec( std::move( other.myPartSpec ) )
        , myMasterTrack( std::move( other.myMasterTrack ) )
        , myStaves( std::move( other.myStaves ) )
		, myStaffContext( std::move( other.myStaffContext ) )
		{

		}
        

		Part& Part::operator=( const Part& other )
		{
			myPartSpec = other.myPartSpec->clone();
            myMasterTrack = other.myMasterTrack;
            myStaves.clear();
            cloneStaves( other.myStaves );
			myStaffContext = other.myStaffContext;
            return *this;
		}
        

		Part& Part::operator=( Part&& other ) noexcept
		{
			myPartSpec = std::move( other.myPartSpec );
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
            newPart->myPartSpec = std::move( this->myPartSpec );
            newPart->myMasterTrack = std::move( this->myMasterTrack );
            newPart->myStaves = std::move( this->myStaves );
			newPart->myStaffContext = std::move( this->myStaffContext );
			// *this becomes an unusable object
			return IPartUP( newPart );
		}

		std::ostream & Part::toStream( std::ostream & os ) const
		{
            os << "Part " << myPartSpec->getName() << std::endl;
            os << "{" << std::endl;
            int staffIndex = 0;
			for ( auto s = myStaves.cbegin(); s != myStaves.cend(); ++s )
            {
                os << "    " << myPartSpec->getUniqueId() << " STAFF " << staffIndex << std::endl;
                os << "    {" << std::endl;
                int measureIndex = 0;
                for ( auto m = s->cbegin(); m != s->cend(); ++m )
                {
                    
                    std::istringstream iss( (*m)->toString() );
                    std::string line;
                    while( std::getline( iss, line ) )
                    {
                        os << "        " << line;
                        if( line == "Measure" )
                        {
                            os << " " << measureIndex;
                        }
                        os << std::endl;
                    }
                    ++measureIndex;
                }
                os << "    }" << std::endl;
                ++staffIndex;
            }
            os << "}";
            return os;
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
        
        
        IPartSpecUP Part::getPartSpec() const
        {
            return myPartSpec->clone();
        }
        

		int Part::getMeasureCount() const
		{
			return static_cast<int>( (myStaves.cbegin() + myStaffContext)->size() );
		}
        

		IMeasureH Part::getMeasure( int measureIndex )
		{
			THROW_IF_BAD_VALUE( measureIndex, 0, myMasterTrack->getMeasureCount() );
			StaffIter staffIter = myStaves.begin() + myStaffContext;
			MeasureIter iter = staffIter->begin() + measureIndex;
			return IMeasureH{ *iter };
		}
        

		const IMeasureHC Part::getMeasure( int measureIndex ) const
		{
			return getMeasureConst( measureIndex );
		}
        
        
        const IMeasureHC Part::getMeasureConst( int measureIndex ) const
        {
            THROW_IF_BAD_VALUE( measureIndex, 0, myMasterTrack->getMeasureCount() );
			StaffIterConst staffIter = myStaves.cbegin() + myStaffContext;
			MeasureIterConst iter = staffIter->cbegin() + measureIndex;
			return IMeasureHC{ *iter };
        }
        

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Part::Part()
        : myPartSpec( nullptr )
        , myMasterTrack( nullptr )
        , myStaves()
        {
            
        }
        
        
		void Part::initializeMeasures( int numStaves )
		{
            for( int i = 0; i < numStaves; ++i )
            {
                myStaves.push_back( Measures{} );
                auto staff = ( myStaves.begin() + i );
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
