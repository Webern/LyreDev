#include "Lyre/Private/BeatPatternFactory.h"
#include "Lyre/IBeatPattern.h"
#include "Lyre/Private/BeatPattern.h"

namespace Lyre
{
    namespace Private
    {
        BeatPatternFactory::~BeatPatternFactory() {}
        
        IBeatPatternUP BeatPatternFactory::create( int count,
                                                   const IDurationUP& dur ) const
        {
            return IBeatPatternUP{ new Private::BeatPattern{ count, dur } };
        }
        
        IBeatPatternUP BeatPatternFactory::create( const VecIDurationUP& durations ) const
        {
            return IBeatPatternUP{ new Private::BeatPattern{ durations } };
        }
    }
}

