#include "Lyre/IScoreSpecFactory.h"
#include "Lyre/Private/ScoreSpecFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IScoreSpecFactoryUP
    createScoreSpecFactory( ScoreSpecFactoryType t )
    {
        switch ( t )
        {
            case ScoreSpecFactoryType::Standard:
                return IScoreSpecFactoryUP{ new Private::ScoreSpecFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized ScoreSpecFactoryType" )
    }
}
