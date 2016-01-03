//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/INote.h"
#include <memory>

namespace Lyre
{

    class NoteGroup;
    using NoteGroupUP = std::shared_ptr<NoteGroup>;
    using NoteGroupSP = std::unique_ptr<NoteGroup>;
    
    class NoteGroup
    {
    public:
        NoteGroup();
        
        void addNote( const INoteUP& note );
        
        class Iter;
        
    private:
        class Impl;
        std::unique_ptr<Impl> myImpl;
    };
}
