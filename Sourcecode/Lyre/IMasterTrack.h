//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(IMasterTrack)
    
    class PUBLIC IMasterTrack : public IStreamable
    {
    public:
        virtual ~IMasterTrack() {};
        virtual IMasterTrackUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
    };
}
