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
        class DurBase256th;
        using DurBase256thSP = std::shared_ptr<DurBase256th>;
        using DurBase256thUP = std::unique_ptr<DurBase256th>;
        
        class DurBase256th : public IDurBase
        {
        public:
            virtual ~DurBase256th();
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