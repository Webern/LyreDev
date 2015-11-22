#include "Lyre/Private/DurBase8th.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBase8th::ourRational = Rational { 1, 2 };
        
        const String DurBase8th::ourName = "Eighth";
        
        DurBase8th::~DurBase8th() {}
        
        IDurBaseUP DurBase8th::clone() const
        {
            return Private::makeUnique<DurBase8th>();
        }
        
        void DurBase8th::copyTo( IDurBaseUP& output ) const
        {
            auto tempP = static_cast<const IDurBase*>( this );
            Private::copyTo<IDurBase>( tempP, output );
        }
        
        Rational DurBase8th::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBase8th::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}
