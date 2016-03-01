//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/NoteGroup.h"

namespace Lyre
{
    FORWARD_DECLARE(ILayer)
        
    class PUBLIC ILayer : public NoteGroup
    {
    public:
        virtual ~ILayer() {};
        virtual ILayerUP copyLayer() const = 0;
        
    };
}
