#include "Lyre/Private/DurBase8th.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBase8th::DurBase8th()
        :myRational( 1, 2 )
        ,myName( "Eighth" )
        {}
        
        DurBase8th::~DurBase8th() {}
        
        IDurBaseUP DurBase8th::clone() const
        {
            return Private::makeUnique<DurBase8th>();
        }
        
        Rational DurBase8th::getValue() const
        {
            return myRational;
        }
        std::ostream& DurBase8th::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
