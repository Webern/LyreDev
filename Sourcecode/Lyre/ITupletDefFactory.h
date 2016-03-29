//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ITupletDef.h"

namespace Lyre
{
    FORWARD_DECLARE(ITupletDef)
    FORWARD_DECLARE(IDurDot)
    FORWARD_DECLARE(ITupletDefFactory)
    
    enum class PUBLIC TupletDefFactoryType
    {
        Standard = 0
    };
    
    ITupletDefFactoryUP PUBLIC createTupletDefFactory(
        const TupletDefFactoryType  t = TupletDefFactoryType::Standard );
    
    class PUBLIC ITupletDefFactory
    {
    public:
        virtual ~ITupletDefFactory() = default;
        
        virtual ITupletDefUP createTupletDef(
            const int noteCount,
            const String& noteTypeDurBaseName,
            const int inTheSpaceOfCount,
            const String& inTheSpaceOfTypeDurBaseName ) = 0;
        
        virtual ITupletDefUP createTupletDef(
            const int noteCount,
            const IDurDot& noteType,
            const int inTheSpaceOfCount,
            const IDurDot& inTheSpaceOfType ) = 0;
        
        virtual ITupletDefUP createTupletDef(
            const int notes,
            const int inTheSpaceOf,
            const IDurDot& durDotType ) = 0;
        
        virtual ITupletDefUP createTupletDef(
             const int notes,
             const int inTheSpaceOf,
             const String& durBaseName ) = 0;
        
    };
}
