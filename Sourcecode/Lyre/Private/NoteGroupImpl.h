//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/INote.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE( NoteGroupImpl )
        
        class EXPORT_FOR_TESTS NoteGroupImpl
        {
        public:
            enum class Type
            {
                Leaf,
                Parent,
                Undecided
            };
            
            ~NoteGroupImpl();
            NoteGroupImpl();
            NoteGroupImpl( const INoteUP& note );
            NoteGroupImpl( const NoteGroupImpl& other );
            NoteGroupImpl( NoteGroupImpl&& other );
            NoteGroupImpl& operator=( const NoteGroupImpl& other );
            NoteGroupImpl& operator=( NoteGroupImpl&& other );
            
            NoteGroupImplUP clone() const;
            
            Type getType() const;
            int getCount() const;
            
            void setNote( const INoteUP& value );
            INoteUP getNote() const;
            Rational getTotalDuration() const;
            
            NoteGroupImplUP getChild( int index ) const;
            void addChild( const NoteGroupImplUP& child );
            void removeChild( int index );
            
        private:
            INoteUP myNote;
            VecNoteGroupImplUP myChildren;
            Type myType;
        };
    }
}
