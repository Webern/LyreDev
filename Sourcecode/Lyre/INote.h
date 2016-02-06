//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IPitch.h"
#include "Lyre/IDuration.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    FORWARD_DECLARE(INote)
    
    class PUBLIC INote
    {
    public:
        virtual ~INote() {}
        
        virtual INoteUP clone() const = 0;
        
        virtual IPitchUP getPitch() const = 0;
        virtual void setPitch( const IPitchUP& pitch ) = 0;
        
        virtual IDurationUP getDuration() const = 0;
        
        virtual bool getIsRest() const = 0;
        virtual void setIsRest( const bool isRest ) = 0;
        
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual String toString() const = 0;
        
        //virtual bool getIsGroupMember() const = 0;
        //virtual int getGroupMembershipCount() const = 0;
        
        //TODO virtual const NoteGroupsIter& getGroupsIterator() const = 0;
        
    };
    
    PUBLIC std::ostream& operator<<( std::ostream& os, const INote& note );
}
