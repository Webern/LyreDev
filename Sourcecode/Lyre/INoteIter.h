//PUBLIC
#pragma once
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    
    FORWARD_DECLARE(INoteGroup)
    FORWARD_DECLARE(INote)
    FORWARD_DECLARE(INoteIter)
    
    class INoteIter
    {
        friend class INoteGroup;
        
    public:
        virtual ~INoteIter() {}
        virtual const INoteSP getPrevious() const = 0;
        virtual const INoteSP getCurrent() const = 0;
        virtual const INoteSP getNext() const = 0;
        virtual const INoteSP getFirst() const = 0;
        virtual const INoteSP getLast() const = 0;
        virtual bool getIsEnd() const = 0;
        virtual bool getIsBegin() const = 0;
        virtual void setBegin() = 0;
        virtual void setEnd() = 0;
        virtual bool next() = 0;
        virtual bool previous() = 0;
        virtual void jump( const int index ) = 0;
        
    protected:
        INoteIter( INoteGroup* noteGroupP );
        
    };
}
