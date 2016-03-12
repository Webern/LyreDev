//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMasterTrack.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(MasterTrack)
        
        class MasterTrack : public IMasterTrack
        {
        public:
            virtual ~MasterTrack();
            MasterTrack( const MasterTrackParams& params );
            MasterTrack( MasterTrackParams&& params );
            MasterTrack( const MasterTrack& other );
            MasterTrack( MasterTrack&& other );
            MasterTrack& operator=( const MasterTrack& other );
            MasterTrack& operator=( MasterTrack&& other );
            
            virtual IMasterTrackUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            virtual const TimeTrack& getTimeTrack() const;
            
        private:
            TimeTrack myTimeTrack;
        };
    } 
}
