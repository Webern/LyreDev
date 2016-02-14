//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPitch.h"

namespace Lyre
{
    FORWARD_DECLARE(IPitchFactory)
    
    enum class PUBLIC PitchFactoryType
    {
        StandardChromatic = 0
    };
    
    IPitchFactoryUP PUBLIC createPitchFactory( const PitchFactoryType t );
    
    class PUBLIC IPitchFactory
    {
    public:
        virtual ~IPitchFactory() = default;
        
        virtual IPitchUP createPitch() const = 0;
        virtual void setPitch( const int pitchValue ) = 0;
        virtual void setPitch( const IPitchUP& pitch ) = 0;
        
        virtual void next() = 0;
        virtual void previous() = 0;
        virtual void add( const int value ) = 0;
    };
}
