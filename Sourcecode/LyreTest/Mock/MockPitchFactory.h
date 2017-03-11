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
            virtual void setPitch( const int pitchValue )
            {
                myPitch.setStepValue( pitchValue );
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
            virtual void add( const int value ) { setPitch( createPitch()->getValue() + value ); }

			virtual IPitchUP createPitch( const int pitchValue ) const { UNUSED_PARAMETER( pitchValue ) return createPitch(); }
			virtual IPitchUP createPitch( const IPitchUP& pitch ) const { UNUSED_PARAMETER( pitch ) return createPitch(); }
			virtual IPitchUP createPitch( const String& pitchString ) const { UNUSED_PARAMETER( pitchString ) return createPitch(); }
			virtual IPitchUP createPitch( int step, int alter, int octave ) const { UNUSED_PARAMETER( step ) UNUSED_PARAMETER( alter ) UNUSED_PARAMETER( octave ) return createPitch(); }
        private:
            MockPitch myPitch;
        };
    }
}