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
        class DurBase128th;
        using DurBase128thSP = std::shared_ptr<DurBase128th>;
        using DurBase128thUP = std::unique_ptr<DurBase128th>;
        
        class DurBase128th : public IDurBase
        {
        public:
            virtual ~DurBase128th();
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