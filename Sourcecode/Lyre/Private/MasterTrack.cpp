#include "Lyre/Private/MasterTrack.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        MasterTrack::~MasterTrack()
        {
        }

        MasterTrack::MasterTrack()
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
    }
}
