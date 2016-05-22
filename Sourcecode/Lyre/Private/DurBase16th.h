//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IDurBase.h"
#include "Lyre/Rational.h"
#include "Lyre/DurationConstants.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(DurBase16th)
        
        class EXPORT_FOR_TESTS DurBase16th : public IDurBase
        {
        public:
            DurBase16th();
            virtual ~DurBase16th();
            virtual IDurBaseUP clone() const;
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            Rational myRational;
            String myName;
        };
    }
}
