//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/IDurationFactory.h"
#include <map>

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(DurationFactory)
        
        class EXPORT_FOR_TESTS DurationFactory : public IDurationFactory
        {
            
        public:
            virtual ~DurationFactory();
            DurationFactory();
            
            virtual IDurationUP createDuration(
                const String& durName ) const;
            
            virtual IDurationUP createDuration(
                const String& durName,
                const int dotCount ) const;
            
            virtual IDurationUP createDuration(
                const VecITupletDefSPC& tuplets,
                const String& durName,
                const int dotCount ) const;
            
            virtual IDurationUP createDuration(
                const ITupletDefUP& tupletDef,
                const String& durName,
                const int dotCount ) const;
            
            virtual IDurationUP createDuration(
                const Rational& rational,
                bool doThrowOnBadInput = false ) const;
        
        private:
            IDurationUP find( const Rational& r, bool doThrow ) const;
        };
    }
}
