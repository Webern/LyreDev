#include "Lyre/IDurBaseFactory.h"
#include "Lyre/Private/DurBaseFactory.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    IDurBaseFactory::~IDurBaseFactory() {}
    
    IDurBaseFactoryUP IDurBaseFactory::createDurBaseFactory( const DurBaseFactoryType t )
    {
        IDurBaseFactoryUP output;
        switch ( t )
        {
            case DurBaseFactoryType::Standard:
                output = Private::makeUnique<Private::DurBaseFactory>();
                break;
                
            default:
                throw std::runtime_error( "unknown DurBaseFactoryType" );
                break;
        }
        return std::move( output );
    }
}