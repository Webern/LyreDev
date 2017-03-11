#include "Lyre/Private/TimeSignatureFactory.h"
#include "Lyre/ITimeSignature.h"
#include "Lyre/Private/TimeSignature.h"


namespace Lyre
{
    namespace Private
    {
        TimeSignatureFactory::~TimeSignatureFactory() {}
        
        ITimeSignatureUP TimeSignatureFactory::create(
            const IBeatPatternUP& beatPattern,
            int top,
            int bottom ) const
        {
            return ITimeSignatureUP{ new TimeSignature{ beatPattern->clone(), top, bottom } };
        }
        
        ITimeSignatureUP TimeSignatureFactory::create(
            int top,
            int bottom ) const
        {
            return ITimeSignatureUP{ new TimeSignature{ top, bottom } };
        }
    }
}

