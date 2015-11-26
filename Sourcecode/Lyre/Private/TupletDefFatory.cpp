#include "Lyre/Private/TupletDefFatory.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/Private/DurBaseQuarter.h"
#include "Lyre/Private/DurDot.h"
#include "Lyre/Private/TupletDef.h"

namespace Lyre
{
    namespace Private
    {
        class TempFakeTupletDef : public ITupletDef
        {
        public:
            
        };

//////////////////////////////////////////////////////////////////////
        
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
            return ITupletDefUP{ new Private::TupletDef{} };
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
            return ITupletDefUP{ new Private::TupletDef{} };
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
            return ITupletDefUP{ new Private::TupletDef{} };
        }
    }
}
