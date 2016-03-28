//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IScoreFactory.h"
#include "Lyre/IScore.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(ScoreFactory)
        
        class ScoreFactory : public IScoreFactory
        {
        public:
            virtual ~ScoreFactory();
            
            virtual IScoreUP create( const IScoreSpecUP& spec ) const;
        };
    }
}
