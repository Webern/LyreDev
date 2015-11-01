//PRIVATE
#pragma once
#include "Lyre/IPitchFactory.h"
#include "LyreTest/Mock/MockPitch.h"

namespace Lyre
{
    namespace Mock
    {
        class MockPitchFactory : public Lyre::IPitchFactory
        {
        public:
            virtual IPitchFactoryUP clone() const
            {
                return std::unique_ptr<MockPitchFactory>{ new MockPitchFactory( *this ) };
            }
            virtual IPitchUP createPitch() const
            {
                return MockPitchUP{ new MockPitch{ myPitch } };
            }
            virtual void setPitch( const Integer pitchValue )
            {
                myPitch.setStepValue( pitchValue );
#if 1==0
                auto octaves = pitchValue / 12;
                octaves -= 1;
                auto p = pitchValue - ( (octaves+1) * 12 );
                switch ( p )
                {
                    case 0:
                        myPitch.setStepValue( 0 );
                        myPitch.setAlterValue( 0 );
                        myPitch.setOctaveValue( octaves );
                        break;
                    case 1:
                        myPitch.setStepValue( 0 );
                        myPitch.setAlterValue( 1 );
                        myPitch.setOctaveValue( octaves );
                        break;
                    case 2:
                        myPitch.setStepValue( 1 );
                        myPitch.setAlterValue( 0 );
                        myPitch.setOctaveValue( octaves );
                        break;
                    case 3:
                        myPitch.setStepValue( 2 );
                        myPitch.setAlterValue( -1 );
                        myPitch.setOctaveValue( octaves );
                        break;
                    case 4:
                        myPitch.setStepValue( 2 );
                        myPitch.setAlterValue( 0 );
                        myPitch.setOctaveValue( octaves );
                        break;
                    case 5:
                        myPitch.setStepValue( 3 );
                        myPitch.setAlterValue( 0 );
                        myPitch.setOctaveValue( octaves );
                        break;
                    case 6:
                        myPitch.setStepValue( 3 );
                        myPitch.setAlterValue( 1 );
                        myPitch.setOctaveValue( octaves );
                        break;
                    case 7:
                        myPitch.setStepValue( 4 );
                        myPitch.setAlterValue( 0 );
                        myPitch.setOctaveValue( octaves );
                        break;
                    case 8:
                        myPitch.setStepValue( 5 );
                        myPitch.setAlterValue( -1 );
                        myPitch.setOctaveValue( octaves );
                        break;
                    case 9:
                        myPitch.setStepValue( 5 );
                        myPitch.setAlterValue( 0 );
                        myPitch.setOctaveValue( octaves );
                        break;
                    case 10:
                        myPitch.setStepValue( 6 );
                        myPitch.setAlterValue( -1 );
                        myPitch.setOctaveValue( octaves );
                        break;
                    case 11:
                        myPitch.setStepValue( 6 );
                        myPitch.setAlterValue( 0 );
                        myPitch.setOctaveValue( octaves );
                        break;
                    default:
                        throw std::runtime_error( "boom" );
                        break;
                }
#endif
            }
            virtual void setPitch( const IPitchUP& pitch )
            {
                if ( pitch )
                {
                    setPitch( pitch->getValue() );
                }
            }
            
            virtual void next() { add( 1 ); }
            virtual void previous() { add( -1 ); }
            virtual void add( const Integer value ) { setPitch( createPitch()->getValue() + value ); }
        private:
            MockPitch myPitch;
        };
    }
}