#include "Lyre/Private/Dur32nd.h"

namespace lyre
{
    namespace impl
    {
        const Rational Dur32nd::ourRational = Rational { 1, 8 };
        
        const String Dur32nd::ourName = "32nd";
        
        Dur32nd::~Dur32nd() {}
        
        Rational Dur32nd::getValue() const
        {
            return ourRational;
        }
        std::ostream& Dur32nd::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}