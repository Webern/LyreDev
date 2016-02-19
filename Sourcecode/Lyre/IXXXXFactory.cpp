#include "Lyre/IXXXXFactory.h"
#include "Lyre/Private/XXXXFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IXXXXFactoryUP
    createXXXXFactory( XXXXFactoryType t )
    {
        switch ( t )
        {
            case XXXXFactoryType::Standard:
                return IXXXXFactoryUP{ new Private::XXXXFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized XXXXFactoryType" )
    }
}
