//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    enum class PUBLIC DurBaseFactoryType
    {
        Standard = 0
    };
    
    FORWARD_DECLARE(IDurBase)
    FORWARD_DECLARE(IDurBaseFactory)
    
    IDurBaseFactoryUP PUBLIC createDurBaseFactory( const DurBaseFactoryType t );
    
    class PUBLIC IDurBaseFactory
    {
    public:
        
        virtual ~IDurBaseFactory();
        
        virtual IDurBaseUP createDur( const String& durName ) const = 0;
    };
}
