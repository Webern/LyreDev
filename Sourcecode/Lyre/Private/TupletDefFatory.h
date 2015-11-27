//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/ITupletDefFactory.h"
#include <memory>

namespace Lyre
{
    namespace Private
    {
        class TupletDefFactory : public ITupletDefFactory
        {
        public:
            virtual ~TupletDefFactory() = default;
            
            virtual ITupletDefUP createTupletDef(
                const Integer countCount,
                const IDurDot& countType,
                const Integer inTheSpaceOf,
                const IDurDot& inTheSpaceOfType );
            
            virtual ITupletDefUP createTupletDef(
                const Integer count,
                const Integer inTheSpaceOf,
                const IDurDot& durationType );
            
            virtual ITupletDefUP createTupletDef(
                const Integer count,
                const Integer inTheSpaceOf,
                const String& durBaseName );
        };

    }
}
