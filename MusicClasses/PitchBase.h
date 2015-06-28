#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"

namespace music
{
    class PitchBase;
    using PitchBasePtr = std::shared_ptr<PitchBase>;
    using PitchBaseUPtr = std::unique_ptr<PitchBase>;
    using PitchBaseSet = std::vector<PitchBasePtr>;
    using PitchBaseSetIter = PitchBaseSet::iterator;
    using PitchBaseSetIterConst = PitchBaseSet::const_iterator;
    inline PitchBasePtr makePitchBase() { return std::make_shared<PitchBase>(); }
    
    class Step;
    using StepPtr = std::shared_ptr<Step>;
    using StepUPtr = std::unique_ptr<Step>;
    using StepSet = std::vector<StepPtr>;
    using StepSetIter = StepSet::iterator;
    using StepSetIterConst = StepSet::const_iterator;
    inline StepPtr makeStep() { return std::make_shared<Step>(); }
    
    class PitchBase
    {
    public:
        virtual ~PitchBase() = default;
    private:
        Step myStep;
        Int myAlter;
    };
}