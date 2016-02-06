#include "Lyre/Private/DurBaseWhole.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBaseWhole::ourRational = Rational { 4, 1 };
        
        const String DurBaseWhole::ourName = "Whole";
        
        DurBaseWhole::~DurBaseWhole() {}
        
        IDurBaseUP DurBaseWhole::clone() const
        {
            return Private::makeUnique<DurBaseWhole>();
        }
        
        Rational DurBaseWhole::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBaseWhole::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}
