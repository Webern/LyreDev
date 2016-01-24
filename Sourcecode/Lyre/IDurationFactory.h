//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDuration.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    enum class DurationFactoryType
    {
        Standard = 0
    };
    
    FORWARD_DECLARE(IDurationFactory)
    
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
            const VecITupletDefSPC& tuplets,
            const String& durName,
            const Integer dotCount ) const = 0;
    };
}
