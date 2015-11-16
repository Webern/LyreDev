#include "MockDurBase.h"
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Mock
    {
        Lyre::IDurBaseUP createMockDurBase( const Rational value, const String name )
        {
            return Private::makeUnique<MockDurBase>( value, name );
        }
        
        IDurBaseUP MockDurBase::clone() const
        {
            return Private::makeUnique<MockDurBase>( myRational, myName );
        }
        
        void MockDurBase::copyTo( IDurBaseUP& output ) const
        {
            auto temp = Private::makeUnique<MockDurBase>( myRational, myName );
            Private::copyTo<IDurBase>( temp.get(), output );
        }
        
        MockDurBase::MockDurBase( const Rational value, const String name )
        :myRational( value )
        ,myName( name )
        {}
        
        Rational MockDurBase::getValue() const
        {
            return myRational;
        }
        
        std::ostream& MockDurBase::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
    }
}