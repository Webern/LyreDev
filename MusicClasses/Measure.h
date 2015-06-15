#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"

namespace music
{
    class Measure;
    using MeasurePtr = std::shared_ptr<Measure>;
    using MeasureUPtr = std::unique_ptr<Measure>;
    using MeasureSet = std::vector<MeasurePtr>;
    using MeasureSetIter = MeasureSet::iterator;
    using MeasureSetIterConst = MeasureSet::const_iterator;
    inline MeasurePtr makeMeasure() { return std::make_shared<Measure>(); }
    
    class TimeSignature;
    using TimeSignaturePtr = std::shared_ptr<TimeSignature>;
    using TimeSignatureUPtr = std::unique_ptr<TimeSignature>;
    using TimeSignatureSet = std::vector<TimeSignaturePtr>;
    using TimeSignatureSetIter = TimeSignatureSet::iterator;
    using TimeSignatureSetIterConst = TimeSignatureSet::const_iterator;
    
    class Note;
    using NotePtr = std::shared_ptr<Note>;
    using NoteUPtr = std::unique_ptr<Note>;
    using NoteSet = std::vector<NotePtr>;
    using NoteSetIter = NoteSet::iterator;
    using NoteSetIterConst = NoteSet::const_iterator;
    
    class Measure
    {
    public:
        virtual ~Measure() = default;
    private:
        TimeSignaturePtr myTimeSignature;
        NoteSet myNotes;
    };
}