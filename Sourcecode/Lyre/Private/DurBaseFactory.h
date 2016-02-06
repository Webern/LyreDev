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
        
        class EXPORT_FOR_TESTS DurBaseFactory : public IDurBaseFactory
        {
        public:
            DurBaseFactory();
            virtual ~DurBaseFactory();
            virtual IDurBaseUP createDur( const String& durName ) const;
        private:
            using DurMap = std::map<String, IDurBaseUP>;
            using DurPair = std::pair<String, IDurBaseUP>;
            static DurMap ourDurMap;
        };
    }
}
