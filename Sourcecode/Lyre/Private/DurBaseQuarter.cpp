#include "Lyre/Private/DurBaseQuarter.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        DurBaseQuarter::DurBaseQuarter()
        :myRational( 1, 1 )
        ,myName( "Quarter" )
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
        std::ostream& DurBaseQuarter::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}
