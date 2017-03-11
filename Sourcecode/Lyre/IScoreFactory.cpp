#include "Lyre/IScoreFactory.h"
#include "Lyre/Private/ScoreFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IScoreFactoryUP
    createScoreFactory( ScoreFactoryType t )
    {
        switch ( t )
        {
            case ScoreFactoryType::Standard:
                return IScoreFactoryUP{ new Private::ScoreFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized ScoreFactoryType" )
    }
}
