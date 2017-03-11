#include "Lyre/Private/NoteFactory.h"
#include "Lyre/Private/Note.h"

namespace Lyre
{
    namespace Private
    {
        NoteFactory::~NoteFactory() {}
        NoteFactory::NoteFactory() {}
        
        INoteFactoryUP NoteFactory::clone() const
        {
            NoteFactory* nf = new NoteFactory{};
            return INoteFactoryUP{ nf };
        }
        
        INoteUP NoteFactory::createNote(
            const IPitchUP& pitch,
            const IDurationUP& duration ) const
        {
            return INoteUP{ new Note{ pitch, duration } };
        }
    }
}
