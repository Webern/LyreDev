#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/Private/BeatPatternFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IBeatPatternFactoryUP
    createBeatPatternFactory( BeatPatternFactoryType t )
    {
        switch ( t )
        {
            case BeatPatternFactoryType::Standard:
                return IBeatPatternFactoryUP{ new Private::BeatPatternFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized BeatPatternFactoryType" )
    }
}

