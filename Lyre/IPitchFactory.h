#pragma once
#include "TypeDefs.h"
#include <memory>
#include "IPitch.h"

namespace lyre
{
    class IPitchFactory;
    using IPitchFactoryPtr = std::shared_ptr<IPitchFactory>;
    using IPitchFactoryUPtr = std::unique_ptr<IPitchFactory>;
    
    class IPitchFactory
    {
    public:
        virtual ~IPitchFactory() = default;
        
        /* return a deep copy of "this" */
        virtual IPitchFactoryUPtr clone() const = 0;
        
        /* deep copy to "output", note
         the use of static_cast, be careful */
        template <typename T>
        void copyTo( std::unique_ptr<T>& output ) const
        {
            output = std::move( std::unique_ptr<T>{ new T{ *(static_cast<T*>( clone().get() )) } } );
        }
        
        virtual IPitchUPtr makePitch() const = 0;
        virtual void setPitch( const Integer pitchValue ) = 0;
        virtual void setPitch( const IPitchUPtr& pitch ) = 0;
        
        virtual void next() = 0;
        virtual void previous() = 0;
        virtual void add( const Integer value ) = 0;
    };
}