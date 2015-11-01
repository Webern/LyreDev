#include "LyreTest/Mock/MockDurFactory.h"

namespace Lyre
{
    namespace Mock
    {
        IDurFactorySP createMockDurFactory( MockDurs&& durs )
        {
            return std::make_shared<MockDurFactory>( std::move( durs ) );
        }
        MockDurFactory::MockDurFactory( MockDurs&& durs )
        :myDurs( std::move( durs ) )
        {}
        
        IDurSP MockDurFactory::createDur( const String& durName ) const
        {
            auto it = myDurs.find( durName );
            if ( it != std::end( myDurs ) )
            {
                return it->second;
            }
            IDurSP nullIDurSP;
            return nullIDurSP;
        }
    }
}