#include "Lyre/Private/DurBaseBreve.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBaseBreve::DurBaseBreve()
        :myRational( VAL_BREVE )
        ,myName( STR_BREVE )
        ,myMaxBeams( DUR_MAX_BEAMS_BREVE )
        {}
        
        DurBaseBreve::~DurBaseBreve() {}
        
        IDurBaseUP DurBaseBreve::clone() const
        {
            return Private::makeUnique<DurBaseBreve>();
        }
        
        Rational DurBaseBreve::getValue() const
        {
            return myRational;
        }
        
        int DurBaseBreve::getMaxBeams() const
        {
            return myMaxBeams;
        }
        
        std::ostream& DurBaseBreve::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
