//PRIVATE
#pragma once
#include "Lyre/INote.h"
#include "Lyre/IPitch.h"
#include "Lyre/IDuration.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(Note)
        
        class EXPORT_FOR_TESTS Note : public INote
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
            
            virtual int getBeams() const;
            virtual void setBeams( int value );
            virtual int getMaxBeams() const;
            
            virtual std::ostream& toStream( std::ostream& os ) const;
            virtual String toString() const;
            
        private:
            IPitchUP myPitch;
            IDurationUP myDuration;
            bool myIsRest;
            int myBeams;
        };
    }
}
