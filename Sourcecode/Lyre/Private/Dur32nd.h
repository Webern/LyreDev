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
        class Dur32nd;
        using Dur32ndSP = std::shared_ptr<Dur32nd>;
        using Dur32ndUP = std::unique_ptr<Dur32nd>;
        
        class Dur32nd : public IDur
        {
        public:
            virtual ~Dur32nd();
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}