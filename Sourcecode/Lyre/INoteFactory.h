//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/INote.h"
#include "Lyre/IDuration.h"
#include "Lyre/IPitch.h"
#include <memory>

namespace Lyre
{
    class INoteFactory;
    using INoteFactoryUP = std::unique_ptr<INoteFactory>;
    using INoteFactorySP = std::shared_ptr<INoteFactory>;
    using INoteFactoryUPC = std::unique_ptr<const INoteFactory>;
    using INoteFactorySPC = std::shared_ptr<const INoteFactory>;
    
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
