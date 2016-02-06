//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/IDurationFactory.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(DurationFactory)
        
        class EXPORT_FOR_TESTS DurationFactory : public IDurationFactory
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
