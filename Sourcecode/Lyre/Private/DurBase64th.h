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
        FORWARD_DECLARE(DurBase64th)
        
        class EXPORT_FOR_TESTS DurBase64th : public IDurBase
        {
        public:
            virtual ~DurBase64th();
            virtual Rational getValue() const;
            virtual IDurBaseUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}
