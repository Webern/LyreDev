#include "Lyre/IPitchFactory.h"
#include "Lyre/Private/PitchFactory.h"

namespace Lyre
{
    using namespace Lyre::Private;
    IPitchFactoryUP IPitchFactory::createPitchFactory( const PitchFactoryType t)
    {
        IPitchFactoryUP output;
        switch ( t )
        {
            case PitchFactoryType::StandardChromatic:
                output = IPitchFactoryUP{ new PitchFactory{} };
                break;
                
            default:
                break;
        }
        return output;
    }
}
