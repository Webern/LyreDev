#include "Lyre/Private/MasterTrack.h"
#include "Lyre/Private/throw.h"
#include "Lyre/IMeasureFactory.h"

namespace Lyre
{
    namespace Private
    {
        MasterTrack::~MasterTrack()
        {
            
        }

        MasterTrack::MasterTrack( const MasterTrackParams& params )
        : myMeasureCount( 1 )
        , myTimeTrack()
		, myMeasureFactory( nullptr )
        {
			myMeasureFactory = createMeasureFactory();
            setMeasureCountIfValid( params.measureCount );
            setTimeTrackIfValid( params.timeTrack );
        }

        MasterTrack::MasterTrack( const MasterTrack& other )
        {
            UNUSED_PARAMETER( other )
        }

        MasterTrack::MasterTrack( MasterTrack&& other )
        {
            UNUSED_PARAMETER( other )
        }

        MasterTrack& MasterTrack::operator=( const MasterTrack& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        MasterTrack& MasterTrack::operator=( MasterTrack&& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        IMasterTrackUP MasterTrack::clone() const
        {
            return IMasterTrackUP{ new MasterTrack{ *this } };
        }
        

		int MasterTrack::getMeasureCount() const
		{
			return myMeasureCount;
		}
        ITimeSignatureUPC MasterTrack::getTimeSignature( int measureIndex ) const
        {
            THROW_IF_BAD_VALUE( measureIndex, 0, myMeasureCount - 1 )
            auto previousIter = myTimeTrack.cbegin();
            for ( auto it = myTimeTrack.cbegin();
                  it != myTimeTrack.cend(); ++it )
            {
                if ( it->first > measureIndex )
                {
                    break;
                }
                previousIter = it;
            }
            return previousIter->second->clone();
        }

		std::vector<IMeasureUP> MasterTrack::createMeasures() const
		{
			std::vector<IMeasureUP> measures;
			int measureIndex = 0;
			auto timeSignature = myTimeTrack.cbegin()->second->clone();
			for ( auto it = myTimeTrack.cbegin();
			      it != myTimeTrack.cend(); ++it )
			{
				for ( ; measureIndex < it->first; ++measureIndex )
				{
					measures.push_back( myMeasureFactory->create( timeSignature ) );
				}
				timeSignature = it->second->clone();
			}
			for ( ; measureIndex < myMeasureCount; ++measureIndex )
            {
                measures.push_back( myMeasureFactory->create( timeSignature ) );
            }
            return std::move( measures );
            
		}
        
        void MasterTrack::setMeasureCountIfValid( int measureCount )
        {
            THROW_IF_BAD_VALUE( measureCount, 1, INT_MAX )
            myMeasureCount = measureCount;
        }
        
        void MasterTrack::setTimeTrackIfValid( const TimeTrack& timeTrack )
        {
            THROW_IF_BAD_VALUE( timeTrack.size(), 1, INT_MAX )
            if( timeTrack.cbegin()->first != 0 )
            {
                THROW_IF_BAD_VALUE( timeTrack.cbegin()->first, 0, INT_MAX )
                THROW( "time track must specify a time signature for measure 0" )
            }
            for ( auto it = timeTrack.cbegin();
                 it != timeTrack.cend(); ++it )
            {
                THROW_IF_BAD_VALUE( it->first, 0, myMeasureCount-1 );
                myTimeTrack[it->first] = it->second->clone();
            }
        }
    }
}
