//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IInstrument.h"

namespace Lyre
{
    enum class PUBLIC InstrumentFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IInstrumentFactory)
    FORWARD_DECLARE(IBeatPattern)
    
    PUBLIC IInstrumentFactoryUP
        createInstrumentFactory(
            InstrumentFactoryType t = 
            InstrumentFactoryType::Standard );

    class PUBLIC IInstrumentFactory
    {
    public:
        virtual ~IInstrumentFactory() {}
        
        virtual IInstrumentUP create(
            const String& name,
            const String& shortName,
            const IRangeUP& range ) const = 0;

    };
}
