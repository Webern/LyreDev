//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDurDotFactory.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(DurDotFactory)
        
        class EXPORT_FOR_TESTS DurDotFactory : public IDurDotFactory
        {
        public:
            virtual ~DurDotFactory();
            
            virtual IDurDotUP createDurDot(
                const String& durName,
                const Integer dotCount ) const;
            
            virtual IDurDotUP createDurDot(
                const String& durName ) const;
            
            virtual IDurDotUP createDurDot() const;
        };
    }
}
