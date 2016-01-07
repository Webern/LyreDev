//PRIVATE
#pragma once
#include "Lyre/INoteFactory.h"

namespace Lyre
{
    namespace Private
    {
        class NoteFactory;
        using NoteFactorySP = std::shared_ptr<NoteFactory>;
        using NoteFactoryUP = std::unique_ptr<NoteFactory>;
        
        class NoteFactory : public INoteFactory
        {
        
        public:
            virtual ~NoteFactory();
            NoteFactory();
            virtual INoteFactoryUP clone() const;

            virtual INoteUP createNote(
                const IPitchUP& pitch,
                const IDurationUP& duration ) const;
        };
    }
}
