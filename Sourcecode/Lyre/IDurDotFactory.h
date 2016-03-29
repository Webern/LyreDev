//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IDurDot.h"

namespace Lyre
{
    enum class PUBLIC DurDotFactoryType
    {
        Standard = 0
    };
    
    FORWARD_DECLARE(IDurDot)
    FORWARD_DECLARE(IDurDotFactory)
    
    IDurDotFactoryUP PUBLIC createDurDotFactory(
        const DurDotFactoryType t = DurDotFactoryType::Standard );

    class PUBLIC IDurDotFactory
    {
    public:
        
        virtual ~IDurDotFactory();
        
        virtual IDurDotUP createDurDot(
            const String& durName,
            const int dotCount ) const = 0;
        
        virtual IDurDotUP createDurDot(
            const String& durName ) const = 0;
        
        virtual IDurDotUP createDurDot() const = 0;
    };
}
