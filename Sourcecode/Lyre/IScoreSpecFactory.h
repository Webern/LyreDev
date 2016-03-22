//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IScoreSpec.h"

namespace Lyre
{
    enum class PUBLIC ScoreSpecFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IScoreSpecFactory)
    
    PUBLIC IScoreSpecFactoryUP
        createScoreSpecFactory(
            ScoreSpecFactoryType t = 
            ScoreSpecFactoryType::Standard );

    class PUBLIC IScoreSpecFactory
    {
    public:
        virtual ~IScoreSpecFactory() {}
        virtual IScoreSpecUP create() const = 0;

    };
}
