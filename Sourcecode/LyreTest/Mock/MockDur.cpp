#include "MockDur.h"

namespace Lyre
{
    namespace Mock
    {
        Lyre::IDurSP createMockDur( const Rational value, const String name )
        {
            return std::make_shared<MockDur>( value, name );
        }
        
        
        MockDur::MockDur( const Rational value, const String name )
        :myRational( value )
        ,myName( name )
        {}
        
        Rational MockDur::getValue() const
        {
            return myRational;
        }
        
        std::ostream& MockDur::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}