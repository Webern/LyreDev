//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDuration.h"
#include <memory>

namespace Lyre
{
    namespace Private
    {
        class DurationFactory //: public IDurationFactory
        {
        public:
            virtual ~DurationFactory() = default;
            
            virtual IDurationUP createDuration( const std::string& durBaseName );
            virtual IDurationUP createDuration( const std::string& durBaseName );
        };
    }
}
