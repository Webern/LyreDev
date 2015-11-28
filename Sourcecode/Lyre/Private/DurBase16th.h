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
        class DurBase16th;
        using DurBase16thSP = std::shared_ptr<DurBase16th>;
        using DurBase16thUP = std::unique_ptr<DurBase16th>;
        
        class DurBase16th : public IDurBase
        {
        public:
            virtual ~DurBase16th();
            virtual IDurBaseUP clone() const;
            virtual // void copyTo( IDurBaseUP& output ) const;
            
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}
