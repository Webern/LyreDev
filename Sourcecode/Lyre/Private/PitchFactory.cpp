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
                while ( myCurrent.getAlterValue() >= 12 )
                {
                    myCurrent.incrementOctave();
                    myCurrent.setAlterValue( myCurrent.getAlterValue() - 12 );
                }
                while ( myCurrent.getAlterValue() > 1 )
                {
                    auto curStep = myCurrent.getStepValue();
                    if ( curStep != 2 && curStep != 6 )
                    {
                        myCurrent.decrementAlter();
                    }
                    myCurrent.decrementAlter();
                    if ( curStep == 6 )
                    {
                        myCurrent.incrementOctave();
                    }
                    if ( curStep == 6 )
                    {
                        curStep = 0;
                    }
                    else
                    {
                        ++curStep;
                    }
                    myCurrent.setStepValue( curStep );
                }
                while ( myCurrent.getAlterValue() <= -12 )
                {
                    myCurrent.decrementOctave();
                    myCurrent.setAlterValue( myCurrent.getAlterValue() + 12 );
                }
                while ( myCurrent.getAlterValue() < -1 )
                {
                    auto curStep = myCurrent.getStepValue();
                    if ( curStep != 0 && curStep != 3 )
                    {
                        myCurrent.incrementAlter();
                    }
                    myCurrent.incrementAlter();
                    if ( curStep == 0 )
                    {
                        myCurrent.decrementOctave();
                    }
                    if ( curStep == 0 )
                    {
                        curStep = 6;
                    }
                    else
                    {
                        --curStep;
                    }
                    myCurrent.setStepValue( curStep );
                }
            }
            int step = myCurrent.getStepValue();
            int alter = myCurrent.getAlterValue();
            switch ( step )
            {
                case 0:
                {
                    if ( alter == -1 ) // change Cb to B
                    {
                        myCurrent.decrementOctave();
                        myCurrent.setStepValue( 6 );
                        myCurrent.setAlterValue( 0 );
                    }
                }
                    break;
                case 1:
                {
                    if ( alter == -1 ) // change Db to C#
                    {
                        myCurrent.setStepValue( 0 );
                        myCurrent.setAlterValue( 1 );
                    }
                    if ( alter == 1 ) // change D# to Eb
                    {
                        myCurrent.setStepValue( 2 );
                        myCurrent.setAlterValue( -1 );
                    }
                }
                    break;
                case 2:
                {
                    if ( alter == 1 ) // change E# to F
                    {
                        myCurrent.setStepValue( 3 );
                        myCurrent.setAlterValue( 0 );
                    }
                }
                    break;
                case 3:
                {
                    if ( alter == -1 ) // change Fb to E
                    {
                        myCurrent.setStepValue( 2 );
                        myCurrent.setAlterValue( 0 );
                    }
                }
                    break;
                case 4:
                {
                    if ( alter == -1 ) // change Gb to F#
                    {
                        myCurrent.setStepValue( 3 );
                        myCurrent.setAlterValue( 1 );
                    }
                    if ( alter == 1 ) // change G# to Ab
                    {
                        myCurrent.setStepValue( 5 );
                        myCurrent.setAlterValue( -1 );
                    }
                }
                    break;
                case 5:
                {
                    if ( alter == 1 ) // change A# to Bb
                    {
                        myCurrent.setStepValue( 6 );
                        myCurrent.setAlterValue( -1 );
                    }
                }
                    break;
                case 6:
                {
                    if ( alter == 1 ) // change B# to C
                    {
                        myCurrent.incrementOctave();
                        myCurrent.setStepValue( 0 );
                        myCurrent.setAlterValue( 0 );
                    }
                }
                    break;
                default:
                    break;
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
