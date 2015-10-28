#include "DurHalf.h"

namespace lyre
{
    namespace impl
    {
        const Rational DurHalf::ourRational = Rational { 2, 1 };
        
        const String DurHalf::ourName = "Half";
        
        DurHalf::~DurHalf() {}
        
        Rational DurHalf::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurHalf::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}