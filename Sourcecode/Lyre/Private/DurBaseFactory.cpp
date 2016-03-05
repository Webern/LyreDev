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
		DurMap::DurPairMap DurMap::values = 
		{
			DurPair{ "256th", Private::makeUnique<DurBase256th>() },
			DurPair{ "128th", Private::makeUnique<DurBase128th>() },
			DurPair{ "64th", Private::makeUnique<DurBase64th>() },
			DurPair{ "32nd", Private::makeUnique<DurBase32nd>() },
			DurPair{ "16th", Private::makeUnique<DurBase16th>() },
			DurPair{ "Eighth", Private::makeUnique<DurBaseEighth>() },
			DurPair{ "Quarter", Private::makeUnique<DurBaseQuarter>() },
			DurPair{ "Half", Private::makeUnique<DurBaseHalf>() },
			DurPair{ "Whole", Private::makeUnique<DurBaseWhole>() },
			DurPair{ "Breve", Private::makeUnique<DurBaseBreve>() },
			DurPair{ "Longa", Private::makeUnique<DurBaseLonga>() }
		};

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
