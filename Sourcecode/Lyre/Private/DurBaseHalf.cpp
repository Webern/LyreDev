#include "Lyre/Private/DurBaseHalf.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBaseHalf::ourRational = Rational { 2, 1 };
        
        const String DurBaseHalf::ourName = "Half";
        
        DurBaseHalf::~DurBaseHalf() {}
        
        IDurBaseUP DurBaseHalf::clone() const
        {
            return Private::makeUnique<DurBaseHalf>();
        }
        
        void DurBaseHalf::copyTo( IDurBaseUP& output ) const
        {
            auto tempP = static_cast<const IDurBase*>( this );
            Private::copyTo<IDurBase>( tempP, output );
        }
        
        Rational DurBaseHalf::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBaseHalf::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}
