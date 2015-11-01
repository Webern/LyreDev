//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include <memory>
#include "Lyre/IPitch.h"

namespace Lyre
{
    class IPitchFactory;
    using IPitchFactorySP = std::shared_ptr<IPitchFactory>;
    using IPitchFactoryUP = std::unique_ptr<IPitchFactory>;
    
    enum class PitchFactoryType
    {
        StandardChromatic = 0
    };
    
    class IPitchFactory
    {
    public:
        static IPitchFactoryUP createPitchFactory( const PitchFactoryType t );
        virtual ~IPitchFactory() = default;
        
        /* return a deep copy of "this" */
        virtual IPitchFactoryUP clone() const = 0;
        
        /* deep copy to "output", note
         the use of static_cast, be careful */
        template <typename T>
        void copyTo( std::unique_ptr<T>& output ) const
        {
            output = std::move( std::unique_ptr<T>{ new T{ *(static_cast<T*>( clone().get() )) } } );
        }
        
        virtual IPitchUP createPitch() const = 0;
        virtual void setPitch( const Integer pitchValue ) = 0;
        virtual void setPitch( const IPitchUP& pitch ) = 0;
        
        virtual void next() = 0;
        virtual void previous() = 0;
        virtual void add( const Integer value ) = 0;
    };
}