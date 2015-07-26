#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"
#include "Duration.h"

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
        TimeSignature();
        TimeSignature( Int beatCount, const Duration& beatDuration );
        virtual ~TimeSignature() = default;
        void setBeatCount( const Int value );
        Int getBeatCount() const;
        void setBeatDuration( const Duration& value );
        Rational getMeasureDuration() const;
        Duration getBeatDuration() const;
        Int getDenominator() const;
        
    private:
        Int myBeatCount;
        Duration myBeatDuration;
    };
}