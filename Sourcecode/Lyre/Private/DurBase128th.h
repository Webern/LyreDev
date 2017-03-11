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
        FORWARD_DECLARE(DurBase128th)
        
        class EXPORT_FOR_TESTS DurBase128th : public IDurBase
        {
        public:
            DurBase128th();
            virtual ~DurBase128th();
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
