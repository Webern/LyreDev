#include "Lyre/Private/DurationFactory.h"
#include "Lyre/Private/Duration.h"
#include "Lyre/Private/makeUnique.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        DurationFactory::~DurationFactory() {}
        
        IDurationUP DurationFactory::createDuration(
            const String& durName,
            const Integer dotCount ) const
        {
            return IDurationUP{ new Duration{ durName, dotCount } };
        }
        
        IDurationUP DurationFactory::createDuration(
            const String& durName ) const
        {
            return IDurationUP{ new Duration{ durName } };
        }
    }
}
