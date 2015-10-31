//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDur.h"
#include "Lyre/Rational.h"
#include <memory>

namespace lyre
{
    namespace impl
    {
        class DurHalf;
        using DurHalfSP = std::shared_ptr<DurHalf>;
        using DurHalfUP = std::unique_ptr<DurHalf>;
        
        class DurHalf : public IDur
        {
        public:
            virtual ~DurHalf();
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}