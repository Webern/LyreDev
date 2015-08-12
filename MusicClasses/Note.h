#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"

namespace music
{
    class Note;
    using NotePtr = std::shared_ptr<Note>;
    using NoteUPtr = std::unique_ptr<Note>;
    using NoteSet = std::vector<NotePtr>;
    using NoteSetIter = NoteSet::iterator;
    using NoteSetIterConst = NoteSet::const_iterator;
    inline NotePtr makeNote() { return std::make_shared<Note>(); }
    
    class Pitch;
    using PitchPtr = std::shared_ptr<Pitch>;
    using PitchUPtr = std::unique_ptr<Pitch>;
    using PitchSet = std::vector<PitchPtr>;
    using PitchSetIter = PitchSet::iterator;
    using PitchSetIterConst = PitchSet::const_iterator;
    
    class Duration;
    using DurationPtr = std::shared_ptr<Duration>;
    using DurationUPtr = std::unique_ptr<Duration>;
    using DurationSet = std::vector<DurationPtr>;
    using DurationSetIter = DurationSet::iterator;
    using DurationSetIterConst = DurationSet::const_iterator;
    
    class Dynamic;
    using DynamicPtr = std::shared_ptr<Dynamic>;
    using DynamicUPtr = std::unique_ptr<Dynamic>;
    using DynamicSet = std::vector<DynamicPtr>;
    using DynamicSetIter = DynamicSet::iterator;
    using DynamicSetIterConst = DynamicSet::const_iterator;
    
    class Note
    {
    public:
        virtual ~Note() = default;
    private:
        PitchPtr myPitch;
        DurationPtr myDuration;
        bool myIsRest;
        bool myIsTied;
    };
}