//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/Private/DurDot.h"
#include <memory>

namespace Lyre
{
    namespace Private
    {
        class TupletDef : public ITupletDef
        {
        public:
            
            TupletDef(
                const Integer noteCount,
                const String& noteTypeDurBaseName,
                const Integer inTheSpaceOfCount,
                const String& inTheSpaceOfTypeDurBaseName );
            
            TupletDef(
                const Integer count,
                const Lyre::IDurDot& countType,
                const Integer inTheSpaceOf,
                const Lyre::IDurDot& inTheSpaceOfType );
            
            TupletDef(
                const Integer count,
                const Integer inTheSpaceOf,
                const IDurDot& durationType );
            
            TupletDef(
                const Integer count,
                const Integer inTheSpaceOf,
                const String& durBaseName );
            
            virtual ~TupletDef() = default;
            
            virtual ITupletDefUP clone() const;
            
            virtual Rational getMultiplier() const;
            virtual Rational getTotalLength() const;
            
            virtual Integer getCount() const;
            virtual IDurDotUPC getCountType() const;
            
            virtual Integer getInTheSpaceOf() const;
            virtual IDurDotUPC getInTheSpaceOfType() const;
            
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            virtual String toString() const;
            
            virtual bool getIsValid() const;
            
        private:
            Integer myCount;
            IDurDotUP myCountType;
            Integer myInTheSpaceOf;
            IDurDotUP myInTheSpaceOfType;
            
        private:
            void throwIfNonPositive( const Integer value ) const;
            void throwIfNull( const IDurDotUP& up ) const;
            void nullCheckThrow() const;
            void constructor(
                const Integer count,
                const String& countTypeName,
                const Integer countTypeDots,
                const Integer itso,
                const String& itsoType,
                const Integer itsoDots );
        };
    }
}
