#include "Lyre/Private/TupletDefFatory.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/Private/DurBaseQuarter.h"
#include "Lyre/Private/DurDot.h"

namespace Lyre
{
    namespace Private
    {
        class TempFakeTupletDef : public ITupletDef
        {
        public:
            virtual ~TempFakeTupletDef() = default;
            
            virtual ITupletDefUP clone() const
            {
                return ITupletDefUP{ new TempFakeTupletDef() };
            }
            
            void copyTo( ITupletDefUP& output ) const
            {
                output = ITupletDefUP{ new TempFakeTupletDef() };
            }
            
            virtual Rational getValue() const
            {
                return Rational{ 1, 1 };
            }
            
            virtual IDurDotUPC getNumeratorDurDot() const
            {
                return IDurDotUPC{ new Private::DurDot{ "Quarter", 0 } };
            }
            
            virtual Integer getNumeratorCount() const
            {
                return -1;
            }
            
            virtual IDurDotUPC getDenominatorDurDot() const
            {
                return IDurDotUPC{ new Private::DurDot{ "Quarter", 0 } };
            }
            
            virtual Integer getDenominatorCount() const
            {
                return -1;
            }
            
            virtual std::ostream& toStream( std::ostream& os ) const
            {
                return os << "not implemented";
            }
            
            virtual String toString() const
            {
                return "string not implemented";
            }
        };

////////////////////////////////////////////////////////////
        
        ITupletDefUP TupletDefFactory::createTupletDef(
            const Integer numeratorCount,
            const Lyre::IDurDot& numeratorType,
            const Integer noteCountXXXX,
            const Lyre::IDurDot& denomintorType )
        {
            auto xx = numeratorCount;
            ++xx;
            auto yy = noteCountXXXX;
            ++yy;
            auto ss = numeratorType.toString();
            ss.clear();
            auto tt = denomintorType.toString();
            tt.clear();
            return ITupletDefUP{ new TempFakeTupletDef{} };
        }
        
        ITupletDefUP TupletDefFactory::createTupletDef(
            const Integer numerator,
            const Integer denominator,
            const IDurDot& durationType )
        {
            auto xx = numerator;
            ++xx;
            auto yy = denominator;
            ++yy;
            auto ss = durationType.toString();
            ss.clear();
            return ITupletDefUP{ new TempFakeTupletDef{} };
        }
        
        ITupletDefUP TupletDefFactory::createTupletDef(
           const Integer numerator,
           const Integer denominator,
           const String& durBaseName )
        {
            auto xx = numerator;
            ++xx;
            auto yy = denominator;
            ++yy;
            auto ss = durBaseName;
            ss.clear();
            return ITupletDefUP{ new TempFakeTupletDef{} };
        }
    }
}
