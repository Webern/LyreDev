//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(IScore)
    
    class PUBLIC IScore : public IStreamable
    {
    public:
        virtual ~IScore() {};
        virtual IScoreUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
    };
}
