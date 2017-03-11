//PRIVATE
#pragma once
#include "Lyre/IPitch.h"

namespace Lyre
{
    namespace Mock
    {
        class MockPitch;
        using MockPitchUP = std::unique_ptr<MockPitch>;
        class MockPitch : public IPitch
        {
        public:
            MockPitch() : myValue(0) {}
            virtual ~MockPitch() {}
            virtual IPitchUP clone() const { return MockPitchUP{ new MockPitch{} }; }
            virtual int getValue() const { return myValue; }
            virtual void setValue( const int pitchValue ) { UNUSED_PARAMETER( pitchValue ) }
            virtual bool parse( const String& str ) { UNUSED_PARAMETER( str ) return true; }
            virtual std::ostream& toStream( std::ostream& os ) const { UNUSED_PARAMETER( os ) return os << myValue; }
            /* virtual String toString() const;
             virtual bool isLessThan( const Pitch& other ) const;
             virtual bool isGreaterThan( const Pitch& other ) const;
             virtual bool isEqualTo( const Pitch& other ) const; */
            virtual bool isIdenticalTo( const IPitch& other ) const { UNUSED_PARAMETER( other ) return true; }
            virtual int getStepValue() const { return 0; }
            virtual void setStepValue( const int val ) { myValue = val; }
            virtual void incrementStep() {}
            virtual void decrementStep() {}
            virtual int getAlterValue() const { return 0; }
            virtual void setAlterValue( const int val ) { UNUSED_PARAMETER( val ) }
            virtual void incrementAlter() {}
            virtual void decrementAlter() {}
            virtual int getOctaveValue() const { return 0; }
            virtual void setOctaveValue( const int val ) { UNUSED_PARAMETER( val ) }
            virtual void incrementOctave() {}
            virtual void decrementOctave() {}
        private:
            int myValue;
        };
    }
}