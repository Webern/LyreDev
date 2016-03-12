#include "Lyre/Private/MasterTrackFactory.h"
#include "Lyre/IMasterTrack.h"
#include "Lyre/Private/MasterTrack.h"


namespace Lyre
{
    namespace Private
    {
        MasterTrackFactory::~MasterTrackFactory() {}
        
        IMasterTrackUP MasterTrackFactory::create() const
        {
            return IMasterTrackUP{ new MasterTrack{} };
        }
    }
}
