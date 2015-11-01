//PRIVATE
#pragma once

#include "Lyre/IStep.h"

namespace Lyre
{
    namespace Mock
    {
        class MockStep : public IStep
        {
        public:
            IStepUP clone() const
            {
                IStepUP value{ new MockStep{ *this } };
                return value;
            }
            Integer getValue() const { return myValue; }
            void setValue( const Integer val ) { myValue = val; }
            virtual bool isIdenticalTo( const IStep& other ) const { return true; }
            Integer getMin() const { return 0; }
            Integer getMax() const { return 1; }
            bool parse( const String& str ) { return true; }
            std::ostream& toStream( std::ostream& os ) const { return os << myValue; }
            bool extendedFunction() const { return true; }
            void increment() { myValue++; }
            void decrement() { myValue--; }
        private:
            Integer myValue;
        };
    }
}