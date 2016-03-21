#include "Lyre/Private/PartSpecFactory.h"
#include "Lyre/IPartSpec.h"
#include "Lyre/Private/PartSpec.h"


namespace Lyre
{
    namespace Private
    {
        PartSpecFactory::~PartSpecFactory() {}
        
        IPartSpecUP PartSpecFactory::create(
            int numStaves,
            const IInstrumentUP& instrument ) const
        {
            return IPartSpecUP{ new PartSpec{ numStaves, instrument } };
        }
    }
}
