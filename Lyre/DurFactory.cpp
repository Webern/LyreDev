#include "DurFactory.h"
#include "DurQuarter.h"

namespace lyre
{
    namespace impl
    {
        DurFactory::DurFactory()
        {
            if ( ourDurMap.size() == 0 )
            {
                ourDurMap.insert( DurPair{ "Quarter", std::make_shared<DurQuarter>() } );
            }
        }
        
        IDurSP DurFactory::createDur( const String& durName ) const
        {
            auto it = ourDurMap.find( durName );
            if ( it == ourDurMap.cend() )
            {
                throw std::runtime_error( "invalid Dur string" );
            }
            return it->second;
        }
    }
}