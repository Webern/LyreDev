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
            DurBaseLonga();
            virtual ~DurBaseLonga();
            virtual IDurBaseUP clone() const;
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            Rational myRational;
            String myName;
        };
    }
}
