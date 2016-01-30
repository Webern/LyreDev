//PUBLIC
#pragma once
#include "Lyre/INoteGroup.h"

namespace Lyre
{
    FORWARD_DECLARE(NoteGroup)
    FORWARD_DECLARE(INote)
    FORWARD_DECLARE(INoteIter)
    
	class NoteGroup : public INoteGroup
    {
    public:
        NoteGroup();
        NoteGroup( const NoteGroup& other );
        NoteGroup( NoteGroup&& other );
        NoteGroup& operator=( const NoteGroup& other );
        NoteGroup& operator=( NoteGroup&& other );
        virtual ~NoteGroup();
        virtual INoteGroupUP clone() const;
        virtual bool getIsEmpty() const;
        virtual int getCount() const;
        virtual Rational getDurationValue() const;
        virtual void add( const INoteSP& note );
        virtual void remove( const INoteSP& note );
        virtual INoteIterUP getIterator() const;
    protected:
        virtual const INoteSP getNote( int index ) const;
    private:
        class Impl;
        Impl* myImplP;
    };
}
