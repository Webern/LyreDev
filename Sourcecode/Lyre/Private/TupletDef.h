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
            virtual ~TupletDef() = default;
            
            virtual ITupletDefUP clone() const ;
            
            virtual void copyTo( ITupletDefUP& output ) const;
            
            virtual Rational getMultiplier() const ;
            virtual Rational getTotalLength() const ;
            
            virtual Integer getCount() const ;
            virtual IDurDotUPC getCountType() const ;
            
            virtual Integer getInTheSpaceOf() const ;
            virtual IDurDotUPC getInTheSpaceOfType() const ;
            
            virtual std::ostream& toStream( std::ostream& os ) const ;
            
            virtual String toString() const ;
        private:
            Integer myCount;
            DurDot myCountType;
            Integer myInTheSpaceOf;
            DurDot myInTheSpaceOfType;
        };
    }
}
