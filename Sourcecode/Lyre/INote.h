//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IPitch.h"
#include "Lyre/IDuration.h"
#include <vector>
#include <memory>

namespace Lyre
{
    class INoteGroupsIter;
    
    class INote
    {
    public:
        virtual ~INote() {}
        
        virtual IPitchUP getPitch() const = 0;
        virtual void setPitch( const IPitchUP& pitch ) = 0;
        
        virtual IDuration getDuration() const = 0;
        virtual void setDuration( const IDurationUP& duration ) = 0;
        
        virtual bool getIsRest() const = 0;
        virtual void setIsRest( const bool isRest ) = 0;
        
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual String& toString() const = 0;
        
        virtual bool getIsGroupMember() const = 0;
        virtual int getGroupMembershipCount() const = 0;
        virtual const INoteGroupsIter& getGroupsIterator() const = 0;
    };
    
    std::ostream& operator<<( std::ostream& os, const INote& note );
}
