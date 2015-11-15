#include "Lyre/IDurBaseFactory.h"
#include "Lyre/Private/DurBaseFactory.h"

namespace Lyre
{
    IDurBaseFactory::~IDurBaseFactory() {}
    
    IDurBaseFactorySP IDurBaseFactory::createDurBaseFactory( const DurBaseFactoryType t )
    {
        IDurBaseFactorySP output;
        switch ( t )
        {
            case DurBaseFactoryType::Standard:
                output = std::make_shared<Private::DurBaseFactory>();
                break;
                
            default:
                throw std::runtime_error( "unknown DurBaseFactoryType" );
                break;
        }
        return output;
    }
}