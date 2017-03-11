//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPartGroupSpecFactory.h"
#include "Lyre/IPartGroupSpec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(PartGroupSpecFactory)
        
        class PartGroupSpecFactory : public IPartGroupSpecFactory
        {
        public:
            virtual ~PartGroupSpecFactory();
            
            virtual IPartGroupSpecUP create() const;
        };
    }
}
