#include "Lyre/Private/DurBaseLonga.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBaseLonga::ourRational = Rational { 16, 1 };
        
        const String DurBaseLonga::ourName = "Longa";
        
        DurBaseLonga::~DurBaseLonga() {}
        
        Rational DurBaseLonga::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBaseLonga::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}