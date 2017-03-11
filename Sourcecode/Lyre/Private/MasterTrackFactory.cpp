#include "Lyre/Private/MasterTrackFactory.h"
#include "Lyre/IMasterTrack.h"
#include "Lyre/Private/MasterTrack.h"


namespace Lyre
{
    namespace Private
    {
        MasterTrackFactory::~MasterTrackFactory() {}
        
        IMasterTrackUP MasterTrackFactory::create(
            const MasterTrackParams& params ) const
        {
            return IMasterTrackUP{ new MasterTrack{ params } };
        }
        
        IMasterTrackUP MasterTrackFactory::create(
            MasterTrackParams&& params ) const
        {
            return IMasterTrackUP{ new MasterTrack{ std::move( params ) } };
        }
    }
}
