//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(ILayer)
    
    static const int DEFAULT_TOP = 4;
    static const int DEFAULT_BOTTOM = 4;
    
    class PUBLIC ILayer : public IStreamable
    {
    public:
        virtual ~ILayer() {};
        virtual ILayerUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
    };
}
