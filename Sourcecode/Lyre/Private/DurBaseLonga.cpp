#include "Lyre/Private/DurBaseLonga.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBaseLonga::DurBaseLonga()
        :myRational( VAL_LONGA )
        ,myName( STR_LONGA )
        ,myMaxBeams( DUR_MAX_BEAMS_LONGA )
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
        
        int DurBaseLonga::getMaxBeams() const
        {
            return myMaxBeams;
        }
        
        std::ostream& DurBaseLonga::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
