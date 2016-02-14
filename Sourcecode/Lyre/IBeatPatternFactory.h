//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IBeatPattern.h"
#if 1==0
namespace Lyre
{
    enum class PUBLIC BeatPatternFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IBeatPatternFactory)
    
    PUBLIC IBeatPatternFactoryUP
        createBeatPatternFactory(
            BeatPatternFactoryType t = 
            BeatPatternFactoryType::Standard );

    class PUBLIC IBeatPatternFactory
    {
    public:
        virtual ~IBeatPatternFactory() {}
        virtual IBeatPatternUP create() = 0;
    };
}
#endif
