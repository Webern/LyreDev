//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(IPart)
    
    static const int DEFAULT_TOP = 4;
    static const int DEFAULT_BOTTOM = 4;
    
    class PUBLIC IPart : public IStreamable
    {
    public:
        virtual ~IPart() {};
        virtual IPartUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
    };
}
