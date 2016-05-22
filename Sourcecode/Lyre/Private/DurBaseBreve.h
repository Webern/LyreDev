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
        FORWARD_DECLARE(DurBaseBreve)
        
        class EXPORT_FOR_TESTS DurBaseBreve : public IDurBase
        {
        public:
            DurBaseBreve();
            virtual ~DurBaseBreve();
            virtual IDurBaseUP clone() const;
            virtual Rational getValue() const;
            virtual int getMaxBeams() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            Rational myRational;
            String myName;
            int myMaxBeams;
        };
    }
}
