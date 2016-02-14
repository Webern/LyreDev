#include "Lyre/Private/TimeSignatureFactory.h"
#include "Lyre/ITimeSignature.h"
#include "Lyre/Private/TimeSignature.h"

#if 1==0
namespace Lyre
{
    namespace Private
    {
        TimeSignatureFactory::~TimeSignatureFactory() {}
        
        ITimeSignatureUP TimeSignatureFactory::create(
            int top,
            int bottom )
        {
            return ITimeSignatureUP{ new TimeSignature{ top, bottom } };
        }
    }
}
#endif
