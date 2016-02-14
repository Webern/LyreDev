//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IDurBaseFactory.h"
#include <map>

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(DurBaseFactory)
        
        struct DurMap
        {
        public:
            using DurPairMap = std::map<String, IDurBaseUP>;
            using DurPair = std::pair<String, IDurBaseUP>;
            DurPairMap values;
            DurMap();
            DurMap( const DurMap& other );
            DurMap& operator=( const DurMap& other );
        };
        
        class EXPORT_FOR_TESTS DurBaseFactory : public IDurBaseFactory
        {
        public:
            DurBaseFactory();
            virtual ~DurBaseFactory();
            virtual IDurBaseUP createDur( const String& durName ) const;
        private:
            DurMap myDurMap;
        };
    }
}
