//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDuration.h"
#include "Lyre/ITupletDef.h"
#include <memory>

namespace Lyre
{
    enum class DurationFactoryType
    {
        Standard = 0
    };
    
    class IDurationFactory;
    using IDurationFactorySP = std::shared_ptr<IDurationFactory>;
    using IDurationFactoryUP = std::unique_ptr<IDurationFactory>;
    
    IDurationFactoryUP createDurationFactory( const DurationFactoryType t );

    class IDurationFactory
    {
    public:
        
        virtual ~IDurationFactory();
        
        virtual IDurationUP createDuration(
            const String& durName ) const = 0;
        
        virtual IDurationUP createDuration(
            const String& durName,
            const Integer dotCount ) const = 0;
        
        virtual IDurationUP createDuration(
            const ITupletDefSPCs& tuplets,
            const String& durName,
            const Integer dotCount ) const = 0;
    };
}
