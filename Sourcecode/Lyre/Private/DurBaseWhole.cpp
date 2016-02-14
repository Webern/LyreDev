#include "Lyre/Private/DurBaseWhole.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBaseWhole::DurBaseWhole()
        :myRational( 4, 1 )
        ,myName( "Whole" )
        {}
        
        DurBaseWhole::~DurBaseWhole() {}
        
        IDurBaseUP DurBaseWhole::clone() const
        {
            return Private::makeUnique<DurBaseWhole>();
        }
        
        Rational DurBaseWhole::getValue() const
        {
            return myRational;
        }
        std::ostream& DurBaseWhole::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
