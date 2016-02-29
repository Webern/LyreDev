#include "Lyre/ILayerFactory.h"
#include "Lyre/Private/LayerFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    ILayerFactoryUP
    createLayerFactory( LayerFactoryType t )
    {
        switch ( t )
        {
            case LayerFactoryType::Standard:
                return ILayerFactoryUP{ new Private::LayerFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized LayerFactoryType" )
    }
}
