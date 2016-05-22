#include "Lyre/Private/DurBaseHalf.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBaseHalf::DurBaseHalf()
        :myRational( VAL_HALF )
        ,myName( STR_HALF )
        {}
        
        DurBaseHalf::~DurBaseHalf() {}
        
        IDurBaseUP DurBaseHalf::clone() const
        {
            return Private::makeUnique<DurBaseHalf>();
        }
        
        Rational DurBaseHalf::getValue() const
        {
            return myRational;
        }
        std::ostream& DurBaseHalf::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
