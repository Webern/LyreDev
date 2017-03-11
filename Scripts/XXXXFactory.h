//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IXXXXFactory.h"
#include "Lyre/IXXXX.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(XXXXFactory)
        
        class XXXXFactory : public IXXXXFactory
        {
        public:
            virtual ~XXXXFactory();
            
            virtual IXXXXUP create() const;
        };
    }
}
