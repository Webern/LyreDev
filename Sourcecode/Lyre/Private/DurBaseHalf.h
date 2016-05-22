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
        FORWARD_DECLARE(DurBaseHalf)
        
        class EXPORT_FOR_TESTS DurBaseHalf : public IDurBase
        {
        public:
            DurBaseHalf();
            virtual ~DurBaseHalf();
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
