//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ILayer.h"

namespace Lyre
{
    enum class PUBLIC LayerFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(ILayerFactory)
    FORWARD_DECLARE(IBeatPattern)
    
    PUBLIC ILayerFactoryUP
        createLayerFactory(
            LayerFactoryType t = 
            LayerFactoryType::Standard );

    class PUBLIC ILayerFactory
    {
    public:
        virtual ~ILayerFactory() {}
        virtual ILayerUP createLayer() = 0;

    };
}
