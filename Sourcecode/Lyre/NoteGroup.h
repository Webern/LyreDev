//PUBLIC
#pragma once
#include "Lyre/INoteGroup.h"

namespace Lyre
{
    FORWARD_DECLARE(INoteGroup)
    FORWARD_DECLARE(INote)
    FORWARD_DECLARE(NoteGroup)
    
    PUBLIC INoteGroupUP createNoteGroup();
    
    class PUBLIC NoteGroup : public INoteGroup
    {
    public:
        virtual ~NoteGroup();
        NoteGroup();
        NoteGroup( const NoteGroup& other );
        NoteGroup( NoteGroup&& other ) noexcept;
        NoteGroup& operator=( const NoteGroup& other );
        NoteGroup& operator=( NoteGroup&& other ) noexcept;
        virtual INoteGroupUP clone() const;
        virtual bool getIsEmpty() const;
        virtual bool getIsEnd() const;
        virtual int getCount() const;
        virtual Rational getTotalDuration() const;
        virtual INoteUP getCurrent() const;
        virtual INoteUP getNext() const;
        virtual INoteUP getPrevious() const;
        virtual INoteUP getNote( int index ) const;
        virtual void first();
        virtual void last();
        virtual bool next();
        virtual bool previous();
        virtual void jump( int index );
        virtual void add( const INoteUP& note );
        virtual void remove( int index );
        
        int getSubGroupCount() const;
        bool getIsCurrentSubGrouped() const;
        bool getAreAllNotesSubGrouped() const;
        int getCurrentSubGroupIndex() const;
        INoteGroupUP getGroup( int subGroupIndex ) const;
        void addGroup( const INoteGroupUP& group );
        void removeGroup( int subGroupIndex );

    private:
        class Impl;
        Impl* myImplP;
    };
}
