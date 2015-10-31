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
        class DurWhole;
        using DurWholeSP = std::shared_ptr<DurWhole>;
        using DurWholeUP = std::unique_ptr<DurWhole>;
        
        class DurWhole : public IDur
        {
        public:
            virtual ~DurWhole();
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}