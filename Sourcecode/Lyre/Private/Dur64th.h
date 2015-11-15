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
        class Dur64th;
        using Dur64thSP = std::shared_ptr<Dur64th>;
        using Dur64thUP = std::unique_ptr<Dur64th>;
        
        class Dur64th : public IDurBase
        {
        public:
            virtual ~Dur64th();
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}