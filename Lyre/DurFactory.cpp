#include "DurFactory.h"
#include "Dur256th.h"
#include "Dur128th.h"
#include "Dur64th.h"
#include "Dur32nd.h"
#include "Dur16th.h"
#include "DurEighth.h"
#include "DurQuarter.h"
#include "DurHalf.h"
#include "DurWhole.h"
#include "DurBreve.h"
#include "DurLonga.h"

namespace lyre
{
    namespace impl
    {
        std::map<String, IDurSP> DurFactory::ourDurMap;
        
        DurFactory::DurFactory()
        {
            if ( ourDurMap.size() == 0 )
            {
                ourDurMap.insert( DurPair{ "256th", std::make_shared<Dur256th>() } );
                ourDurMap.insert( DurPair{ "128th", std::make_shared<Dur128th>() } );
                ourDurMap.insert( DurPair{ "64th", std::make_shared<Dur64th>() } );
                ourDurMap.insert( DurPair{ "32nd", std::make_shared<Dur32nd>() } );
                ourDurMap.insert( DurPair{ "16th", std::make_shared<Dur16th>() } );
                ourDurMap.insert( DurPair{ "Eighth", std::make_shared<DurEighth>() } );
                ourDurMap.insert( DurPair{ "Quarter", std::make_shared<DurQuarter>() } );
                ourDurMap.insert( DurPair{ "Half", std::make_shared<DurHalf>() } );
                ourDurMap.insert( DurPair{ "Whole", std::make_shared<DurWhole>() } );
                ourDurMap.insert( DurPair{ "Breve", std::make_shared<DurBreve>() } );
                ourDurMap.insert( DurPair{ "Longa", std::make_shared<DurLonga>() } );
            }
        }
        
        DurFactory::~DurFactory() {}
        
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