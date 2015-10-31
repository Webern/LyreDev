#include "Lyre/IPitchFactory.h"
#include "Lyre/PitchFactory.h"

namespace lyre
{
    using namespace lyre::impl;
    IPitchFactoryUP IPitchFactory::createPitchFactory( const PitchFactoryType t)
    {
        IPitchFactoryUP output;
        switch ( t )
        {
            case PitchFactoryType::StandardChromatic:
                output = nullptr;
                break;
                
            default:
                break;
        }
        return output;
    }
}