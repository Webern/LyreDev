#if 1==0

#include "Lyre/Private/LayerFactory.h"
#include "Lyre/ILayer.h"
#include "Lyre/Private/Layer.h"


namespace Lyre
{
    namespace Private
    {
        LayerFactory::~LayerFactory() {}
        
        ILayerUP LayerFactory::createLayer()
        {
            return ILayerUP{ new Layer{} };
        }
    }
}

#endif
