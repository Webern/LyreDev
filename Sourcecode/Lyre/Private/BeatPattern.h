//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IBeatPattern.h"

namespace Lyre
{
    FORWARD_DECLARE(BeatPattern)
    
    class BeatPattern : public IBeatPattern
    {
    public:
        BeatPattern( Integer top, Integer bottom );
        BeatPattern();
        virtual ~BeatPattern();
        virtual IBeatPatternUP clone() const;
        virtual std::ostream& toStream( std::ostream& os ) const;
    private:
        Integer myTop;
        Integer myBottom;
    };
}
