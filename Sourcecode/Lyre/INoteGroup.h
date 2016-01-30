//PUBLIC
#pragma once
#include "Lyre/ForwardDec.h"
#include "Lyre/Rational.h"

namespace Lyre
{

    FORWARD_DECLARE(INoteGroup)
    FORWARD_DECLARE(INote)
    FORWARD_DECLARE(INoteIter)
    
    class INoteGroup
    {
        friend class INoteIter;
        
    public:
        virtual ~INoteGroup() {}
        virtual INoteGroupUP clone() const = 0;
        virtual bool getIsEmpty() const = 0;
        virtual int getCount() const = 0;
        virtual Rational getDurationValue() const = 0;
        virtual void add( const INoteSP& note ) = 0;
        virtual void remove( const INoteSP& note ) = 0;
        virtual INoteIterUP getIterator() const = 0;
    
    protected:
        virtual const INoteSP getNote( int index ) const = 0;
    };
}
