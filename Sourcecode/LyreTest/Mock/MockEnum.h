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
            Integer getValue() const { return myValue; }
            void setValue( const Integer val ) { myValue = val; }
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