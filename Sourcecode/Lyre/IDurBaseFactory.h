//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    enum class DurBaseFactoryType
    {
        Standard = 0
    };
    
    FORWARD_DECLARE(IDurBase)
    FORWARD_DECLARE(IDurBaseFactory)
    
    IDurBaseFactoryUP createDurBaseFactory( const DurBaseFactoryType t );
    
    class IDurBaseFactory
    {
    public:
        
        virtual ~IDurBaseFactory();
        
        virtual IDurBaseUP createDur( const String& durName ) const = 0;
    };
}
