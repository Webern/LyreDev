#include "Lyre/Private/DurBase256th.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBase256th::ourRational = Rational { 1, 64 };
        
        const String DurBase256th::ourName = "256th";
        
        DurBase256th::~DurBase256th() {}
        
        IDurBaseUP DurBase256th::clone() const
        {
            return Private::makeUnique<DurBase256th>();
        }
        
        Rational DurBase256th::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBase256th::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}
