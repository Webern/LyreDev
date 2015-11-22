//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDurBase.h"
#include "Lyre/Rational.h"
#include <memory>

namespace Lyre
{
    namespace Private
    {
        class DurBaseQuarter;
        using DurBaseQuarterSP = std::shared_ptr<DurBaseQuarter>;
        using DurBaseQuarterUP = std::unique_ptr<DurBaseQuarter>;
        
        class DurBaseQuarter : public IDurBase
        {
        public:
            virtual ~DurBaseQuarter();
            virtual IDurBaseUP clone() const;
            virtual void copyTo( IDurBaseUP& output ) const;
            
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}
