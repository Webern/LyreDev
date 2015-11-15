#include "Lyre/Private/DurBase16th.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBase16th::ourRational = Rational { 1, 4 };
        
        const String DurBase16th::ourName = "16th";
        
        DurBase16th::~DurBase16th() {}
        
        Rational DurBase16th::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBase16th::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}