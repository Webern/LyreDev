#include "Lyre/Private/MasterTrack.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        MasterTrack::~MasterTrack()
        {
            
        }

        MasterTrack::MasterTrack( const MasterTrackParams& params )
        :myTimeTrack()
        {
            for ( auto it = params.timeTrack.cbegin();
                  it != params.timeTrack.cend(); ++it )
            {
                myTimeTrack[it->first] = it->second->clone();
            }
        }
        
        MasterTrack::MasterTrack( MasterTrackParams&& params )
        :myTimeTrack( std::move( params.timeTrack ) )
        {

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

        std::ostream& MasterTrack::toStream( std::ostream& os ) const
        {
            return os << "MasterTrack not implemented";
        }
        
        const TimeTrack& MasterTrack::getTimeTrack() const
        {
            return myTimeTrack;
        }
    }
}
