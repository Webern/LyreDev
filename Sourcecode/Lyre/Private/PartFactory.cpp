#include "Lyre/Private/PartFactory.h"
#include "Lyre/IPart.h"
#include "Lyre/Private/Part.h"


namespace Lyre
{
    namespace Private
    {
        PartFactory::~PartFactory() {}
        
        IPartUP PartFactory::create(
                int numStaves,
                const IInstrumentUP& instrument ) const
        {
            return IPartUP{ new Part{ numStaves, instrument } };
        }
    }
}
