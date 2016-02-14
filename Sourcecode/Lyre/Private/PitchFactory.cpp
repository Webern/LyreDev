#include "Lyre/Private/PitchFactory.h"
#include "Lyre/Private/Pitch.h"

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
    }
}
