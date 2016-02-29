#include "LyreTest/Mock/MockDurBaseFactory.h"
#include "Lyre/Private/throw.h"

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
                    THROW( "MockDurBaseFactory attempted to dereference a null IDurBase pointer" )
                }
                IDurBaseUP output = it->second->clone();
                return std::move( output );
            }
            THROW( "invalid mock dur name" )
        }
    }
}