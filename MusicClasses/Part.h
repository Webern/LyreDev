#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"

namespace music
{
    class Part;
    using PartPtr = std::shared_ptr<Part>;
    using PartUPtr = std::unique_ptr<Part>;
    using PartSet = std::vector<PartPtr>;
    using PartSetIter = PartSet::iterator;
    using PartSetIterConst = PartSet::const_iterator;
    inline PartPtr makePart() { return std::make_shared<Part>(); }
    
    class Measure;
    using MeasurePtr = std::shared_ptr<Measure>;
    using MeasureUPtr = std::unique_ptr<Measure>;
    using MeasureSet = std::vector<MeasurePtr>;
    using MeasureSetIter = MeasureSet::iterator;
    using MeasureSetIterConst = MeasureSet::const_iterator;
    
    class Instrument;
    using InstrumentPtr = std::shared_ptr<Instrument>;
    using InstrumentUPtr = std::unique_ptr<Instrument>;
    using InstrumentSet = std::vector<InstrumentPtr>;
    using InstrumentSetIter = InstrumentSet::iterator;
    using InstrumentSetIterConst = InstrumentSet::const_iterator;
    
    class Part
    {
    public:
        ~Part() = default;
        const MeasureSet getMeasureSet() const;
        void addMeasure( const MeasurePtr& measure );
        void removeMeasure( const MeasureSetIterConst& iter );
        void clearMeasureSet();
        
        PartPtr clone() const;
        
    private:
        InstrumentPtr myInstrument;
        MeasureSet myMeasureSet;
    };
}