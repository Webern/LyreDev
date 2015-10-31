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
        class DurEighth;
        using DurEighthSP = std::shared_ptr<DurEighth>;
        using DurEighthUP = std::unique_ptr<DurEighth>;
        
        class DurEighth : public IDur
        {
        public:
            virtual ~DurEighth();
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}