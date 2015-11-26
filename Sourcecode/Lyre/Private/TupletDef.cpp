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
            auto numerator = getInTheSpaceOfType()->getValue() * Rational{ getInTheSpaceOf(), 1 };
            auto denominator = getCountType()->getValue() * Rational{ getCount(), 1 };
            return numerator / denominator;
        }

        Rational TupletDef::getTotalLength() const
        {
            return getInTheSpaceOfType()->getValue() * Rational{ getInTheSpaceOf(), 1 };
        }
        
        Integer TupletDef::getCount() const
        {
            return myCount;
        }
        
        IDurDotUPC TupletDef::getCountType() const
        {
            return myCountType.clone();
        }
        
        Integer TupletDef::getInTheSpaceOf() const
        {
            return myInTheSpaceOf;
        }
        
        IDurDotUPC TupletDef::getInTheSpaceOfType() const
        {
            return myInTheSpaceOfType.clone();
        }
        
        std::ostream& TupletDef::toStream( std::ostream& os ) const
        {
            os << myCount;
            os << "[";
            os << myCountType;
            os << "]:";
            os << myInTheSpaceOf;
            os << "[";
            os << myInTheSpaceOfType;
            os << "]";
            return os << "not implemented";
        }
        
        String TupletDef::toString() const
        {
            return "string not implemented";
        }
    }
}
