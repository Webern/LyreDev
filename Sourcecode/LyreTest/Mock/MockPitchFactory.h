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