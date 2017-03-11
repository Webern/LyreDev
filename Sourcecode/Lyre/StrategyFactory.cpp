#include "Lyre/StrategyFactory.h"

namespace Lyre
{
    IMeasureStrategyUP StrategyFactory::createBeamingStrategy()
    {
        return IMeasureStrategyUP{};
    }
    
    
    IMeasureStrategyUP StrategyFactory::createBeamingStrategy( const IBeatPatternUP& beatPattern )
    {
        UNUSED_PARAMETER( beatPattern );
        return IMeasureStrategyUP{};
    }
    
    
}
