#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>

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
    };
}