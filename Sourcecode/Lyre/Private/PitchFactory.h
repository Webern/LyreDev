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
            
            virtual IPitchUP createPitch( const int pitchValue ) const;
            virtual IPitchUP createPitch( const IPitchUP& pitch ) const;
            virtual IPitchUP createPitch( const String& pitchString ) const;
            virtual IPitchUP createPitch( int step, int alter, int octave ) const;
            
        private:
            Private::Pitch myCurrent;
        };
    }
}
