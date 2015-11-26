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
                const Integer numeratorCount,
                const IDurDot& numeratorType,
                const Integer noteCountXXXX,
                const IDurDot& denomintorType );
            
            virtual ITupletDefUP createTupletDef(
                const Integer numerator,
                const Integer denominator,
                const IDurDot& durationType );
            
            virtual ITupletDefUP createTupletDef(
                const Integer numerator,
                const Integer denominator,
                const String& durBaseName );
        };

    }
}
