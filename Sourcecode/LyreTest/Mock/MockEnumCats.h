//PRIVATE
#pragma once
#include "Lyre/Private/Enum.h"

namespace Lyre
{
    namespace Mock
    {
        const static std::shared_ptr<Strings> mockenumstrings = std::make_shared<Strings>( Strings{"Bones","Bishop","Mabel"} );
        
        class MockEnumCats : public Lyre::Private::Enum
        {
        public:
            MockEnumCats()
            :Enum( 0, mockenumstrings, 1 )
            {}
        };
    }
}