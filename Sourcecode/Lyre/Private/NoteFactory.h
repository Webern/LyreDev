//PRIVATE
#pragma once
#include "Lyre/INoteFactory.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(NoteFactory)
        
        class EXPORT_FOR_TESTS NoteFactory : public INoteFactory
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
