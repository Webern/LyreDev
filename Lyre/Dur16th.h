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
        class Dur16th;
        using Dur16thSP = std::shared_ptr<Dur16th>;
        using Dur16thUP = std::unique_ptr<Dur16th>;
        
        class Dur16th : public IDur
        {
        public:
            virtual ~Dur16th();
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}