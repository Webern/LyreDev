//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDurationFactory.h"
#include <memory>
#include <map>

namespace Lyre
{
    namespace Private
    {
        class DurationFactory;
        using DurationFactorySP = std::shared_ptr<DurationFactory>;
        using DurationFactoryUP = std::unique_ptr<DurationFactory>;
        
        class DurationFactory : public IDurationFactory
        {
        public:
            virtual ~DurationFactory();
            
            virtual IDurationUP createDuration(
                const String& durName,
                const Integer dotCount ) const;
            
            virtual IDurationUP createDuration(
                const String& durName ) const;
        };
    }
}
