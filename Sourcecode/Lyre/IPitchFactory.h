//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IPitch.h"
#include <memory>

namespace Lyre
{
    class IPitchFactory;
    using IPitchFactorySP = std::shared_ptr<IPitchFactory>;
    using IPitchFactoryUP = std::unique_ptr<IPitchFactory>;
    
    enum class PitchFactoryType
    {
        StandardChromatic = 0
    };
    
    IPitchFactoryUP createPitchFactory( const PitchFactoryType t );
    
    class IPitchFactory
    {
    public:
        virtual ~IPitchFactory() = default;
        
        virtual IPitchUP createPitch() const = 0;
        virtual void setPitch( const Integer pitchValue ) = 0;
        virtual void setPitch( const IPitchUP& pitch ) = 0;
        
        virtual void next() = 0;
        virtual void previous() = 0;
        virtual void add( const Integer value ) = 0;
    };
}
