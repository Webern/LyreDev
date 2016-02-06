#include "Lyre/Private/TimeSignatureFactory.h"
#include "Lyre/ITimeSignature.h"
#include "Lyre/Private/TimeSignature.h"


namespace Lyre
{
    namespace Private
    {
        TimeSignatureFactory::~TimeSignatureFactory() {}
        
        ITimeSignatureUP TimeSignatureFactory::create(
            Integer top,
            Integer bottom )
        {
            return ITimeSignatureUP{ new TimeSignature{ top, bottom } };
        }
    }
}
