//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IBeatPattern.h"

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
        virtual IBeatPatternUP create( Integer top, Integer bottom ) = 0;
    };
}
