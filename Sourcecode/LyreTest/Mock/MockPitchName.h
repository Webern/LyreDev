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
            /* template <typename T>
             // void copyTo( std::unique_ptr<T>& output ) const */
            virtual Integer getValue() const { return 0; }
            virtual bool parse( const String& str ) { return true; }
            virtual std::ostream& toStream( std::ostream& os ) const { return os; }
            /* virtual String toString() const;
             virtual bool isLessThan( const PitchName& other ) const;
             virtual bool isGreaterThan( const PitchName& other ) const;
             virtual bool isEqualTo( const PitchName& other ) const; */
            virtual bool isIdenticalTo( const IPitchName& other ) const { return true; }
            virtual Integer getStepValue() const { return 0; }
            virtual void setStepValue( const Integer val ) {}
            virtual Integer getMinStepValue() const { return 0; }
            virtual Integer getMaxStepValue() const { return 0; }
            virtual void incrementStep() {}
            virtual void decrementStep() {}
            virtual Integer getAlterValue() const { return 0; }
            virtual void setAlterValue( const Integer val ) {}
            virtual Integer getMinAlterValue() const { return 0; }
            virtual Integer getMaxAlterValue() const { return 0; }
            virtual void incrementAlter() {}
            virtual void decrementAlter() {}
        };
    }
}