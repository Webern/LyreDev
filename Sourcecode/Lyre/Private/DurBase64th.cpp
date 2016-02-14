#include "Lyre/Private/DurBase64th.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBase64th::DurBase64th()
        :myRational( 1, 16 )
        ,myName( "64th" )
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
