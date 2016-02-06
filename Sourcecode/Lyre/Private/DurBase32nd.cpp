#include "Lyre/Private/DurBase32nd.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBase32nd::ourRational = Rational { 1, 8 };
        
        const String DurBase32nd::ourName = "32nd";
        
        DurBase32nd::~DurBase32nd() {}
        
        IDurBaseUP DurBase32nd::clone() const
        {
            return Private::makeUnique<DurBase32nd>();
        }
        
        Rational DurBase32nd::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBase32nd::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}
