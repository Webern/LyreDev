//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IXXXX.h"

namespace Lyre
{
    enum class PUBLIC XXXXFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IXXXXFactory)
    
    PUBLIC IXXXXFactoryUP
        createXXXXFactory(
            XXXXFactoryType t = 
            XXXXFactoryType::Standard );

    class PUBLIC IXXXXFactory
    {
    public:
        virtual ~IXXXXFactory() {}
        virtual IXXXXUP create() const = 0;

    };
}
