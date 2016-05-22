#include "Lyre/Private/DurBaseEighth.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBaseEighth::DurBaseEighth()
        :myRational( VAL_EIGHTH )
        ,myName( STR_EIGHTH )
        {}
        
        DurBaseEighth::~DurBaseEighth() {}
        
        IDurBaseUP DurBaseEighth::clone() const
        {
            return Private::makeUnique<DurBaseEighth>();
        }
        
        Rational DurBaseEighth::getValue() const
        {
            return myRational;
        }
        std::ostream& DurBaseEighth::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
