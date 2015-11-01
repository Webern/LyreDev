//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include <memory>

namespace Lyre
{
    enum class DurFactoryType
    {
        Standard = 0
    };
    
    // Forward Declarations
    class IDur;
    using IDurSP = std::shared_ptr<IDur>;
    using IDurUP = std::unique_ptr<IDur>;
    
    class IDurFactory;
    using IDurFactorySP = std::shared_ptr<IDurFactory>;
    using IDurFactoryUP = std::unique_ptr<IDurFactory>;
    
    class IDurFactory
    {
    public:
        
        virtual ~IDurFactory();
        
        static IDurFactorySP createDurFactory( const DurFactoryType t );
        
        virtual IDurSP createDur( const String& durName ) const = 0;
    };
}
