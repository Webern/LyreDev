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
            int getValue() const { return myValue; }
            void setValue( const int val ) { myValue = val; }
            virtual bool isIdenticalTo( const IStep& other ) const { return true; }
            int getMin() const { return 0; }
            int getMax() const { return 1; }
            bool parse( const String& str ) { return true; }
            std::ostream& toStream( std::ostream& os ) const { return os << myValue; }
            bool extendedFunction() const { return true; }
            void increment() { myValue++; }
            void decrement() { myValue--; }
        private:
            int myValue;
        };
    }
}