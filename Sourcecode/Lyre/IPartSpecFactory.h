//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPartSpec.h"

namespace Lyre
{
    enum class PUBLIC PartSpecFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IPartSpecFactory)
    
    PUBLIC IPartSpecFactoryUP
        createPartSpecFactory(
            PartSpecFactoryType t = 
            PartSpecFactoryType::Standard );

    class PUBLIC IPartSpecFactory
    {
    public:
        virtual ~IPartSpecFactory() {}
        
        virtual IPartSpecUP create(
            int numStaves,
            const IInstrumentUP& instrument ) const = 0;

    };
}
