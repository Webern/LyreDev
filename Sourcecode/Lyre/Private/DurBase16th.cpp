#include "Lyre/Private/DurBase16th.h"
#include "Lyre/Private/makeUnique.h"
#include "Lyre/IDurBase.h"

namespace Lyre
{
    namespace Private
    {
        DurBase16th::DurBase16th()
        :myRational( 1, 4 )
        ,myName( "16th" )
        {}
        
        DurBase16th::~DurBase16th() {}
        
        IDurBaseUP DurBase16th::clone() const
        {
            return Private::makeUnique<DurBase16th>();
        }
        
        Rational DurBase16th::getValue() const
        {
            return myRational;
        }
        std::ostream& DurBase16th::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
