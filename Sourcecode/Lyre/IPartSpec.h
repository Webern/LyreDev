//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IInstrument.h"

namespace Lyre
{
    FORWARD_DECLARE(IPartSpec)
    
    class PUBLIC IPartSpec : public IStreamable
    {
    public:
        virtual ~IPartSpec() {};
        virtual IPartSpecUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual String getName() const = 0;
        virtual String getUniqueId() const = 0;
        virtual IInstrumentUP getInstrument() const = 0;
        virtual int getNumStaves() const = 0;
        
        virtual void setName( const String& name ) = 0;
        virtual void setUniqueId( const String& uniqueId ) = 0;
        virtual void autoGenerateUniqueIdFromName() = 0;
    };
}
