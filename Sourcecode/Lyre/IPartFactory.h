//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPart.h"
#include "Lyre/IInstrument.h"
#include "Lyre/IMasterTrack.h"
#include "Lyre/IPartSpec.h"

namespace Lyre
{
    enum class PUBLIC PartFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IPartFactory)
    FORWARD_DECLARE(IBeatPattern)
    
    PUBLIC IPartFactoryUP
        createPartFactory(
            PartFactoryType t = 
            PartFactoryType::Standard );

    class PUBLIC IPartFactory
    {
    public:
        virtual ~IPartFactory() {}

        virtual IPartUP create(
                const IPartSpecUP& partSpec,
                const IMasterTrackSPC& masterTrack ) const = 0;

    };
}
