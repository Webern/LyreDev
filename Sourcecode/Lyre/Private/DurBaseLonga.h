//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IDurBase.h"
#include "Lyre/Rational.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(DurBaseLonga)
        
        class EXPORT_FOR_TESTS DurBaseLonga : public IDurBase
        {
        public:
            virtual ~DurBaseLonga();
            virtual IDurBaseUP clone() const;
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}
