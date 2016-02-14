//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IDurBase.h"
#include "Lyre/Rational.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(DurBase256th)
        
        class EXPORT_FOR_TESTS DurBase256th : public IDurBase
        {
        public:
            DurBase256th();
            virtual ~DurBase256th();
            virtual IDurBaseUP clone() const;
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            Rational myRational;
            String myName;
        };
    }
}
