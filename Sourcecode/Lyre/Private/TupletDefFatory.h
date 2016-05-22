//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ITupletDefFactory.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(TupletDefFactory)
        
        class EXPORT_FOR_TESTS TupletDefFactory : public ITupletDefFactory
        {
        public:
            virtual ~TupletDefFactory() = default;
            
            virtual ITupletDefUP createTupletDef(
                const int noteCount,
                const String& noteTypeDurBaseName,
                const int inTheSpaceOfCount,
                const String& inTheSpaceOfTypeDurBaseName ) const;
            
            virtual ITupletDefUP createTupletDef(
                const int countCount,
                const IDurDot& countType,
                const int inTheSpaceOf,
                const IDurDot& inTheSpaceOfType ) const;
            
            virtual ITupletDefUP createTupletDef(
                const int count,
                const int inTheSpaceOf,
                const IDurDot& durationType ) const;
            
            virtual ITupletDefUP createTupletDef(
                const int count,
                const int inTheSpaceOf,
                const String& durBaseName ) const;
        };
    }
}
