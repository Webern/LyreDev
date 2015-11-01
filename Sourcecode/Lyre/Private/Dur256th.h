//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDur.h"
#include "Lyre/Rational.h"
#include <memory>

namespace Lyre
{
    namespace Private
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