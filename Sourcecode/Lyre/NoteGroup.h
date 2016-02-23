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
        NoteGroup( NoteGroup&& other );
        NoteGroup& operator=( const NoteGroup& other );
        NoteGroup& operator=( NoteGroup&& other );
        virtual INoteGroupUP clone() const;
        virtual bool getIsEmpty() const;
        virtual bool getIsEnd() const;
        virtual int getCount() const;
        virtual Rational getTotalDuration() const;
        virtual const INoteUP getCurrent() const;
        virtual const INoteUP getNext() const;
        virtual const INoteUP getPrevious() const;
        virtual void first();
        virtual void last();
        virtual bool next();
        virtual bool previous();
        virtual void jump( int index );
        virtual void add( const INoteUP& note );
        virtual void remove( int index );

    private:
        class Impl;
        Impl* myImplP;
    };
}
