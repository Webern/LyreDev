//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ILayerFactory.h"
#include "Lyre/ILayer.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(LayerFactory)
        
        class LayerFactory : public ILayerFactory
        {
        public:
            virtual ~LayerFactory();
            
            virtual ILayerUP createLayer();
        };
    }
}
