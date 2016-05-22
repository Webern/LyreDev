#include "Lyre/Private/TupletDefFatory.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/Private/DurBaseQuarter.h"
#include "Lyre/Private/DurDot.h"
#include "Lyre/Private/TupletDef.h"

namespace Lyre
{
    namespace Private
    {
        ITupletDefUP TupletDefFactory::createTupletDef(
            const int count,
            const String& noteTypeDurBaseName,
            const int inTheSpaceOf,
            const String& inTheSpaceOfTypeDurBaseName ) const
        {
            return ITupletDefUP{ new Private::TupletDef{ count, noteTypeDurBaseName, inTheSpaceOf, inTheSpaceOfTypeDurBaseName } };
        }
        
        ITupletDefUP TupletDefFactory::createTupletDef(
            const int count,
            const Lyre::IDurDot& countType,
            const int inTheSpaceOf,
            const Lyre::IDurDot& inTheSpaceOfType ) const
        {
            return ITupletDefUP{ new Private::TupletDef{ count, countType, inTheSpaceOf, inTheSpaceOfType } };
        }
        
        ITupletDefUP TupletDefFactory::createTupletDef(
            const int count,
            const int inTheSpaceOf,
            const IDurDot& durationType ) const
        {
            return ITupletDefUP{ new Private::TupletDef{ count, inTheSpaceOf, durationType } };
        }
        
        ITupletDefUP TupletDefFactory::createTupletDef(
           const int count,
           const int inTheSpaceOf,
           const String& durBaseName ) const
        {
            return ITupletDefUP{ new Private::TupletDef{ count, inTheSpaceOf, durBaseName } };
        }
    }
}
