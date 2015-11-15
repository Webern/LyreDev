#include "Lyre/Private/DurBase128th.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBase128th::ourRational = Rational { 1, 32 };
        
        const String DurBase128th::ourName = "128th";
        
        DurBase128th::~DurBase128th() {}
        
        IDurBaseUP DurBase128th::clone() const
        {
            return makeUnique<DurBase128th>();
        }
        
        void DurBase128th::copyTo( IDurBaseUP& output ) const
        {
            auto tempP = static_cast<const IDurBase*>( this );
            Lyre::copyTo<IDurBase>( tempP, output );
        }
        
        Rational DurBase128th::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBase128th::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}