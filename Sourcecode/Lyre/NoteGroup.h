//PUBLIC
#pragma once
#include "Lyre/ForwardDec.h"
#include "Lyre/INoteGroup.h"

namespace Lyre
{
    FORWARD_DECLARE(INoteGroup)
    FORWARD_DECLARE(INote)
    FORWARD_DECLARE(NoteGroup)
    
    class NoteGroup : public INoteGroup
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
        virtual int getCount() const;
        virtual Rational getDurationValue() const;
        virtual const INoteSPC getCurrentNote() const;
        virtual const INoteSPC getNextNote() const;
        virtual const INoteSPC getPreviousNote() const;
        virtual void first();
        virtual void last();
        virtual bool next();
        virtual bool previous();
        virtual void jump( int index );
        virtual void add( const INoteSP& note );
        virtual void remove( const INoteSP& note );
    private:
        class Impl;
        Impl* myImplP;
    };
}
