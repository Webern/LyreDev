//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/IDurationFactory.h"
#include <memory>

namespace Lyre
{
    namespace Private
    {
        class DurationFactory : public IDurationFactory
        {
        public:
            virtual ~DurationFactory() = default;
            
            virtual IDurationUP createDuration(
                const String& durName ) const;
            
            virtual IDurationUP createDuration(
                const String& durName,
                const Integer dotCount ) const;
            
            virtual IDurationUP createDuration(
                const ITupletDefSPCs& tuplets,
                const String& durName,
                const Integer dotCount ) const;
        };
    }
}
