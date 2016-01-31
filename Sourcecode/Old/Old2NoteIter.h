//PUBLIC
#pragma once
#include "Lyre/INoteIter.h"
#include "Lyre/INoteGroup.h"

namespace Lyre
{
    FORWARD_DECLARE(INoteGroup)
    FORWARD_DECLARE(NoteGroup)
    FORWARD_DECLARE(INote)
    FORWARD_DECLARE(INoteIter)
    
    class NoteIter : public INoteIter
    {
    public:
        NoteIter( const NoteIter& other );
        NoteIter( NoteIter&& other );
        NoteIter& operator=( const NoteIter& other );
        NoteIter& operator=( NoteIter&& other );
        virtual ~NoteIter();
        virtual const INoteSP getPrevious() const;
        virtual const INoteSP getCurrent() const;
        virtual const INoteSP getNext() const;
        virtual const INoteSP getFirst() const;
        virtual const INoteSP getLast() const;
        virtual bool getIsEnd() const;
        virtual bool getIsBegin() const;
        virtual void setBegin();
        virtual void setEnd();
        virtual bool next();
        virtual bool previous();
        virtual void jump( const int index );
    protected:
        NoteIter( NoteGroup* noteGroupP );
    private:
        class Impl;
        Impl* myImplP;
    };
}
