//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    FORWARD_DECLARE(ITupletDef)
    FORWARD_DECLARE(IDurDot)
    FORWARD_DECLARE(ITupletDefFactory)
    
    enum class PUBLIC TupletDefFactoryType
    {
        Standard = 0
    };
    
    ITupletDefFactoryUP PUBLIC createTupletDefFactory( const TupletDefFactoryType  t);
    
    class PUBLIC ITupletDefFactory
    {
    public:
        virtual ~ITupletDefFactory() = default;
        
        virtual ITupletDefUP createTupletDef(
            const Integer noteCount,
            const String& noteTypeDurBaseName,
            const Integer inTheSpaceOfCount,
            const String& inTheSpaceOfTypeDurBaseName ) = 0;
        
        virtual ITupletDefUP createTupletDef(
            const Integer noteCount,
            const IDurDot& noteType,
            const Integer inTheSpaceOfCount,
            const IDurDot& inTheSpaceOfType ) = 0;
        
        virtual ITupletDefUP createTupletDef(
            const Integer notes,
            const Integer inTheSpaceOf,
            const IDurDot& durDotType ) = 0;
        
        virtual ITupletDefUP createTupletDef(
             const Integer notes,
             const Integer inTheSpaceOf,
             const String& durBaseName ) = 0;
        
    };
}
