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
        
        using MockDurBases = std::map<String, IDurBaseUP>;
        
        IDurBaseFactorySP createMockDurBaseFactory( MockDurBases&& durs );
        
        class MockDurBaseFactory : public IDurBaseFactory
        {
        public:
            MockDurBaseFactory( MockDurBases&& durs );
            IDurBaseUP createDur( const String& durName ) const;
        private:
            MockDurBases myDurs;
        };
    }
}