//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/Rational.h"

namespace Lyre
{
    FORWARD_DECLARE(INoteGroup)
    FORWARD_DECLARE(INote)
    
    class PUBLIC INoteGroup : public IStreamable
    {
    public:
        virtual ~INoteGroup() {}
        virtual INoteGroupUP clone() const = 0;
        virtual INoteGroupUP move() = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual bool getIsEmpty() const = 0;
        virtual int getCount() const = 0;
        virtual Rational getTotalDuration() const = 0;
        virtual INoteUP getNote( int noteIndex ) const = 0;
        virtual void add( const INoteUP& note ) = 0;
        virtual void remove( int noteIndex ) = 0;
        
        virtual int getGroupCount() const = 0;
        virtual bool getIsInGroup( int noteIndex ) const = 0;
        virtual int getGroupIndex( int noteIndex ) const = 0;
        virtual INoteGroupUP getGroup( int groupIndex ) const = 0;
        virtual void addGroup( const INoteGroupUP& group ) = 0;
        virtual void removeGroup( int groupIndex ) = 0;
    };
}
