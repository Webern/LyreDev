#include "Lyre/Private/DurBaseFactory.h"
#include "Lyre/Private/DurBase256th.h"
#include "Lyre/Private/DurBase128th.h"
#include "Lyre/Private/DurBase64th.h"
#include "Lyre/Private/DurBase32nd.h"
#include "Lyre/Private/DurBase16th.h"
#include "Lyre/Private/DurBase8th.h"
#include "Lyre/Private/DurBaseQuarter.h"
#include "Lyre/Private/DurBaseHalf.h"
#include "Lyre/Private/DurBaseWhole.h"
#include "Lyre/Private/DurBaseBreve.h"
#include "Lyre/Private/DurBaseLonga.h"

namespace Lyre
{
    namespace Private
    {
        std::map<String, IDurBaseSP> DurBaseFactory::ourDurMap;
        
        DurBaseFactory::DurBaseFactory()
        {
            if ( ourDurMap.size() == 0 )
            {
                ourDurMap.insert( DurPair{ "256th", std::make_shared<DurBase256th>() } );
                ourDurMap.insert( DurPair{ "128th", std::make_shared<DurBase128th>() } );
                ourDurMap.insert( DurPair{ "64th", std::make_shared<DurBase64th>() } );
                ourDurMap.insert( DurPair{ "32nd", std::make_shared<DurBase32nd>() } );
                ourDurMap.insert( DurPair{ "16th", std::make_shared<DurBase16th>() } );
                ourDurMap.insert( DurPair{ "Eighth", std::make_shared<DurBase8th>() } );
                ourDurMap.insert( DurPair{ "Quarter", std::make_shared<DurBaseQuarter>() } );
                ourDurMap.insert( DurPair{ "Half", std::make_shared<DurBaseHalf>() } );
                ourDurMap.insert( DurPair{ "Whole", std::make_shared<DurBaseWhole>() } );
                ourDurMap.insert( DurPair{ "Breve", std::make_shared<DurBaseBreve>() } );
                ourDurMap.insert( DurPair{ "Longa", std::make_shared<DurBaseLonga>() } );
            }
        }
        
        DurBaseFactory::~DurBaseFactory() {}
        
        IDurBaseSP DurBaseFactory::createDur( const String& durName ) const
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