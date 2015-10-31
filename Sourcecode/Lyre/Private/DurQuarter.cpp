#include "Lyre/Private/DurQuarter.h"

namespace lyre
{
    namespace impl
    {
        const Rational DurQuarter::ourRational = Rational { 1, 1 };
        
        const String DurQuarter::ourName = "Quarter";
        
        DurQuarter::~DurQuarter() {}
        
        Rational DurQuarter::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurQuarter::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}