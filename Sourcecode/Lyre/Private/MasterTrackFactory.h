//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMasterTrackFactory.h"
#include "Lyre/IMasterTrack.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(MasterTrackFactory)
        
        class MasterTrackFactory : public IMasterTrackFactory
        {
        public:
            virtual ~MasterTrackFactory();
            
            virtual IMasterTrackUP create() const;
        };
    }
}
