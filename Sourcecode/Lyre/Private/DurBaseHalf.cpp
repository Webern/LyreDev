#include "Lyre/Private/DurBaseHalf.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBaseHalf::ourRational = Rational { 2, 1 };
        
        const String DurBaseHalf::ourName = "Half";
        
        DurBaseHalf::~DurBaseHalf() {}
        
        Rational DurBaseHalf::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBaseHalf::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}