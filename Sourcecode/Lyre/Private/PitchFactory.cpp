#include "Lyre/Private/PitchFactory.h"
#include "Lyre/Private/Pitch.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        IPitchFactoryUP PitchFactory::clone() const
        {
            return IPitchFactoryUP( new PitchFactory( *this ) );
        }
        
        IPitchUP PitchFactory::createPitch() const
        {
            return IPitchUP( new Pitch( myCurrent ) );
        }
        void PitchFactory::setPitch( const int pitchValue )
        {
            myCurrent.setValue( pitchValue );
        }
        void PitchFactory::setPitch( const IPitchUP& pitch )
        {
            if ( pitch )
            {
                myCurrent.setAlterValue( pitch->getAlterValue() );
                myCurrent.setStepValue( pitch->getStepValue() );
                myCurrent.setOctaveValue( pitch->getOctaveValue() );
            }
            
        }
        void PitchFactory::next()
        {
            setPitch( myCurrent.getValue() + 1 );
        }
        void PitchFactory::previous()
        {
            setPitch( myCurrent.getValue() - 1 );
        }
        void PitchFactory::add( const int value )
        {
            setPitch( myCurrent.getValue() + value );
        }
        
        IPitchUP PitchFactory::createPitch( const int pitchValue ) const
        {
            IPitchUP pitch = IPitchUP{ new Pitch{} };
            pitch->setValue( pitchValue );
            return std::move( pitch );
        }
        
        IPitchUP PitchFactory::createPitch( const IPitchUP& pitch ) const
        {
            THROW_IF_NULL( pitch )
            auto step = pitch->getStepValue();
            auto alter = pitch->getAlterValue();
            auto octave = pitch->getOctaveValue();
            IPitchUP newPitch = IPitchUP{ new Pitch{ step, alter, octave } };
            return std::move( newPitch );
        }
        
        IPitchUP PitchFactory::createPitch( const String& pitchString ) const
        {
            IPitchUP pitch = IPitchUP{ new Pitch{ pitchString } };
            return std::move( pitch );
        }
        
        IPitchUP PitchFactory::createPitch(
            int step,
            int alter,
            int octave ) const
        {
            IPitchUP newPitch = IPitchUP{ new Pitch{ step, alter, octave } };
            return std::move( newPitch );
        }
    }
}
