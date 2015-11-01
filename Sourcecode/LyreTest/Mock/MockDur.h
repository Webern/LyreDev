//PRIVATE
#pragma once

#include "Lyre/IDur.h"

namespace Lyre
{
    namespace Mock
    {
        class MockDur;
        using MockDurSP = std::shared_ptr<MockDur>;
        using MockDurUP = std::unique_ptr<MockDur>;
        
        Lyre::IDurUP createMockDur( const Rational value, const String name );
        
        class MockDur : public Lyre::IDur
        {
        public:
            MockDur( const Rational value, const String name );
            Rational getValue() const;
            std::ostream& toStream( std::ostream& os ) const;
        private:
            Lyre::Rational myRational;
            String myName;
        };
    }
}