#include "Lyre/IInstrumentFactory.h"
#include "Lyre/Private/InstrumentFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IInstrumentFactoryUP
    createInstrumentFactory( InstrumentFactoryType t )
    {
        switch ( t )
        {
            case InstrumentFactoryType::Standard:
                return IInstrumentFactoryUP{ new Private::InstrumentFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized InstrumentFactoryType" )
    }
}
