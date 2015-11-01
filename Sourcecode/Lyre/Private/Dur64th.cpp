#include "Lyre/Private/Dur64th.h"

namespace Lyre
{
    namespace Private
    {
        const Rational Dur64th::ourRational = Rational { 1, 16 };
        
        const String Dur64th::ourName = "64th";
        
        Dur64th::~Dur64th() {}
        
        Rational Dur64th::getValue() const
        {
            return ourRational;
        }
        std::ostream& Dur64th::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}