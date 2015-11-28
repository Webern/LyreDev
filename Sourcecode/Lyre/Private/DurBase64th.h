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
        class DurBase64th;
        using DurBase64thSP = std::shared_ptr<DurBase64th>;
        using DurBase64thUP = std::unique_ptr<DurBase64th>;
        
        class DurBase64th : public IDurBase
        {
        public:
            virtual ~DurBase64th();
            virtual Rational getValue() const;
            virtual IDurBaseUP clone() const;
            virtual // void copyTo( IDurBaseUP& output ) const;
            
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}
