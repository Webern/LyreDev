#include "Lyre/Private/BeatPatternFactory.h"
#include "Lyre/IBeatPattern.h"
#include "Lyre/Private/BeatPattern.h"


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
