#include "Lyre/Private/DurBaseLonga.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBaseLonga::DurBaseLonga()
        :myRational( VAL_LONGA )
        ,myName( STR_LONGA )
        {}
        
        DurBaseLonga::~DurBaseLonga() {}
        
        IDurBaseUP DurBaseLonga::clone() const
        {
            return Private::makeUnique<DurBaseLonga>();
        }
        
        Rational DurBaseLonga::getValue() const
        {
            return myRational;
        }
        std::ostream& DurBaseLonga::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
