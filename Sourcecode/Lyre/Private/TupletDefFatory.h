//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/ITupletDefFactory.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(TupletDefFactory)
        
        class TupletDefFactory : public ITupletDefFactory
        {
        public:
            virtual ~TupletDefFactory() = default;
            
            virtual ITupletDefUP createTupletDef(
                const Integer noteCount,
                const String& noteTypeDurBaseName,
                const Integer inTheSpaceOfCount,
                const String& inTheSpaceOfTypeDurBaseName );
            
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
