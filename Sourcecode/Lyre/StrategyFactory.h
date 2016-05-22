//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMeasureStrategy.h"
#include "Lyre/IBeatPattern.h"

namespace Lyre
{
    class StrategyFactory
    {
    public:
        static IMeasureStrategyUP createBeamingStrategy();
        static IMeasureStrategyUP createBeamingStrategy( const IBeatPatternUP& beatPattern );
    };
}
