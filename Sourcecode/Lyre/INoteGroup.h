//PUBLIC
#pragma once
#include "Lyre/ForwardDec.h"
#include "Lyre/Rational.h"

namespace Lyre
{
    FORWARD_DECLARE(INoteGroup)
    FORWARD_DECLARE(INote)
    
    class INoteGroup
    {
    public:
        virtual ~INoteGroup() {}
        virtual INoteGroupUP clone() const = 0;
        virtual bool getIsEmpty() const = 0;
        virtual int getCount() const = 0;
        virtual Rational getDurationValue() const = 0;
        virtual const INoteSPC getCurrentNote() const = 0;
        virtual const INoteSPC getNextNote() const = 0;
        virtual const INoteSPC getPreviousNote() const = 0;
        virtual void first() = 0;
        virtual void last() = 0;
        virtual bool next() = 0;
        virtual bool previous() = 0;
        virtual void add( const INoteSP& note ) = 0;
        virtual void remove( const INoteSP& note ) = 0;
    };
}
