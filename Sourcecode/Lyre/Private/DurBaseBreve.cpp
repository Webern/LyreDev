#include "Lyre/Private/DurBaseBreve.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBaseBreve::ourRational = Rational { 8, 1 };
        
        const String DurBaseBreve::ourName = "Breve";
        
        DurBaseBreve::~DurBaseBreve() {}
        
        Rational DurBaseBreve::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBaseBreve::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}