//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDurBaseFactory.h"
#include <memory>
#include <map>

namespace Lyre
{
    namespace Private
    {
        class DurBaseFactory;
        using DurBaseFactorySP = std::shared_ptr<DurBaseFactory>;
        using DurBaseFactoryUP = std::unique_ptr<DurBaseFactory>;
        
        class DurBaseFactory : public IDurBaseFactory
        {
        public:
            DurBaseFactory();
            virtual ~DurBaseFactory();
            virtual IDurBaseSP createDur( const String& durName ) const;
        private:
            using DurMap = std::map<String, IDurBaseSP>;
            using DurPair = std::pair<String, IDurBaseSP>;
            static DurMap ourDurMap;
        };
    }
}
