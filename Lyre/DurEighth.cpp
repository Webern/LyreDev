#include "Lyre/DurEighth.h"

namespace lyre
{
    namespace impl
    {
        const Rational DurEighth::ourRational = Rational { 1, 2 };
        
        const String DurEighth::ourName = "Eighth";
        
        DurEighth::~DurEighth() {}
        
        Rational DurEighth::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurEighth::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}