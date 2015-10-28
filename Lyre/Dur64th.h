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
        class Dur64th;
        using Dur64thSP = std::shared_ptr<Dur64th>;
        using Dur64thUP = std::unique_ptr<Dur64th>;
        
        class Dur64th : public IDur
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