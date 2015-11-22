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
        class DurBaseWhole;
        using DurBaseWholeSP = std::shared_ptr<DurBaseWhole>;
        using DurBaseWholeUP = std::unique_ptr<DurBaseWhole>;
        
        class DurBaseWhole : public IDurBase
        {
        public:
            virtual ~DurBaseWhole();
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
