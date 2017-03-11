//PRIVATE
#pragma once

#include "Lyre/IPitchName.h"

namespace Lyre
{
    namespace Mock
    {
        class MockPitchName;
        using MockPitchNameUP = std::unique_ptr<MockPitchName>;
        class MockPitchName : public IPitchName
        {
        public:
            virtual ~MockPitchName() {}
            virtual IPitchNameUP clone() const { return MockPitchNameUP{ new MockPitchName{} }; }
            virtual int getValue() const { return 0; }
            virtual bool parse( const String& str ) { UNUSED_PARAMETER( str ) return true; }
            virtual std::ostream& toStream( std::ostream& os ) const { return os; }
            /* virtual String toString() const;
             virtual bool isLessThan( const PitchName& other ) const;
             virtual bool isGreaterThan( const PitchName& other ) const;
             virtual bool isEqualTo( const PitchName& other ) const; */
            virtual bool isIdenticalTo( const IPitchName& other ) const { UNUSED_PARAMETER( other ) return true; }
            virtual int getStepValue() const { return 0; }
            virtual void setStepValue( const int val ) { UNUSED_PARAMETER( val ) }
            virtual int getMinStepValue() const { return 0; }
            virtual int getMaxStepValue() const { return 0; }
            virtual void incrementStep() {}
            virtual void decrementStep() {}
            virtual int getAlterValue() const { return 0; }
            virtual void setAlterValue( const int val ) { UNUSED_PARAMETER( val ) }
            virtual int getMinAlterValue() const { return 0; }
            virtual int getMaxAlterValue() const { return 0; }
            virtual void incrementAlter() {}
            virtual void decrementAlter() {}
        };
    }
}