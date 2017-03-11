//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMasterTrack.h"

namespace Lyre
{
    enum class PUBLIC MasterTrackFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IMasterTrackFactory)
    
    PUBLIC IMasterTrackFactoryUP
        createMasterTrackFactory(
            MasterTrackFactoryType t = 
            MasterTrackFactoryType::Standard );

    class PUBLIC IMasterTrackFactory
    {
    public:
        virtual ~IMasterTrackFactory() {}
        virtual IMasterTrackUP create( const MasterTrackParams& params ) const = 0;
        virtual IMasterTrackUP create( MasterTrackParams&& params ) const = 0;

    };
}
