//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/INote.h"
#include "Lyre/IDuration.h"
#include "Lyre/IPitch.h"

namespace Lyre
{
    FORWARD_DECLARE(INoteFactory)
    
    enum class PUBLIC NoteFactoryType
    {
        Standard = 0
    };
    
    INoteFactoryUP PUBLIC createNoteFactory( const NoteFactoryType t );
    
    class PUBLIC INoteFactory
    {
    public:
        virtual ~INoteFactory() {}
        virtual INoteUP createNote(
            const IPitchUP& pitch,
            const IDurationUP& duration ) const = 0;
    };
}
