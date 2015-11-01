//PRIVATE
#pragma once

#include "Lyre/IDurFactory.h"
#include "Lyre/IDur.h"

#include <vector>
#include <map>

namespace Lyre
{
    namespace Mock
    {
        class MockDurFactory;
        using MockDurFactoryUP = std::unique_ptr<MockDurFactory>;
        using MockDurFactorySP = std::shared_ptr<MockDurFactory>;
        
        using MockDurs = std::map<String, IDurSP>;
        
        IDurFactorySP createMockDurFactory( MockDurs&& durs );
        
        class MockDurFactory : public IDurFactory
        {
        public:
            MockDurFactory( MockDurs&& durs );
            IDurSP createDur( const String& durName ) const;
        private:
            MockDurs myDurs;
        };
    }
}