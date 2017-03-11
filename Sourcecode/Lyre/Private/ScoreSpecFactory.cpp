#include "Lyre/Private/ScoreSpecFactory.h"
#include "Lyre/IScoreSpec.h"
#include "Lyre/Private/ScoreSpec.h"


namespace Lyre
{
    namespace Private
    {
        ScoreSpecFactory::~ScoreSpecFactory() {}
        
        IScoreSpecUP ScoreSpecFactory::create() const
        {
            return IScoreSpecUP{ new ScoreSpec{} };
        }
    }
}
