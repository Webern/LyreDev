#include "Lyre/Private/DurBase128th.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBase128th::DurBase128th()
        :myRational( 1, 32 )
        ,myName( "128th" )
        {}
        
        DurBase128th::~DurBase128th() {}
        
        IDurBaseUP DurBase128th::clone() const
        {
            return Private::makeUnique<DurBase128th>();
        }
        
        Rational DurBase128th::getValue() const
        {
            return myRational;
        }
        std::ostream& DurBase128th::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
