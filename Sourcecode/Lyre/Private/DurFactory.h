//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDurFactory.h"
#include <memory>
#include <map>

namespace lyre
{
    namespace impl
    {
        class DurFactory;
        using DurFactorySP = std::shared_ptr<DurFactory>;
        using DurFactoryUP = std::unique_ptr<DurFactory>;
        
        class DurFactory : public IDurFactory
        {
        public:
            DurFactory();
            virtual ~DurFactory();
            virtual IDurSP createDur( const String& durName ) const;
        private:
            using DurMap = std::map<String, IDurSP>;
            using DurPair = std::pair<String, IDurSP>;
            static DurMap ourDurMap;
        };
    }
}
