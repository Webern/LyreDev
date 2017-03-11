#include "Lyre/Private/DurBaseFactory.h"
#include "Lyre/Private/DurBase256th.h"
#include "Lyre/Private/DurBase128th.h"
#include "Lyre/Private/DurBase64th.h"
#include "Lyre/Private/DurBase32nd.h"
#include "Lyre/Private/DurBase16th.h"
#include "Lyre/Private/DurBaseEighth.h"
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
        DurMap::DurPairMap DurMap::makeValues()
        {
            DurPairMap map;
            map.insert( DurPair{ STR_256TH, makeUnique<DurBase256th>() } );
			map.insert( DurPair{ STR_128TH, makeUnique<DurBase128th>() } );
			map.insert( DurPair{ STR_64TH, makeUnique<DurBase64th>() } );
			map.insert( DurPair{ STR_32ND, makeUnique<DurBase32nd>() } );
			map.insert( DurPair{ STR_16TH, makeUnique<DurBase16th>() } );
			map.insert( DurPair{ STR_EIGHTH, makeUnique<DurBaseEighth>() } );
			map.insert( DurPair{ STR_QUARTER, makeUnique<DurBaseQuarter>() } );
			map.insert( DurPair{ STR_HALF, makeUnique<DurBaseHalf>() } );
			map.insert( DurPair{ STR_WHOLE, makeUnique<DurBaseWhole>() } );
			map.insert( DurPair{ STR_BREVE, makeUnique<DurBaseBreve>() } );
			map.insert( DurPair{ STR_LONGA, makeUnique<DurBaseLonga>() } );
            return std::move( map );
        }
		DurMap::DurPairMap DurMap::values = DurMap::makeValues();

		DurBaseFactory::DurBaseFactory()
        :myDurMap()
        {
            
        }
        
        DurBaseFactory::~DurBaseFactory() {}
        
        IDurBaseUP DurBaseFactory::createDur( const String& durName ) const
        {
            auto it = myDurMap.values.find( durName );
            if ( it == myDurMap.values.cend() )
            {
                std::stringstream ss;
                ss << "'" << durName << "'" << " is not a valid DurBase name";
                THROW( ( ss.str() ) )
            }
            IDurBaseUP temp;
            temp = it->second->clone();
            return temp;
        }
    }
}
