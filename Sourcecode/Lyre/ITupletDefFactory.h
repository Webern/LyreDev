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
            const String& inTheSpaceOfTypeDurBaseName ) const = 0;
        
        virtual ITupletDefUP createTupletDef(
            const int noteCount,
            const IDurDot& noteType,
            const int inTheSpaceOfCount,
            const IDurDot& inTheSpaceOfType ) const = 0;
        
        virtual ITupletDefUP createTupletDef(
            const int notes,
            const int inTheSpaceOf,
            const IDurDot& durDotType ) const = 0;
        
        virtual ITupletDefUP createTupletDef(
             const int notes,
             const int inTheSpaceOf,
             const String& durBaseName ) const = 0;
        
    };
}
