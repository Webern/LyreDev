#include "Lyre/Private/DurationFactory.h"
#include "Lyre/Private/Duration.h"
#include "Lyre/Private/DurDot.h"
#include "Lyre/IDurDotFactory.h"
#include "Lyre/IDurDot.h"
#include "Lyre/Private/throw.h"
#include <sstream>

namespace Lyre
{
    namespace Private
    {
        DurationFactory::~DurationFactory() {}
        
        IDurationUP DurationFactory::createDuration(
            const String& durName ) const
        {
            return IDurationUP{ new Duration { durName } };
        }
        
        IDurationUP DurationFactory::createDuration(
            const String& durName,
            const int dotCount ) const
        {
            return IDurationUP{ new Duration { durName, dotCount } };
        }
        
        IDurationUP DurationFactory::createDuration(
            const VecITupletDefSPC& tuplets,
            const String& durName,
            const int dotCount ) const
        {
            return IDurationUP{ new Duration { tuplets, durName, dotCount } };
        }
    }
}
