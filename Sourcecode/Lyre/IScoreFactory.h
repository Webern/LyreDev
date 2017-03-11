//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IScore.h"

namespace Lyre
{
    enum class PUBLIC ScoreFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IScoreFactory)
    
    PUBLIC IScoreFactoryUP
        createScoreFactory(
            ScoreFactoryType t = 
            ScoreFactoryType::Standard );

    class PUBLIC IScoreFactory
    {
    public:
        virtual ~IScoreFactory() {}
        virtual IScoreUP create( const IScoreSpecUP& spec ) const = 0;

    };
}
