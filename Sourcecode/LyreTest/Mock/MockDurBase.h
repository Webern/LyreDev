//PRIVATE
#pragma once

#include "Lyre/IDurBase.h"

namespace Lyre
{
    namespace Mock
    {
        class MockDurBase;
        using MockDurBaseSP = std::shared_ptr<MockDurBase>;
        using MockDurBaseUP = std::unique_ptr<MockDurBase>;
        
        Lyre::IDurBaseUP createMockDurBase( const Rational value, const String name );
        
        class MockDurBase : public Lyre::IDurBase
        {
        public:
            virtual ~MockDurBase() {}
            MockDurBase( const Rational value, const String name );
            virtual IDurBaseUP clone() const;
            Rational getValue() const;
            std::ostream& toStream( std::ostream& os ) const;
        private:
            Lyre::Rational myRational;
            String myName;
        };
    }
}