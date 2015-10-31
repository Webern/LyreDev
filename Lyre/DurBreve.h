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
        class DurBreve;
        using DurBreveSP = std::shared_ptr<DurBreve>;
        using DurBreveUP = std::unique_ptr<DurBreve>;
        
        class DurBreve : public IDur
        {
        public:
            virtual ~DurBreve();
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}