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
        virtual INoteGroupUP clone() const = 0;
        virtual ILayerUP copyLayer() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
    };
}
