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
#include "Lyre/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        std::map<String, IDurBaseUP> DurBaseFactory::ourDurMap;
        
        DurBaseFactory::DurBaseFactory()
        {
            if ( ourDurMap.size() == 0 )
            {
                ourDurMap.insert( DurPair{ "256th", makeUnique<DurBase256th>() } );
                ourDurMap.insert( DurPair{ "128th", makeUnique<DurBase128th>() } );
                ourDurMap.insert( DurPair{ "64th", makeUnique<DurBase64th>() } );
                ourDurMap.insert( DurPair{ "32nd", makeUnique<DurBase32nd>() } );
                ourDurMap.insert( DurPair{ "16th", makeUnique<DurBase16th>() } );
                ourDurMap.insert( DurPair{ "Eighth", makeUnique<DurBase8th>() } );
                ourDurMap.insert( DurPair{ "Quarter", makeUnique<DurBaseQuarter>() } );
                ourDurMap.insert( DurPair{ "Half", makeUnique<DurBaseHalf>() } );
                ourDurMap.insert( DurPair{ "Whole", makeUnique<DurBaseWhole>() } );
                ourDurMap.insert( DurPair{ "Breve", makeUnique<DurBaseBreve>() } );
                ourDurMap.insert( DurPair{ "Longa", makeUnique<DurBaseLonga>() } );
            }
        }
        
        DurBaseFactory::~DurBaseFactory() {}
        
        IDurBaseUP DurBaseFactory::createDur( const String& durName ) const
        {
            auto it = ourDurMap.find( durName );
            if ( it == ourDurMap.cend() )
            {
                throw std::runtime_error( "invalid Dur string" );
            }
            IDurBaseUP temp;
            it->second->copyTo( temp );
            return temp;
        }
    }
}