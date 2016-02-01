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
            /* // void copyTo( std::unique_ptr<T>& output ) const */
            virtual Integer getValue() const { return myValue; }
            virtual void setValue( const Integer pitchValue ) {}
            virtual bool parse( const String& str ) { return true; }
            virtual std::ostream& toStream( std::ostream& os ) const { return os << myValue; }
            /* virtual String toString() const;
             virtual bool isLessThan( const Pitch& other ) const;
             virtual bool isGreaterThan( const Pitch& other ) const;
             virtual bool isEqualTo( const Pitch& other ) const; */
            virtual bool isIdenticalTo( const IPitch& other ) const { return true; }
            virtual Integer getStepValue() const { return 0; }
            virtual void setStepValue( const Integer val ) { myValue = val; }
            virtual void incrementStep() {}
            virtual void decrementStep() {}
            virtual Integer getAlterValue() const { return 0; }
            virtual void setAlterValue( const Integer val ) {}
            virtual void incrementAlter() {}
            virtual void decrementAlter() {}
            virtual Integer getOctaveValue() const { return 0; }
            virtual void setOctaveValue( const Integer val ) {}
            virtual void incrementOctave() {}
            virtual void decrementOctave() {}
        private:
            Integer myValue;
        };
    }
}