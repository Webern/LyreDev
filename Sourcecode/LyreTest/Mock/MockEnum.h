//PRIVATE
#pragma once
#include "Lyre/IEnum.h"
#include <iostream>

namespace Lyre
{
    namespace Mock
    {
        class MockEnum : public IEnum
        {
        public:
            IEnumUP clone() const
            {
                IEnumUP value{ new MockEnum{ *this } };
                return value;
            }
            int getValue() const { return myValue; }
            void setValue( const int val ) { myValue = val; }
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