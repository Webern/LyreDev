#include "Lyre/Private/TupletDef.h"
#include "Lyre/Private/DurDot.h"
#include "Lyre/IDurDotFactory.h"
#include "Lyre/IDurDot.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        TupletDef::TupletDef(
            const Integer count,
            const Lyre::IDurDot& countType,
            const Integer inTheSpaceOf,
            const Lyre::IDurDot& inTheSpaceOfType )
        :myCount( 1 )
        ,myCountType( nullptr )
        ,myInTheSpaceOf( 1 )
        ,myInTheSpaceOfType( nullptr )
        {
            constructor(
                count, countType.getDurBaseName(), countType.getDotCount(),
                inTheSpaceOf, inTheSpaceOfType.getDurBaseName(), inTheSpaceOfType.getDotCount() );
        }
        
        TupletDef::TupletDef(
                  const Integer count,
                  const Integer inTheSpaceOf,
                  const IDurDot& durationType )
        :myCount( 1 )
        ,myCountType( nullptr )
        ,myInTheSpaceOf( 1 )
        ,myInTheSpaceOfType( nullptr )
        {
            constructor(
                count, durationType.getDurBaseName(), durationType.getDotCount(),
                inTheSpaceOf, durationType.getDurBaseName(), durationType.getDotCount() );
        }
        
        TupletDef::TupletDef(
                  const Integer count,
                  const Integer inTheSpaceOf,
                  const String& durBaseName )
        :myCount( 1 )
        ,myCountType( nullptr )
        ,myInTheSpaceOf( 1 )
        ,myInTheSpaceOfType( nullptr )
        {
            constructor(
                count, durBaseName, 0,
                inTheSpaceOf, durBaseName, 0 );
        }
        
        void TupletDef::constructor(
            const Integer count,
            const String& countTypeName,
            const Integer countTypeDots,
            const Integer itso,
            const String& itsoType,
            const Integer itsoDots )
        {
            throwIfNonPositive( count );
            throwIfNonPositive( itso );
            myCount = count;
            myInTheSpaceOf = itso;
            auto factory = createDurDotFactory( DurDotFactoryType::Standard );
            myCountType = factory->createDurDot( countTypeName, countTypeDots );
            myInTheSpaceOfType = factory->createDurDot( itsoType, itsoDots );
            nullCheckThrow();
        }
        
        void TupletDef::throwIfNull( const IDurDotUP& up ) const
        {
            if ( up == nullptr )
            {
                THROW( "null pointer encountered" )
            }
        }
        
        void TupletDef::throwIfNonPositive( const Integer value ) const
        {
            if ( value < 1 )
            {
                THROW( "value must be positive" )
            }
        }
        
        void TupletDef::nullCheckThrow() const
        {
            throwIfNull( myCountType );
            throwIfNull( myInTheSpaceOfType );
        }
        
        ITupletDefUP TupletDef::clone() const
        {
            nullCheckThrow();
            return ITupletDefUP{ new TupletDef( myCount, *myCountType, myInTheSpaceOf, *myInTheSpaceOfType ) };
        }
        
        void TupletDef::copyTo( ITupletDefUP& output ) const
        {
            auto tempP = static_cast<const ITupletDef*>( this );
            Private::copyTo<ITupletDef>( tempP, output );
        }
        
        Rational TupletDef::getMultiplier() const
        {
            auto count = getInTheSpaceOfType()->getValue() * Rational{ getInTheSpaceOf(), 1 };
            auto inTheSpaceOf = getCountType()->getValue() * Rational{ getCount(), 1 };
            return count / inTheSpaceOf;
        }

        Rational TupletDef::getTotalLength() const
        {
            return getInTheSpaceOfType()->getValue() * Rational{ getInTheSpaceOf(), 1 };
        }
        
        Integer TupletDef::getCount() const
        {
            return myCount;
        }
        
        IDurDotUPC TupletDef::getCountType() const
        {
            nullCheckThrow();
            IDurDotUP output;
            myCountType->copyTo( output );
            return std::move( output );
        }
        
        Integer TupletDef::getInTheSpaceOf() const
        {
            return myInTheSpaceOf;
        }
        
        IDurDotUPC TupletDef::getInTheSpaceOfType() const
        {
            nullCheckThrow();
            IDurDotUP output;
            myInTheSpaceOfType->copyTo( output );
            return std::move( output );
        }
        
        std::ostream& TupletDef::toStream( std::ostream& os ) const
        {
            os << myCount;
            os << "[";
            os << (*myCountType);
            os << "]:";
            os << myInTheSpaceOf;
            os << "[";
            os << (*myInTheSpaceOfType);
            os << "]";
            return os << "not implemented";
        }
        
        String TupletDef::toString() const
        {
            return "string not implemented";
        }
    }
}
