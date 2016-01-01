//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include <memory>

namespace Lyre
{
    enum class DurBaseFactoryType
    {
        Standard = 0
    };
    
    class IDurBase;
    using IDurBaseSP = std::shared_ptr<IDurBase>;
    using IDurBaseUP = std::unique_ptr<IDurBase>;
    
    class IDurBaseFactory;
    using IDurBaseFactorySP = std::shared_ptr<IDurBaseFactory>;
    using IDurBaseFactoryUP = std::unique_ptr<IDurBaseFactory>;
    
    IDurBaseFactoryUP createDurBaseFactory( const DurBaseFactoryType t );
    
    class IDurBaseFactory
    {
    public:
        
        virtual ~IDurBaseFactory();
        
        virtual IDurBaseUP createDur( const String& durName ) const = 0;
    };
}
