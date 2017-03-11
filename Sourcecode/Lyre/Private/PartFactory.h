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
            
            virtual IPartFactoryUP clone() const;
            
            virtual IPartUP create(
                const IPartSpecUP& partSpec,
                const IMasterTrackSPC& masterTrack ) const;
        };
    }
}
