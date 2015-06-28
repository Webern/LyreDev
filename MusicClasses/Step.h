#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"

namespace music
{
    class Step;
    using StepPtr = std::shared_ptr<Step>;
    using StepUPtr = std::unique_ptr<Step>;
    using StepSet = std::vector<StepPtr>;
    using StepSetIter = StepSet::iterator;
    using StepSetIterConst = StepSet::const_iterator;
    inline StepPtr makeStep() { return std::make_shared<Step>(); }
    
    enum class StepName
    {
        C = 0,
        D = 1,
        E = 2,
        F = 3,
        G = 4,
        A = 5,
        B = 6
    };
    
    class Step
    {
    public:
        virtual ~Step() = default;
        Step();
        explicit Step( const StepName& value );
        explicit Step( const Int value );
    private:
        Step myStep;
    };
}