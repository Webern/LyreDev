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
    
    class Note
    {
    public:
        virtual ~Note() = default;
    private:
        PitchPtr myPitch;
        DurationPtr myDuration;
    };
}