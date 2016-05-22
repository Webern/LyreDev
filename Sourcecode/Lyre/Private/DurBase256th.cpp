#include "Lyre/Private/DurBase256th.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBase256th::DurBase256th()
        :myRational( VAL_256TH )
        ,myName( STR_256TH )
        {}
        
        DurBase256th::~DurBase256th() {}
        
        IDurBaseUP DurBase256th::clone() const
        {
            return Private::makeUnique<DurBase256th>();
        }
        
        Rational DurBase256th::getValue() const
        {
            return myRational;
        }
        std::ostream& DurBase256th::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
