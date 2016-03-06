//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IRangeFactory.h"
#include "Lyre/IRange.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(RangeFactory)
        
        class RangeFactory : public IRangeFactory
        {
        public:
            virtual ~RangeFactory();
            
            virtual IRangeUP create();
        };
    }
}
