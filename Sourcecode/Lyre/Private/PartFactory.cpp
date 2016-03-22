#include "Lyre/Private/PartFactory.h"
#include "Lyre/IPart.h"
#include "Lyre/Private/Part.h"


namespace Lyre
{
    namespace Private
    {
        PartFactory::~PartFactory() {}
        
        IPartFactoryUP PartFactory::clone() const
        {
            return IPartFactoryUP{ new PartFactory{ *this } };
        }
        
        IPartUP PartFactory::create(
                const IPartSpecUP& partSpec,
                const IMasterTrackSPC& masterTrack ) const
        {
            return IPartUP{ new Part( partSpec, masterTrack ) };
        }
    }
}
