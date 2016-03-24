#include "Lyre/Private/ScoreFactory.h"
#include "Lyre/IScore.h"
#include "Lyre/Private/Score.h"


namespace Lyre
{
    namespace Private
    {
        ScoreFactory::~ScoreFactory() {}
        
        IScoreUP ScoreFactory::create() const
        {
            return IScoreUP{ new Score{} };
        }
    }
}
