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
        FORWARD_DECLARE(DurBaseQuarter)
        
        class EXPORT_FOR_TESTS DurBaseQuarter : public IDurBase
        {
        public:
            DurBaseQuarter();
            virtual ~DurBaseQuarter();
            virtual IDurBaseUP clone() const;
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            Rational myRational;
            String myName;
        };
    }
}
