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
        void PitchFactory::setPitch( const Integer pitchValue )
        {
            if ( pitchValue != myCurrent.getValue() )
            {
                //TODO Test Correctness of Algorithm
                //TODO Better Algorithm
                Integer increment = 1;
                if ( pitchValue < myCurrent.getValue() )
                {
                    increment = -1;
                }
                for ( Integer i = myCurrent.getValue(); i != pitchValue; i += increment )
                {
                    if ( increment == 1 )
                    {
                        myCurrent.incrementAlter();
                    }
                    else if ( increment == -1 )
                    {
                        myCurrent.decrementAlter();
                    }
                }
                //TODO Respell
            }
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
            //TODO better algorithm
            setPitch( myCurrent.getValue() + 1 );
        }
        void PitchFactory::previous()
        {
            //TODO better algorithm
            setPitch( myCurrent.getValue() - 1 );
        }
        void PitchFactory::add( const Integer value )
        {
            //TODO better algorithm
            setPitch( myCurrent.getValue() + value );
        }
    }
}