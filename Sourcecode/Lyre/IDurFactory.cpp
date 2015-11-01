#include "Lyre/IDurFactory.h"
#include "Lyre/Private/DurFactory.h"

namespace Lyre
{
    IDurFactory::~IDurFactory() {}
    
    IDurFactorySP IDurFactory::createDurFactory( const DurFactoryType t )
    {
        IDurFactorySP output;
        switch ( t )
        {
            case DurFactoryType::Standard:
                output = std::make_shared<Private::DurFactory>();
                break;
                
            default:
                throw std::runtime_error( "unknown DurFactoryType" );
                break;
        }
        return output;
    }
}