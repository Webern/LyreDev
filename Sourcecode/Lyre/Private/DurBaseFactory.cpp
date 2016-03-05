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
            map.insert( DurPair{ "256th", makeUnique<DurBase256th>() } );
			map.insert( DurPair{ "128th", makeUnique<DurBase128th>() } );
			map.insert( DurPair{ "64th", makeUnique<DurBase64th>() } );
			map.insert( DurPair{ "32nd", makeUnique<DurBase32nd>() } );
			map.insert( DurPair{ "16th", makeUnique<DurBase16th>() } );
			map.insert( DurPair{ "Eighth", makeUnique<DurBaseEighth>() } );
			map.insert( DurPair{ "Quarter", makeUnique<DurBaseQuarter>() } );
			map.insert( DurPair{ "Half", makeUnique<DurBaseHalf>() } );
			map.insert( DurPair{ "Whole", makeUnique<DurBaseWhole>() } );
			map.insert( DurPair{ "Breve", makeUnique<DurBaseBreve>() } );
			map.insert( DurPair{ "Longa", makeUnique<DurBaseLonga>() } );
            return std::move( map );
        }
		DurMap::DurPairMap DurMap::values = DurMap::makeValues();

        DurMap::DurMap()
        {

        }
        
        
        DurMap::DurMap( const DurMap& other )
        {
			UNUSED_PARAMETER( other )
        }
        
        DurMap& DurMap::operator=( const DurMap& other )
        {
			UNUSED_PARAMETER( other )
            return *this;
        }
        
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
