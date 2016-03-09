#include "Lyre/IPartFactory.h"
#include "Lyre/Private/PartFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IPartFactoryUP
    createPartFactory( PartFactoryType t )
    {
        switch ( t )
        {
            case PartFactoryType::Standard:
                return IPartFactoryUP{ new Private::PartFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized PartFactoryType" )
    }
}
