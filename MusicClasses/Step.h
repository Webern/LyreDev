#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"
#include "Mod.h"

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
        explicit Step( const StepName value );
        explicit Step( const Int value );
        void setValue( const Int value );
        void setValue( const StepName value );
        Int getValue() const;
        StepName getStepName() const;
        operator Int() const;
        Step& operator++();
        Step& operator++(int);
        Step& operator--();
        Step& operator--(int);
        Step& add( const Int value );
        Step& subtract( const Int value );
    private:
        Mod<Int, 7> myValue;
    };
    
    bool operator==( const Step& r, const Step& l );
    bool operator!=( const Step& r, const Step& l );
    bool operator< ( const Step& r, const Step& l );
    bool operator> ( const Step& r, const Step& l );
    bool operator<=( const Step& r, const Step& l );
    bool operator>=( const Step& r, const Step& l );
}