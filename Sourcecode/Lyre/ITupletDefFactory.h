//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/ITupletDef.h"
#include <vector>
#include <memory>

namespace Lyre
{
    class ITupletDef;
    using ITupletDefSP = std::shared_ptr<ITupletDef>;
    using ITupletDefUP = std::unique_ptr<ITupletDef>;
    using ITupletDefSPC = const std::shared_ptr<const ITupletDef>;
    using ITupletDefUPC = const std::unique_ptr<const ITupletDef>;
    
    class IDurDot;
    using IDurDotSP = std::shared_ptr<IDurDot>;
    using IDurDotUP = std::unique_ptr<IDurDot>;
    using IDurDotSPC = std::shared_ptr<const IDurDot>;
    using IDurDotUPC = std::unique_ptr<const IDurDot>;
    
    class ITupletDefFactory;
    using ITupletDefFactorySP = std::shared_ptr<ITupletDefFactory>;
    using ITupletDefFactoryUP = std::unique_ptr<ITupletDefFactory>;
    using ITupletDefFactorySPC = std::shared_ptr<const ITupletDefFactory>;
    using ITupletDefFactoryUPC = std::unique_ptr<const ITupletDefFactory>;
    
    enum class TupletDefFactoryType
    {
        Standard = 0
    };
    
    ITupletDefFactoryUP createTupletDefFactory( const TupletDefFactoryType  t);
    
    class ITupletDefFactory
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
