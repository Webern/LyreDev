//PRIVATE
#pragma once
#include "Lyre/IPitchFactory.h"
#include "Lyre/Private/Pitch.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(PitchFactory)
        
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
