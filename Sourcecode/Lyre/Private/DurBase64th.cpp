#include "Lyre/Private/DurBase64th.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBase64th::DurBase64th()
        :myRational( VAL_64TH )
        ,myName( STR_64TH )
        {}
        
        DurBase64th::~DurBase64th() {}
        
        IDurBaseUP DurBase64th::clone() const
        {
            return Private::makeUnique<DurBase64th>();
        }
        
        Rational DurBase64th::getValue() const
        {
            return myRational;
        }
        std::ostream& DurBase64th::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
