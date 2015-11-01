#include "Lyre/Private/DurLonga.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurLonga::ourRational = Rational { 16, 1 };
        
        const String DurLonga::ourName = "Longa";
        
        DurLonga::~DurLonga() {}
        
        Rational DurLonga::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurLonga::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}