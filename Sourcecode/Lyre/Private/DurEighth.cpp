#include "Lyre/Private/DurEighth.h"

namespace Lyre
{
    namespace Private
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