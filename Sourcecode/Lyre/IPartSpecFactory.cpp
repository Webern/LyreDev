#include "Lyre/IPartSpecFactory.h"
#include "Lyre/Private/PartSpecFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IPartSpecFactoryUP
    createPartSpecFactory( PartSpecFactoryType t )
    {
        switch ( t )
        {
            case PartSpecFactoryType::Standard:
                return IPartSpecFactoryUP{ new Private::PartSpecFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized PartSpecFactoryType" )
    }
}
