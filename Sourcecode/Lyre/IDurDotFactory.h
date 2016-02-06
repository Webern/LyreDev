//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDurDot.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    enum class PUBLIC DurDotFactoryType
    {
        Standard = 0
    };
    
    FORWARD_DECLARE(IDurDot)
    FORWARD_DECLARE(IDurDotFactory)
    
    IDurDotFactoryUP PUBLIC createDurDotFactory( const DurDotFactoryType t );

    class PUBLIC IDurDotFactory
    {
    public:
        
        virtual ~IDurDotFactory();
        
        virtual IDurDotUP createDurDot(
            const String& durName,
            const Integer dotCount ) const = 0;
        
        virtual IDurDotUP createDurDot(
            const String& durName ) const = 0;
        
        virtual IDurDotUP createDurDot() const = 0;
    };
}
