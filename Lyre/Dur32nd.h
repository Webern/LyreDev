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