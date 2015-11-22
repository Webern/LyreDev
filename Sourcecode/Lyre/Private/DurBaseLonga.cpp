#include "Lyre/Private/DurBaseLonga.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBaseLonga::ourRational = Rational { 16, 1 };
        
        const String DurBaseLonga::ourName = "Longa";
        
        DurBaseLonga::~DurBaseLonga() {}
        
        IDurBaseUP DurBaseLonga::clone() const
        {
            return Private::makeUnique<DurBaseLonga>();
        }
        
        void DurBaseLonga::copyTo( IDurBaseUP& output ) const
        {
            auto tempP = static_cast<const IDurBase*>( this );
            Private::copyTo<IDurBase>( tempP, output );
        }
        
        Rational DurBaseLonga::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBaseLonga::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}
