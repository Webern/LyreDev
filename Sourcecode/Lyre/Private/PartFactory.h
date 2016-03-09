//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPartFactory.h"
#include "Lyre/IPart.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(PartFactory)
        
        class PartFactory : public IPartFactory
        {
        public:
            virtual ~PartFactory();
            
            virtual IPartUP create(
                int numStaves,
                int layersPerStaff,
                const IInstrumentUP& instrument ) const;
        };
    }
}
