#include "MockDur.h"

namespace Lyre
{
    namespace Mock
    {
        Lyre::IDurUP createMockDur( const Rational value, const String name )
        {
            return IDurUP{ new MockDur{ value, name } };
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