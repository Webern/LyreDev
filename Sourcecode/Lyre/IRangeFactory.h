//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IRange.h"

namespace Lyre
{
    enum class PUBLIC RangeFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IRangeFactory)
    FORWARD_DECLARE(IBeatPattern)
    
    PUBLIC IRangeFactoryUP
        createRangeFactory(
            RangeFactoryType t = 
            RangeFactoryType::Standard );

    class PUBLIC IRangeFactory
    {
    public:
        virtual ~IRangeFactory() {}
        virtual IRangeUP create() = 0;

    };
}
