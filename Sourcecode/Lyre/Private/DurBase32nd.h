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
        FORWARD_DECLARE(DurBase32nd)
        
        class EXPORT_FOR_TESTS DurBase32nd : public IDurBase
        {
        public:
            DurBase32nd();
            virtual ~DurBase32nd();
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
