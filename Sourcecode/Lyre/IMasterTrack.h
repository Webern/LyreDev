//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ITimeSignature.h"
#include <map>

namespace Lyre
{
    FORWARD_DECLARE(IMasterTrack)
    FORWARD_DECLARE(IMeasure)
	FORWARD_DECLARE(IMeasureFactory)

    using MeasureIndex = int;
    using TimeTrack = std::map<MeasureIndex,ITimeSignatureUPC>;
    
    struct MasterTrackParams
    {
        int measureCount;
        TimeTrack timeTrack;
    };
    
    class PUBLIC IMasterTrack
    {
    public:
        virtual ~IMasterTrack() {};
        virtual IMasterTrackUP clone() const = 0;
        
		virtual int getMeasureCount() const = 0;
        virtual ITimeSignatureUPC getTimeSignature( int measureIndex ) const = 0;
		virtual std::vector<IMeasureUP> createMeasures() const = 0;
        
    };
}
