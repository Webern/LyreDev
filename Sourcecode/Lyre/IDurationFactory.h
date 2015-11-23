//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDuration.h"
#include <memory>

namespace Lyre
{
    enum class DurationFactoryType
    {
        Standard = 0
    };
    
    // Forward Declarations
    class IDuration;
    using IDurationSP = std::shared_ptr<IDuration>;
    using IDurationUP = std::unique_ptr<IDuration>;
    
    class IDurationFactory;
    using IDurationFactorySP = std::shared_ptr<IDurationFactory>;
    using IDurationFactoryUP = std::unique_ptr<IDurationFactory>;
    
    IDurationFactoryUP createDurationFactory( const DurationFactoryType t );

    class IDurationFactory
    {
    public:
        
        virtual ~IDurationFactory();
        
        virtual IDurationUP createDuration(
            const String& durName,
            const Integer dotCount ) const = 0;
        
        virtual IDurationUP createDuration(
            const String& durName ) const = 0;
    };
}
