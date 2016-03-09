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
                int layersPerStaff,
                const IInstrumentUP& instrument ) const
        {
            return IPartUP{ new Part{ numStaves, layersPerStaff, instrument } };
        }
    }
}
