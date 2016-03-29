//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(IExporter)
    
    class PUBLIC IExporter
    {
    public:
        virtual ~IExporter() {};
        virtual void exportMusic( std::ostream& os ) = 0;
        
    };
}
