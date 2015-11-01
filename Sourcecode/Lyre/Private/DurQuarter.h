//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDur.h"
#include "Lyre/Rational.h"
#include <memory>

namespace Lyre
{
    namespace Private
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