#include "LyreTest/Mock/MockDurBaseFactory.h"

namespace Lyre
{
    namespace Mock
    {
        IDurBaseFactorySP createMockDurBaseFactory( MockDurBases&& durs )
        {
            return std::make_shared<MockDurBaseFactory>( std::move( durs ) );
        }
        MockDurBaseFactory::MockDurBaseFactory( MockDurBases&& durs )
        :myDurs( std::move( durs ) )
        {}
        
        IDurBaseUP MockDurBaseFactory::createDur( const String& durName ) const
        {
            auto it = myDurs.find( durName );
            if ( it != std::end( myDurs ) )
            {
                if ( ! it->second )
                {
                    throw std::runtime_error{ "MockDurBaseFactory attempted to dereference a null IDurBase pointer" };
                }
                IDurBaseUP output;
                it->second->copyTo( output );
                return std::move( output );
            }
            throw std::runtime_error{ "invalid mock dur name" };
            
            // unreachable code
            IDurBaseUP nullIDurBaseUP;
            return nullIDurBaseUP;
        }
    }
}