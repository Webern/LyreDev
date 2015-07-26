#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"

namespace music
{
    class Instrument;
    using InstrumentPtr = std::shared_ptr<Instrument>;
    using InstrumentUPtr = std::unique_ptr<Instrument>;
    using InstrumentSet = std::vector<InstrumentPtr>;
    using InstrumentSetIter = InstrumentSet::iterator;
    using InstrumentSetIterConst = InstrumentSet::const_iterator;
    inline InstrumentPtr makeInstrument() { return std::make_shared<Instrument>(); }
    
    class Instrument
    {
    public:
        Instrument();
        Instrument( const String& name );
        String getName() const;
        void setName( const String& value );
    private:
        String myName;
    };
}