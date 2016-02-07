#include "Lyre/Private/BeatPatternFactory.h"
#include "Lyre/IBeatPattern.h"
#include "Lyre/Private/BeatPattern.h"


namespace Lyre
{
    namespace Private
    {
        BeatPatternFactory::~BeatPatternFactory() {}
        
        IBeatPatternUP BeatPatternFactory::create(
            Integer top,
            Integer bottom )
        {
            return IBeatPatternUP{ new BeatPattern{ top, bottom } };
        }
    }
}
