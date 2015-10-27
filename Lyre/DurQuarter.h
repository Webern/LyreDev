//PRIVATE
#pragma once
#include "TypeDefs.h"
#include "IDur.h"
#include "Rational.h"
#include <memory>

namespace lyre
{
    namespace impl
    {
        class DurQuarter;
        using DurQuarterSP = std::shared_ptr<DurQuarter>;
        using DurQuarterUP = std::unique_ptr<DurQuarter>;
        
        class DurQuarter : public IDur
        {
        public:
            virtual ~DurQuarter();
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}
