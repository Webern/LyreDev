#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"

namespace music
{
    class Pitch;
    using PitchPtr = std::shared_ptr<Pitch>;
    using PitchUPtr = std::unique_ptr<Pitch>;
    using PitchSet = std::vector<PitchPtr>;
    using PitchSetIter = PitchSet::iterator;
    using PitchSetIterConst = PitchSet::const_iterator;
    inline PitchPtr makePitch() { return std::make_shared<Pitch>(); }
    
    class Pitch
    {
    public:
        virtual ~Pitch() = default;
    private:
        PitchBase myPitchBase;
        Int myOctave;
    };
}