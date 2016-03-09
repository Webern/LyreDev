#include "Lyre/Private/InstrumentFactory.h"
#include "Lyre/IInstrument.h"
#include "Lyre/Private/Instrument.h"


namespace Lyre
{
    namespace Private
    {
        InstrumentFactory::~InstrumentFactory() {}
        
        IInstrumentUP InstrumentFactory::create(
            const InstrumentName& name,
            const IRangeUP& range ) const
        {
            return IInstrumentUP{ new Instrument{ name, range } };
        }
    }
}
