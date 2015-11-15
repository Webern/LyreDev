//PRIVATE
#pragma once

#include "Lyre/IDurBaseFactory.h"
#include "Lyre/IDurBase.h"

#include <vector>
#include <map>

namespace Lyre
{
    namespace Mock
    {
        class MockDurBaseFactory;
        using MockDurBaseFactoryUP = std::unique_ptr<MockDurBaseFactory>;
        using MockDurBaseFactorySP = std::shared_ptr<MockDurBaseFactory>;
        
        using MockDurs = std::map<String, IDurBaseSP>;
        
        IDurBaseFactorySP createMockDurBaseFactory( MockDurs&& durs );
        
        class MockDurBaseFactory : public IDurBaseFactory
        {
        public:
            MockDurBaseFactory( MockDurs&& durs );
            IDurBaseSP createDur( const String& durName ) const;
        private:
            MockDurs myDurs;
        };
    }
}