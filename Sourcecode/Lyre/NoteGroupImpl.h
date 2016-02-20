//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/INote.h"

namespace Lyre
{
    namespace Private
    {
        class NoteGroupImpl
        {
        public:
            enum class Type
            {
                Leaf,
                Parent,
                Undecided
            };
            using Child = std::shared_ptr<NoteGroupImpl>;
            using Children = std::vector<Child>;
            
            ~NoteGroupImpl();
            NoteGroupImpl();
            NoteGroupImpl( const INoteUP& note );
            NoteGroupImpl( const NoteGroupImpl& other );
            NoteGroupImpl( NoteGroupImpl&& other );
            NoteGroupImpl& operator=( const NoteGroupImpl& other );
            NoteGroupImpl& operator=( NoteGroupImpl&& other );
            
            Type getType() const;
            void setType( const Type t );
            int getCount() const;
            
            void setNote( const INoteUP& value );
            void setChildren( const Children& children );
            Child getChild( int index ) const;
            void addChild( Child child );
            void removeChild( int index );
            
        private:
            INoteUP myNote;
            Children myChildren;
            Type myType;
        };
    }
}
