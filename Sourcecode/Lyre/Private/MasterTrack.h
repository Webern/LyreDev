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
            
			virtual int getMeasureCount() const;
            virtual ITimeSignatureUPC getTimeSignature( int measureIndex ) const;
			virtual std::vector<IMeasureUP> createMeasures() const;
            
        private:
            int myMeasureCount;
            TimeTrack myTimeTrack;
			IMeasureFactoryUPC myMeasureFactory;

            void setMeasureCountIfValid( int measureCount );
            void setTimeTrackIfValid( const TimeTrack& timeTrack );
        };
    } 
}
