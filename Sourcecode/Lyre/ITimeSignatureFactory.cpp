#include "Lyre/ITimeSignatureFactory.h"
#include "Lyre/Private/TimeSignatureFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    ITimeSignatureFactoryUP
    createTimeSignatureFactory( TimeSignatureFactoryType t )
    {
        switch ( t )
        {
            case TimeSignatureFactoryType::Standard:
                return ITimeSignatureFactoryUP{ new Private::TimeSignatureFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized TimeSignatureFactoryType" )
    }
}
