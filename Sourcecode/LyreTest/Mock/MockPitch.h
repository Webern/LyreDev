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
            virtual void setValue( const int pitchValue ) {}
            virtual bool parse( const String& str ) { return true; }
            virtual std::ostream& toStream( std::ostream& os ) const { return os << myValue; }
            /* virtual String toString() const;
             virtual bool isLessThan( const Pitch& other ) const;
             virtual bool isGreaterThan( const Pitch& other ) const;
             virtual bool isEqualTo( const Pitch& other ) const; */
            virtual bool isIdenticalTo( const IPitch& other ) const { return true; }
            virtual int getStepValue() const { return 0; }
            virtual void setStepValue( const int val ) { myValue = val; }
            virtual void incrementStep() {}
            virtual void decrementStep() {}
            virtual int getAlterValue() const { return 0; }
            virtual void setAlterValue( const int val ) {}
            virtual void incrementAlter() {}
            virtual void decrementAlter() {}
            virtual int getOctaveValue() const { return 0; }
            virtual void setOctaveValue( const int val ) {}
            virtual void incrementOctave() {}
            virtual void decrementOctave() {}
        private:
            int myValue;
        };
    }
}