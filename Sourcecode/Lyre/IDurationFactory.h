//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IDuration.h"
#include "Lyre/ITupletDef.h"

namespace Lyre
{
    enum class PUBLIC DurationFactoryType
    {
        Standard = 0
    };
    
    FORWARD_DECLARE(IDurationFactory)
    
    IDurationFactoryUP PUBLIC createDurationFactory( const DurationFactoryType t );

    class PUBLIC IDurationFactory
    {
    public:
        
        virtual ~IDurationFactory();
        
        virtual IDurationUP createDuration(
            const String& durName ) const = 0;
        
        virtual IDurationUP createDuration(
            const String& durName,
            const int dotCount ) const = 0;
        
        virtual IDurationUP createDuration(
            const VecITupletDefSPC& tuplets,
            const String& durName,
            const int dotCount ) const = 0;
    };
}
