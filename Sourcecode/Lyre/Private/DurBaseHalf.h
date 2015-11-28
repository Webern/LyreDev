//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDurBase.h"
#include "Lyre/Rational.h"
#include <memory>

namespace Lyre
{
    namespace Private
    {
        class DurBaseHalf;
        using DurBaseHalfSP = std::shared_ptr<DurBaseHalf>;
        using DurBaseHalfUP = std::unique_ptr<DurBaseHalf>;
        
        class DurBaseHalf : public IDurBase
        {
        public:
            virtual ~DurBaseHalf();
            virtual IDurBaseUP clone() const;
            virtual // void copyTo( IDurBaseUP& output ) const;
            
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}
