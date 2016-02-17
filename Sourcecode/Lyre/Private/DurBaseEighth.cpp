#include "Lyre/Private/DurBaseEighth.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBaseEighth::DurBaseEighth()
        :myRational( 1, 2 )
        ,myName( "Eighth" )
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
