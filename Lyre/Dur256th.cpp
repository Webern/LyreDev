#include "Dur256th.h"

namespace lyre
{
    namespace impl
    {
        const Rational Dur256th::ourRational = Rational { 1, 64 };
        
        const String Dur256th::ourName = "256th";
        
        Dur256th::~Dur256th() {}
        
        Rational Dur256th::getValue() const
        {
            return ourRational;
        }
        std::ostream& Dur256th::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}