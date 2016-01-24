//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/INote.h"
#include "Lyre/IDuration.h"
#include "Lyre/IPitch.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    FORWARD_DECLARE(INoteFactory)
    
    enum class NoteFactoryType
    {
        Standard = 0
    };
    
    INoteFactoryUP createNoteFactory( const NoteFactoryType t );
    
    class INoteFactory
    {
    public:
        virtual ~INoteFactory() {}
        virtual INoteUP createNote(
            const IPitchUP& pitch,
            const IDurationUP& duration ) const = 0;
    };
}
