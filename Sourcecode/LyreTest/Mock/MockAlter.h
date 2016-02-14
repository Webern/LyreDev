//PRIVATE
#pragma once
#include "Lyre/IAlter.h"
#include <iostream>

namespace Lyre
{
    namespace Mock
    {
        class MockAlter : public IAlter
        {
        public:
            IAlterUP clone() const
            {
                IAlterUP value{ new MockAlter{ *this } };
                return value;
            }
            int getValue() const { return myValue; }
            void setValue( const int val ) { myValue = val; }
            int getMin() const { return 0; }
            int getMax() const { return 1; }
            bool parse( const String& str ) { return true; }
            std::ostream& toStream( std::ostream& os ) const { return os << myValue; }
            bool extendedFunction() const { return true; }
            virtual bool isIdenticalTo( const IAlter& other ) const { return true; }
            void increment() { myValue++; }
            void decrement() { myValue--; }
        private:
            int myValue;
        };
    }
}