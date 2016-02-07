#include "Lyre/Private/BeatPattern.h"

namespace Lyre
{
    BeatPattern::~BeatPattern() {}
    
    BeatPattern::BeatPattern( Integer top, Integer bottom )
    :myTop( top )
    ,myBottom( bottom )
    {}
    
    BeatPattern::BeatPattern()
    :myTop( DEFAULT_TOP )
    ,myBottom( DEFAULT_BOTTOM )
    {}
    
    IBeatPatternUP BeatPattern::clone() const
    {
        return IBeatPatternUP{ new BeatPattern{ *this } };
    }
    
    std::ostream& BeatPattern::toStream( std::ostream& os ) const
    {
        return os;
    }
}
