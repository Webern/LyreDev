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
        class Dur128th;
        using Dur128thSP = std::shared_ptr<Dur128th>;
        using Dur128thUP = std::unique_ptr<Dur128th>;
        
        class Dur128th : public IDur
        {
        public:
            virtual ~Dur128th();
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}