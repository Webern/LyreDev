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
        FORWARD_DECLARE(DurBase64th)
        
        class EXPORT_FOR_TESTS DurBase64th : public IDurBase
        {
        public:
            DurBase64th();
            virtual ~DurBase64th();
            virtual Rational getValue() const;
            virtual IDurBaseUP clone() const;
            virtual int getMaxBeams() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            Rational myRational;
            String myName;
            int myMaxBeams;
        };
    }
}
