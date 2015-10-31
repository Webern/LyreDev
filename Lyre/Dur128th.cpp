#include "Lyre/Dur128th.h"

namespace lyre
{
    namespace impl
    {
        const Rational Dur128th::ourRational = Rational { 1, 32 };
        
        const String Dur128th::ourName = "128th";
        
        Dur128th::~Dur128th() {}
        
        Rational Dur128th::getValue() const
        {
            return ourRational;
        }
        std::ostream& Dur128th::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}