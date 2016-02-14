//PRIVATE
#pragma once
#include "Lyre/IPitchFactory.h"
#include "Lyre/Private/Pitch.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(PitchFactory)
        
        class EXPORT_FOR_TESTS PitchFactory : public IPitchFactory
        {
        public:
            /* return a deep copy of "this" */
            virtual IPitchFactoryUP clone() const;
            
            virtual IPitchUP createPitch() const;
            virtual void setPitch( const int pitchValue );
            virtual void setPitch( const IPitchUP& pitch );
            
            virtual void next();
            virtual void previous();
            virtual void add( const int value );
        private:
            Private::Pitch myCurrent;
        };
    }
}
