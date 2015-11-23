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
#include "Lyre/Private/makeUnique.h"
#include "Lyre/Private/throw.h"
#include <sstream>

namespace Lyre
{
    namespace Private
    {
        std::map<String, IDurBaseUP> DurBaseFactory::ourDurMap;
        
        DurBaseFactory::DurBaseFactory()
        {
            if ( ourDurMap.size() == 0 )
            {
                ourDurMap.insert( DurPair{ "256th", Private::makeUnique<DurBase256th>() } );
                ourDurMap.insert( DurPair{ "128th", Private::makeUnique<DurBase128th>() } );
                ourDurMap.insert( DurPair{ "64th", Private::makeUnique<DurBase64th>() } );
                ourDurMap.insert( DurPair{ "32nd", Private::makeUnique<DurBase32nd>() } );
                ourDurMap.insert( DurPair{ "16th", Private::makeUnique<DurBase16th>() } );
                ourDurMap.insert( DurPair{ "Eighth", Private::makeUnique<DurBase8th>() } );
                ourDurMap.insert( DurPair{ "Quarter", Private::makeUnique<DurBaseQuarter>() } );
                ourDurMap.insert( DurPair{ "Half", Private::makeUnique<DurBaseHalf>() } );
                ourDurMap.insert( DurPair{ "Whole", Private::makeUnique<DurBaseWhole>() } );
                ourDurMap.insert( DurPair{ "Breve", Private::makeUnique<DurBaseBreve>() } );
                ourDurMap.insert( DurPair{ "Longa", Private::makeUnique<DurBaseLonga>() } );
            }
        }
        
        DurBaseFactory::~DurBaseFactory() {}
        
        IDurBaseUP DurBaseFactory::createDur( const String& durName ) const
        {
            auto it = ourDurMap.find( durName );
            if ( it == ourDurMap.cend() )
            {
                std::stringstream ss;
                ss << "'" << durName << "'" << " is not a valid DurBase name";
                THROW( ( ss.str() ) )
            }
            IDurBaseUP temp;
            it->second->copyTo( temp );
            return temp;
        }
    }
}
