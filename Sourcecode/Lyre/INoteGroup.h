//PUBLIC
#pragma once
#include "Lyre/Rational.h"

namespace Lyre
{
    FORWARD_DECLARE(INoteGroup)
    FORWARD_DECLARE(INote)
    
    class PUBLIC INoteGroup
    {
    public:
        virtual ~INoteGroup() {}
        virtual INoteGroupUP clone() const = 0;
        virtual bool getIsEmpty() const = 0;
        virtual bool getIsEnd() const = 0;
        virtual int getCount() const = 0;
        virtual Rational getTotalDuration() const = 0;
        virtual INoteUP getCurrent() const = 0;
        virtual INoteUP getNext() const = 0;
        virtual INoteUP getPrevious() const = 0;
        virtual void first() = 0;
        virtual void last() = 0;
        virtual bool next() = 0;
        virtual bool previous() = 0;
        virtual void jump( int index ) = 0;
        virtual void add( const INoteUP& note ) = 0;
        virtual void remove( int index ) = 0;
    };
}
