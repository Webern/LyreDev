#include "Lyre/Private/InstrumentFactory.h"
#include "Lyre/IInstrument.h"
#include "Lyre/Private/Instrument.h"


namespace Lyre
{
    namespace Private
    {
        InstrumentFactory::~InstrumentFactory() {}
        
        IInstrumentUP InstrumentFactory::create(
            const String& name,
            const String& shortName,
            const IRangeUP& range ) const
        {
            return IInstrumentUP{ new Instrument{ name, shortName, range } };
        }
    }
}
