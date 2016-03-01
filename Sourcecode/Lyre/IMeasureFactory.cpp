#include "Lyre/IMeasureFactory.h"
#include "Lyre/Private/MeasureFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IMeasureFactoryUP
    createMeasureFactory( MeasureFactoryType t )
    {
        switch ( t )
        {
            case MeasureFactoryType::Standard:
                return IMeasureFactoryUP{ new Private::MeasureFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized MeasureFactoryType" )
    }
}
