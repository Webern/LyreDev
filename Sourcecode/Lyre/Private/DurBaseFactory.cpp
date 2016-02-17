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
        DurMap::DurMap()
        :values()
        {
            values.clear();
            values.insert( DurPair{ "256th", Private::makeUnique<DurBase256th>() } );
            values.insert( DurPair{ "128th", Private::makeUnique<DurBase128th>() } );
            values.insert( DurPair{ "64th", Private::makeUnique<DurBase64th>() } );
            values.insert( DurPair{ "32nd", Private::makeUnique<DurBase32nd>() } );
            values.insert( DurPair{ "16th", Private::makeUnique<DurBase16th>() } );
            values.insert( DurPair{ "Eighth", Private::makeUnique<DurBaseEighth>() } );
            values.insert( DurPair{ "Quarter", Private::makeUnique<DurBaseQuarter>() } );
            values.insert( DurPair{ "Half", Private::makeUnique<DurBaseHalf>() } );
            values.insert( DurPair{ "Whole", Private::makeUnique<DurBaseWhole>() } );
            values.insert( DurPair{ "Breve", Private::makeUnique<DurBaseBreve>() } );
            values.insert( DurPair{ "Longa", Private::makeUnique<DurBaseLonga>() } );
        }
        
        
        DurMap::DurMap( const DurMap& other )
        :values()
        {
            for ( auto i = other.values.cbegin(); i != other.values.cend(); ++i )
            {
                values[i->first] = i->second->clone();
            }
        }
        
        DurMap& DurMap::operator=( const DurMap& other )
        {
            values.clear();
            for ( auto i = other.values.cbegin(); i != other.values.cend(); ++i )
            {
                values[i->first] = i->second->clone();
            }
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
