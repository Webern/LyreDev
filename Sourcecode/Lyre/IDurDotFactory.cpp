#include "Lyre/IDurDotFactory.h"
#include "Lyre/Private/DurDotFactory.h"
#include "Lyre/Private/makeUnique.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IDurDotFactory::~IDurDotFactory() {}
    
    IDurDotFactoryUP createDurDotFactory( const DurDotFactoryType t )
    {
        IDurDotFactoryUP output;
        switch ( t )
        {
            case DurDotFactoryType::Standard:
                output = Private::makeUnique<Private::DurDotFactory>();
                break;
                
            default:
                THROW( "unknown DurDotFactoryType" )
                break;
        }
        return std::move( output );
    }
}
