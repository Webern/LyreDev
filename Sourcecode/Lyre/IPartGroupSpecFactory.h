//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPartGroupSpec.h"

namespace Lyre
{
    enum class PUBLIC PartGroupSpecFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IPartGroupSpecFactory)
    
    PUBLIC IPartGroupSpecFactoryUP
        createPartGroupSpecFactory(
            PartGroupSpecFactoryType t = 
            PartGroupSpecFactoryType::Standard );

    class PUBLIC IPartGroupSpecFactory
    {
    public:
        virtual ~IPartGroupSpecFactory() {}
        virtual IPartGroupSpecUP create() const = 0;

    };
}
