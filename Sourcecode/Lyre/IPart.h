//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(IPart)
    
    class PUBLIC IPart : public IStreamable
    {
    public:
        virtual ~IPart() {};
        virtual IPartUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
    };
}
