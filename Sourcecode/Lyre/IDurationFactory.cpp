#include "Lyre/IDurationFactory.h"
#include "Lyre/Private/DurationFactory.h"
#include "Lyre/Private/makeUnique.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IDurationFactory::~IDurationFactory() {}
    
    IDurationFactoryUP createDurationFactory( const DurationFactoryType t )
    {
        IDurationFactoryUP output;
        switch ( t )
        {
            case DurationFactoryType::Standard:
                output = Private::makeUnique<Private::DurationFactory>();
                break;
                
            default:
                THROW( "unknown DurationFactoryType" )
                break;
        }
        return std::move( output );
    }
}
