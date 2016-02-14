//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/Private/DurDot.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(TupletDef)
        
        class EXPORT_FOR_TESTS TupletDef : public ITupletDef
        {
        public:
            
            TupletDef(
                const int noteCount,
                const String& noteTypeDurBaseName,
                const int inTheSpaceOfCount,
                const String& inTheSpaceOfTypeDurBaseName );
            
            TupletDef(
                const int count,
                const Lyre::IDurDot& countType,
                const int inTheSpaceOf,
                const Lyre::IDurDot& inTheSpaceOfType );
            
            TupletDef(
                const int count,
                const int inTheSpaceOf,
                const IDurDot& durationType );
            
            TupletDef(
                const int count,
                const int inTheSpaceOf,
                const String& durBaseName );
            
            virtual ~TupletDef() = default;
            
            virtual ITupletDefUP clone() const;
            
            virtual Rational getMultiplier() const;
            virtual Rational getTotalLength() const;
            
            virtual int getCount() const;
            virtual IDurDotUPC getCountType() const;
            
            virtual int getInTheSpaceOf() const;
            virtual IDurDotUPC getInTheSpaceOfType() const;
            
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            virtual String toString() const;
            
            virtual bool getIsValid() const;
            
        private:
            int myCount;
            IDurDotUP myCountType;
            int myInTheSpaceOf;
            IDurDotUP myInTheSpaceOfType;
            
        private:
            void throwIfNonPositive( const int value ) const;
            void throwIfNull( const IDurDotUP& up ) const;
            void nullCheckThrow() const;
            void constructor(
                const int count,
                const String& countTypeName,
                const int countTypeDots,
                const int itso,
                const String& itsoType,
                const int itsoDots );
        };
    }
}
