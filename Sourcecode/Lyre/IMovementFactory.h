//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMovement.h"
#include "Lyre/IPartFactory.h"

namespace Lyre
{
    enum class PUBLIC MovementFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IMovementFactory)
    
    PUBLIC IMovementFactoryUP
        createMovementFactory(
            MovementFactoryType t = 
            MovementFactoryType::Standard );

    class PUBLIC IMovementFactory
    {
    public:
        virtual ~IMovementFactory() {}
        virtual IMovementUP create(
       const IMovementSpecUP& spec,
           const VecIPartSpecUP& partSpecs,
           const IMasterTrackSPC& masterTrack,
           const IPartFactoryUP& partFactory ) const = 0;

    };
}
