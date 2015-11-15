#include "Lyre/Private/DurBase64th.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBase64th::ourRational = Rational { 1, 16 };
        
        const String DurBase64th::ourName = "64th";
        
        DurBase64th::~DurBase64th() {}
        
        Rational DurBase64th::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBase64th::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}