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
        
        struct EXPORT_FOR_TESTS DurMap
        {
        public:
            using DurPairMap = std::map<String, IDurBaseUP>;
            using DurPair = std::pair<String, IDurBaseUP>;
            static DurPairMap values;
            static DurPairMap makeValues();
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
