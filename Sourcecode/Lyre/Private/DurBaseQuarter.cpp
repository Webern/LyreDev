#include "Lyre/Private/DurBaseQuarter.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBaseQuarter::DurBaseQuarter()
        :myRational( VAL_QUARTER )
        ,myName( STR_QUARTER )
        ,myMaxBeams( DUR_MAX_BEAMS_QUARTER )
        {}
        
        DurBaseQuarter::~DurBaseQuarter() {}
        
        IDurBaseUP DurBaseQuarter::clone() const
        {
            return Private::makeUnique<DurBaseQuarter>();
        }
        
        Rational DurBaseQuarter::getValue() const
        {
            return myRational;
        }
        
        int DurBaseQuarter::getMaxBeams() const
        {
            return myMaxBeams;
        }
        
        std::ostream& DurBaseQuarter::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
