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
        virtual int getCount() const = 0;
        virtual Rational getTotalDuration() const = 0;
        virtual INoteUP getNote( int index ) const = 0;
        virtual void add( const INoteUP& note ) = 0;
        virtual void remove( int index ) = 0;
        
        virtual int getGroupCount() const = 0;
        virtual bool getIsInGroup( int noteIndex ) const = 0;
        virtual int getGroupIndex( int noteIndex ) const = 0;
        virtual INoteGroupUP getGroup( int groupIndex ) const = 0;
        virtual void addGroup( const INoteGroupUP& group ) = 0;
        virtual void removeGroup( int subGroupIndex ) = 0;
    };
}
