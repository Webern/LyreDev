#include "Lyre/Private/LayerFactory.h"
#include "Lyre/ILayer.h"
#include "Lyre/Private/Layer.h"


namespace Lyre
{
    namespace Private
    {
        LayerFactory::~LayerFactory() {}
        
        ILayerUP LayerFactory::create()
        {
            return ILayerUP{ new Layer{} };
        }
    }
}
