#include "Lyre/Private/Duration.h"
#include <sstream>

namespace Lyre
{
    namespace Private
    {
        Duration::Duration( const String& durName )
        : myDurBaseFactory( IDurBaseFactory::createDurBaseFactory( DurBaseFactoryType::Standard ) )
        , myDurBase( nullptr )
        , myDotCount( 0 )
        {
            setDurBase( durName );
        }
        
        Duration::Duration( const String& durName,
                           const Integer dotCount )
        : myDurBaseFactory( IDurBaseFactory::createDurBaseFactory( DurBaseFactoryType::Standard ) )
        , myDurBase( nullptr )
        , myDotCount( 0 )
        {
            setDurBase( durName );
            setDotCount( dotCount );
        }
        
        Duration::~Duration() {}
        
        IDurationUP Duration::clone() const
        {
            return IDurationUP{ new Duration{ "Quarter" } };
        }
        
        void Duration::copyTo( IDurationUP& output ) const
        {
            output = IDurationUP{ new Duration{ "Quarter" } };
        }
        
        Rational Duration::getValue() const
        {
            Rational temp = myDurBase->getValue();
            Rational additional = myDurBase->getValue();
            for ( Integer i = 0; i < getDotCount(); ++i )
            {
                additional *= Rational{ 1, 2 };
                temp += additional;
            }
            return temp;
        }
        
        Rational Duration::getDurBaseValue() const
        {
            return myDurBase->getValue();
        }
        
        Integer Duration::getDotCount() const
        {
            return myDotCount;
        }
        
        void Duration::setDotCount( const Integer dots )
        {
            if ( dots < 0 )
            {
                myDotCount = 0;
                return;
            }
            if ( dots > DURATION_MAX_DOTS )
            {
                std::stringstream ss;
                ss << "too many dots. max dots is " << DURATION_MAX_DOTS;
                THROW( ( ss.str() ) )
            }
            myDotCount = dots;
        }
        
        std::ostream& Duration::toStream( std::ostream& os ) const
        {
            os << ( *myDurBase );
            for ( Integer i = 0; i < getDotCount(); ++i )
            {
                os << ".";
            }
            return os;
        }
        
        std::ostream& Duration::durBaseToStream( std::ostream& os ) const
        {
            return os << ( *myDurBase );
        };
        
        String Duration::toString() const
        {
            std::stringstream ss;
            toStream( ss );
            return ss.str();
        }
        
        String Duration::durBaseToString() const
        {
            return myDurBase->toString();
        }
        
        bool Duration::isEqualTo( const IDuration& other ) const
        {
            return getValue() == other.getValue();
        }
        
        bool Duration::isGreaterThan( const IDuration& other ) const
        {
            return getValue() > other.getValue();
        }
        
        bool Duration::isLessThan( const IDuration& other ) const
        {
            return getValue() < other.getValue();
        }
        
        void Duration::setDurBase( const String& durName )
        {
            auto temp = myDurBaseFactory->createDur( durName );
            if ( temp )
            {
                myDurBase = std::move( temp );
            }
        }
    }
}
