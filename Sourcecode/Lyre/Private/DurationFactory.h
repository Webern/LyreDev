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
            DurationFactory( const DurationFactory& other );
            DurationFactory( DurationFactory&& other );
            DurationFactory& operator=( const DurationFactory& other );
            DurationFactory& operator=( DurationFactory&& other );
            
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
                const Rational& rational,
                bool doThrowOnBadInput = false ) const;
        
        private:
            std::map<Rational,IDurationUP> myLut;
            void createLut();
            void copyLut( const std::map<Rational,IDurationUP>& other );
            IDurationUP find( const Rational& r, bool doThrow ) const;
        };
    }
}
