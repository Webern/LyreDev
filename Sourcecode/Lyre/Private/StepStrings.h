//PRIVATE
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(StepStrings)
        
        class StepStrings
        {
        public:
            std::shared_ptr<Strings> getStrings() const;
        private:
            static std::shared_ptr<Strings> ourStrings;
            void initialize() const;
        };
    }
}
