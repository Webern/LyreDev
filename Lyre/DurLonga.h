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
        class DurLonga;
        using DurLongaSP = std::shared_ptr<DurLonga>;
        using DurLongaUP = std::unique_ptr<DurLonga>;
        
        class DurLonga : public IDur
        {
        public:
            virtual ~DurLonga();
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}