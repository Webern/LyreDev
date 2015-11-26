#include "Lyre/Private/TupletDef.h"
#include "Lyre/Private/DurDot.h"

namespace Lyre
{
    namespace Private
    {
        ITupletDefUP TupletDef::clone() const
        {
            return ITupletDefUP{ new TupletDef() };
        }
        
        void TupletDef::copyTo( ITupletDefUP& output ) const
        {
            auto tempP = static_cast<const ITupletDef*>( this );
            Private::copyTo<ITupletDef>( tempP, output );
        }
        
        Rational TupletDef::getMultiplier() const
        {
            return Rational{ 1, 1 };
        }

        Rational TupletDef::getTotalLength() const
        {
            return Rational{ 1, 1 };
        }
        
        Integer TupletDef::getCount() const
        {
            return -1;
        }
        
        IDurDotUPC TupletDef::getCountType() const
        {
            return IDurDotUPC{ new Private::DurDot{ "Quarter", 0 } };
        }
        
        Integer TupletDef::getInTheSpaceOf() const
        {
            return -1;
        }
        
        IDurDotUPC TupletDef::getInTheSpaceOfType() const
        {
            return IDurDotUPC{ new Private::DurDot{ "Quarter", 0 } };
        }
        
        std::ostream& TupletDef::toStream( std::ostream& os ) const
        {
            return os << "not implemented";
        }
        
        String TupletDef::toString() const
        {
            return "string not implemented";
        }
    }
}
