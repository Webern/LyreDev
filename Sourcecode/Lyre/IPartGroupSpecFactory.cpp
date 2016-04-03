#include "Lyre/IPartGroupSpecFactory.h"
#include "Lyre/Private/PartGroupSpecFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IPartGroupSpecFactoryUP
    createPartGroupSpecFactory( PartGroupSpecFactoryType t )
    {
        switch ( t )
        {
            case PartGroupSpecFactoryType::Standard:
                return IPartGroupSpecFactoryUP{ new Private::PartGroupSpecFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized PartGroupSpecFactoryType" )
    }
}
