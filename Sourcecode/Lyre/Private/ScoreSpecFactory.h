//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IScoreSpecFactory.h"
#include "Lyre/IScoreSpec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(ScoreSpecFactory)
        
        class ScoreSpecFactory : public IScoreSpecFactory
        {
        public:
            virtual ~ScoreSpecFactory();
            
            virtual IScoreSpecUP create() const;
        };
    }
}
