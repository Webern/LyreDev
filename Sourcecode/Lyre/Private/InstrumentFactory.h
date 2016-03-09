//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IInstrumentFactory.h"
#include "Lyre/IInstrument.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(InstrumentFactory)
        
        class InstrumentFactory : public IInstrumentFactory
        {
        public:
            virtual ~InstrumentFactory();
            
            virtual IInstrumentUP create(
                const InstrumentName& name,
                const IRangeUP& range ) const;
        };
    }
}
