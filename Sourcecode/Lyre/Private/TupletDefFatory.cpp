#include "Lyre/Private/TupletDefFatory.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/Private/DurBaseQuarter.h"
#include "Lyre/Private/DurDot.h"
#include "Lyre/Private/TupletDef.h"

namespace Lyre
{
    namespace Private
    {
        class TempFakeTupletDef : public ITupletDef
        {
        public:
            
        };

//////////////////////////////////////////////////////////////////////
        
        ITupletDefUP TupletDefFactory::createTupletDef(
            const Integer count,
            const Lyre::IDurDot& countType,
            const Integer inTheSpaceOf,
            const Lyre::IDurDot& inTheSpaceOfType )
        {
            return ITupletDefUP{ new Private::TupletDef{ count, countType, inTheSpaceOf, inTheSpaceOfType } };
        }
        
        ITupletDefUP TupletDefFactory::createTupletDef(
            const Integer count,
            const Integer inTheSpaceOf,
            const IDurDot& durationType )
        {
            return ITupletDefUP{ new Private::TupletDef{ count, inTheSpaceOf, durationType } };
        }
        
        ITupletDefUP TupletDefFactory::createTupletDef(
           const Integer count,
           const Integer inTheSpaceOf,
           const String& durBaseName )
        {
            return ITupletDefUP{ new Private::TupletDef{ count, inTheSpaceOf, durBaseName } };
        }
    }
}
