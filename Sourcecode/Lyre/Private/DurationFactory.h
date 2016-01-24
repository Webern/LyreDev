//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(DurationFactory)
        
        class DurationFactory : public IDurationFactory
        {
        public:
            virtual ~DurationFactory();
            
            virtual IDurationUP createDuration(
                const String& durName ) const;
            
            virtual IDurationUP createDuration(
                const String& durName,
                const Integer dotCount ) const;
            
            virtual IDurationUP createDuration(
                const VecITupletDefSPC& tuplets,
                const String& durName,
                const Integer dotCount ) const;
        };
    }
}
