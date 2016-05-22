#include "Lyre/Private/DurBase32nd.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBase32nd::DurBase32nd()
        :myRational( VAL_32ND )
        ,myName( STR_32ND )
        {}
        
        DurBase32nd::~DurBase32nd() {}
        
        IDurBaseUP DurBase32nd::clone() const
        {
            return Private::makeUnique<DurBase32nd>();
        }
        
        Rational DurBase32nd::getValue() const
        {
            return myRational;
        }
        std::ostream& DurBase32nd::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
