#include "Lyre/IMasterTrackFactory.h"
#include "Lyre/Private/MasterTrackFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IMasterTrackFactoryUP
    createMasterTrackFactory( MasterTrackFactoryType t )
    {
        switch ( t )
        {
            case MasterTrackFactoryType::Standard:
                return IMasterTrackFactoryUP{ new Private::MasterTrackFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized MasterTrackFactoryType" )
    }
}
