#include "Lyre/Private/DurBase64th.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBase64th::ourRational = Rational { 1, 16 };
        
        const String DurBase64th::ourName = "64th";
        
        DurBase64th::~DurBase64th() {}
        
        IDurBaseUP DurBase64th::clone() const
        {
            return Private::makeUnique<DurBase64th>();
        }
        
//        void DurBase64th::copyTo( IDurBaseUP& output ) const
//        {
//            auto tempP = static_cast<const IDurBase*>( this );
//            Private::copyTo<IDurBase>( tempP, output );
//        }
        
        Rational DurBase64th::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBase64th::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}
