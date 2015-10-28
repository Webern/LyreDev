#include "Dur16th.h"

namespace lyre
{
    namespace impl
    {
        const Rational Dur16th::ourRational = Rational { 1, 4 };
        
        const String Dur16th::ourName = "16th";
        
        Dur16th::~Dur16th() {}
        
        Rational Dur16th::getValue() const
        {
            return ourRational;
        }
        std::ostream& Dur16th::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}