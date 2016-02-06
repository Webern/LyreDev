//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDurBase.h"
#include "Lyre/Rational.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(DurBaseQuarter)
        
        class DurBaseQuarter : public IDurBase
        {
        public:
            virtual ~DurBaseQuarter();
            virtual IDurBaseUP clone() const;
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}
