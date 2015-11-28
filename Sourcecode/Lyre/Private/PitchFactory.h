//PRIVATE
#pragma once
#include "Lyre/IPitchFactory.h"
#include "Lyre/Private/Pitch.h"

namespace Lyre
{
    namespace Private
    {
        class PitchFactory;
        using PitchFactorySP = std::shared_ptr<PitchFactory>;
        using PitchFactoryUP = std::unique_ptr<PitchFactory>;
        
        class PitchFactory : public IPitchFactory
        {
        public:
            /* return a deep copy of "this" */
            virtual IPitchFactoryUP clone() const;
            
            /* // void copyTo( std::unique_ptr<T>& output ) const; */
            
            virtual IPitchUP createPitch() const;
            virtual void setPitch( const Integer pitchValue );
            virtual void setPitch( const IPitchUP& pitch );
            
            virtual void next();
            virtual void previous();
            virtual void add( const Integer value );
        private:
            Private::Pitch myCurrent;
        };
    }
}
