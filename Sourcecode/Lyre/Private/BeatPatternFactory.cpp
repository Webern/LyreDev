#include "Lyre/Private/BeatPatternFactory.h"
#include "Lyre/IBeatPattern.h"
#include "Lyre/Private/BeatPattern.h"

#if 1==0

namespace Lyre
{
    namespace Private
    {
        BeatPatternFactory::~BeatPatternFactory() {}
        
        IBeatPatternUP BeatPatternFactory::create()
        {
            return IBeatPatternUP{ new Private::BeatPattern{} };
        }
    }
}
#endif
