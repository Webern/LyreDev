#include "Lyre/IDurFactory.h"
#include "Lyre/DurFactory.h"

namespace lyre
{
    IDurFactory::~IDurFactory() {}
    
    IDurFactorySP IDurFactory::createDurFactory( const DurFactoryType t )
    {
        IDurFactorySP output;
        switch ( t )
        {
            case DurFactoryType::Standard:
                output = std::make_shared<impl::DurFactory>();
                break;
                
            default:
                throw std::runtime_error( "unknown DurFactoryType" );
                break;
        }
        return output;
    }
}