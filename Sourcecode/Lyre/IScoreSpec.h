//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(IScoreSpec)
    
    class PUBLIC IScoreSpec : public IStreamable
    {
    public:
        virtual ~IScoreSpec() {};
        virtual IScoreSpecUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
    };
}
