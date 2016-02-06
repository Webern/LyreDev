#include "Lyre/Private/DurBaseLonga.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBaseLonga::ourRational = Rational { 16, 1 };
        
        const String DurBaseLonga::ourName = "Longa";
        
        DurBaseLonga::~DurBaseLonga() {}
        
        IDurBaseUP DurBaseLonga::clone() const
        {
            return Private::makeUnique<DurBaseLonga>();
        }
        
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
