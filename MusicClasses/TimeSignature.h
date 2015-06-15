#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"

namespace music
{
    class TimeSignature;
    using TimeSignaturePtr = std::shared_ptr<TimeSignature>;
    using TimeSignatureUPtr = std::unique_ptr<TimeSignature>;
    using TimeSignatureSet = std::vector<TimeSignaturePtr>;
    using TimeSignatureSetIter = TimeSignatureSet::iterator;
    using TimeSignatureSetIterConst = TimeSignatureSet::const_iterator;
    inline TimeSignaturePtr makeTimeSignature() { return std::make_shared<TimeSignature>(); }
    
    class TimeSignature
    {
    public:
        virtual ~TimeSignature() = default;
    private:
        Int myNumerator;
        Int myDenominator;
    };
}