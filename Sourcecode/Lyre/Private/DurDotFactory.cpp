#include "Lyre/Private/DurDotFactory.h"
#include "Lyre/Private/DurDot.h"
#include "Lyre/Private/makeUnique.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        DurDotFactory::~DurDotFactory() {}
        
        IDurDotUP DurDotFactory::createDurDot(
            const String& durName,
            const Integer dotCount ) const
        {
            return IDurDotUP{ new DurDot{ durName, dotCount } };
        }
        
        IDurDotUP DurDotFactory::createDurDot(
            const String& durName ) const
        {
            return IDurDotUP{ new DurDot{ durName } };
        }
        
        IDurDotUP DurDotFactory::createDurDot() const
        {
            return IDurDotUP{ new DurDot{} };
        }
    }
}
