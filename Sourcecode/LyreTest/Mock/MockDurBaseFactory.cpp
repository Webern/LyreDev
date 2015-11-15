#include "LyreTest/Mock/MockDurBaseFactory.h"

namespace Lyre
{
    namespace Mock
    {
        IDurBaseFactorySP createMockDurBaseFactory( MockDurs&& durs )
        {
            return std::make_shared<MockDurBaseFactory>( std::move( durs ) );
        }
        MockDurBaseFactory::MockDurBaseFactory( MockDurs&& durs )
        :myDurs( std::move( durs ) )
        {}
        
        IDurBaseSP MockDurBaseFactory::createDur( const String& durName ) const
        {
            auto it = myDurs.find( durName );
            if ( it != std::end( myDurs ) )
            {
                if ( ! it->second )
                {
                    throw std::runtime_error{ "MockDurBaseFactory attempted to dereference a null IDurBase pointer" };
                }
                return it->second;
            }
            throw std::runtime_error{ "invalid mock dur name" };
            
            // unreachable code
            IDurBaseSP nullIDurBaseSP;
            return nullIDurBaseSP;
        }
    }
}