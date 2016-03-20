//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPartSpec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(PartSpec)
        
        class PartSpec : public IPartSpec
        {
        public:
            virtual ~PartSpec();
            PartSpec( const IInstrumentUP& instrument );
            PartSpec( const PartSpec& other );
            PartSpec( PartSpec&& other );
            PartSpec& operator=( const PartSpec& other );
            PartSpec& operator=( PartSpec&& other );
            
            virtual IPartSpecUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            virtual String getName() const;
            virtual String getUniqueId() const;
            virtual IInstrumentUP getInstrument() const;
            
            virtual void setName( const String& name );
            virtual void setUniqueId( const String& uniqueId );
            virtual void setInstrument( const IInstrumentUP& instrument );
            
        private:
            String myName;
            String myId;
            IInstrumentUPC myInstrument;
            
        };
    } 
}
