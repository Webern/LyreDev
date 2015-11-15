#include "Lyre/Private/DurBaseQuarter.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBaseQuarter::ourRational = Rational { 1, 1 };
        
        const String DurBaseQuarter::ourName = "Quarter";
        
        DurBaseQuarter::~DurBaseQuarter() {}
        
        Rational DurBaseQuarter::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBaseQuarter::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}