#include "DurWhole.h"

namespace lyre
{
    namespace impl
    {
        const Rational DurWhole::ourRational = Rational { 4, 1 };
        
        const String DurWhole::ourName = "Whole";
        
        DurWhole::~DurWhole() {}
        
        Rational DurWhole::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurWhole::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}