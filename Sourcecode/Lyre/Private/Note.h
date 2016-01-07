//PRIVATE
#pragma once
#include "Lyre/INote.h"
#include "Lyre/IPitch.h"
#include "Lyre/IDuration.h"

namespace Lyre
{
    namespace Private
    {
        class Note;
        using NoteSP = std::shared_ptr<Note>;
        using NoteUP = std::unique_ptr<Note>;
        
        class Note : public INote
        {
        public:
            virtual ~Note();
            Note( const IPitchUP& pitch, const IDurationUP& duration );
            virtual INoteUP clone() const;
            
            virtual IPitchUP getPitch() const;
            virtual void setPitch( const IPitchUP& pitch );
            
            virtual IDurationUP getDuration() const;
            
            virtual bool getIsRest() const;
            virtual void setIsRest( const bool isRest );
            
            virtual std::ostream& toStream( std::ostream& os ) const;
            virtual String toString() const;
            
            //virtual bool getIsGroupMember() const;
            //virtual int getGroupMembershipCount() const;
        private:
            IPitchUP myPitch;
            IDurationUP myDuration;
            bool myIsRest;
        };
    }
}
