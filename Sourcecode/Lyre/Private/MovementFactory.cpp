#include "Lyre/Private/MovementFactory.h"
#include "Lyre/IMovement.h"
#include "Lyre/Private/Movement.h"


namespace Lyre
{
    namespace Private
    {
        MovementFactory::~MovementFactory() {}
        
        IMovementUP MovementFactory::create(
            const IMovementSpecUP& spec,
            const VecIPartSpecUP& partSpecs,
            const IMasterTrackSPC& masterTrack,
            const IPartFactoryUP& partFactory ) const
        {
            return IMovementUP{ new Movement( spec, partSpecs, masterTrack, partFactory ) };
        }
    }
}
