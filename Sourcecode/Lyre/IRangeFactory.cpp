#include "Lyre/IRangeFactory.h"
#include "Lyre/Private/RangeFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IRangeFactoryUP
    createRangeFactory( RangeFactoryType t )
    {
        switch ( t )
        {
            case RangeFactoryType::Standard:
                return IRangeFactoryUP{ new Private::RangeFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized RangeFactoryType" )
    }
}
