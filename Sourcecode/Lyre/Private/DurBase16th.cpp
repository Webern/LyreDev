#include "Lyre/Private/DurBase16th.h"
#include "Lyre/makeUnique.h"
#include "Lyre/copyTo.h"
#include "Lyre/IDurBase.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBase16th::ourRational = Rational { 1, 4 };
        
        const String DurBase16th::ourName = "16th";
        
        DurBase16th::~DurBase16th() {}
        
        IDurBaseUP DurBase16th::clone() const
        {
            return makeUnique<DurBase16th>();
        }
        
        void DurBase16th::copyTo( IDurBaseUP& output ) const
        {
            auto tempP = static_cast<const IDurBase*>( this );
            Lyre::copyTo<IDurBase>( tempP, output );
        }
        
        Rational DurBase16th::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBase16th::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}