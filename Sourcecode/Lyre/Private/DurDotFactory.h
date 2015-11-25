//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDurDotFactory.h"
#include <memory>
#include <map>

namespace Lyre
{
    namespace Private
    {
        class DurDotFactory;
        using DurDotFactorySP = std::shared_ptr<DurDotFactory>;
        using DurDotFactoryUP = std::unique_ptr<DurDotFactory>;
        
        class DurDotFactory : public IDurDotFactory
        {
        public:
            virtual ~DurDotFactory();
            
            virtual IDurDotUP createDurDot(
                const String& durName,
                const Integer dotCount ) const;
            
            virtual IDurDotUP createDurDot(
                const String& durName ) const;
        };
    }
}
