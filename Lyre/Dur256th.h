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
        class Dur256th;
        using Dur256thSP = std::shared_ptr<Dur256th>;
        using Dur256thUP = std::unique_ptr<Dur256th>;
        
        class Dur256th : public IDur
        {
        public:
            virtual ~Dur256th();
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}