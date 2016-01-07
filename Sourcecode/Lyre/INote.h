//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IPitch.h"
#include "Lyre/IDuration.h"
#include <vector>
#include <memory>

namespace Lyre
{
    class INote;
    using INoteUP = std::unique_ptr<INote>;
    using INoteSP = std::shared_ptr<INote>;
    using INoteUPC = std::unique_ptr<const INote>;
    using INoteSPC = std::shared_ptr<const INote>;
    
    
    class INote
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
    
    std::ostream& operator<<( std::ostream& os, const INote& note );
}
