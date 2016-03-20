//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPartSpecFactory.h"
#include "Lyre/IPartSpec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(PartSpecFactory)
        
        class PartSpecFactory : public IPartSpecFactory
        {
        public:
            virtual ~PartSpecFactory();
            
            virtual IPartSpecUP create( const IInstrumentUP& instrument ) const;
        };
    }
}
