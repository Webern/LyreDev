#include "Lyre/Private/DurDot.h"
#include "Lyre/Private/throw.h"
#include <sstream>

namespace Lyre
{
    namespace Private
    {
        DurDot::DurDot()
        : myDurBaseFactory( createDurBaseFactory( DurBaseFactoryType::Standard ) )
        , myDurBase( nullptr )
        , myDotCount( 0 )
        {
            setDurBase( "Quarter" );
        }
        
        DurDot::DurDot( const String& durName )
        : myDurBaseFactory( createDurBaseFactory( DurBaseFactoryType::Standard ) )
        , myDurBase( nullptr )
        , myDotCount( 0 )
        {
            setDurBase( durName );
        }
        
        DurDot::DurDot( const String& durName,
                           const Integer dotCount )
        : myDurBaseFactory( createDurBaseFactory( DurBaseFactoryType::Standard ) )
        , myDurBase( nullptr )
        , myDotCount( 0 )
        {
            setDurBase( durName );
            setDotCount( dotCount );
        }
        
        DurDot::~DurDot() {}
        
        IDurDotUP DurDot::clone() const
        {   
            return IDurDotUP{ new DurDot{ getDurBaseName(), getDotCount() } };
        }
        
//        void DurDot::copyTo( IDurDotUP& output ) const
//        {
//            auto tempP = static_cast<const IDurDot*>( this );
//            Private::copyTo<IDurDot>( tempP, output );
//        }
        
        Rational DurDot::getValue() const
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
        
        Rational DurDot::getDurBaseValue() const
        {
            return myDurBase->getValue();
        }
        
        Integer DurDot::getDotCount() const
        {
            return myDotCount;
        }
        
        void DurDot::setDotCount( const Integer dots )
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
        
        std::ostream& DurDot::toStream( std::ostream& os ) const
        {
            os << ( *myDurBase );
            for ( Integer i = 0; i < getDotCount(); ++i )
            {
                os << ".";
            }
            return os;
        }
        
        std::ostream& DurDot::durBaseToStream( std::ostream& os ) const
        {
            return os << ( *myDurBase );
        };
        
        String DurDot::toString() const
        {
            std::stringstream ss;
            toStream( ss );
            return ss.str();
        }
        
        String DurDot::getDurBaseName() const
        {
            return myDurBase->toString();
        }
        
        bool DurDot::isEqualTo( const IDurDot& other ) const
        {
            return getValue() == other.getValue();
        }
        
        bool DurDot::isGreaterThan( const IDurDot& other ) const
        {
            return getValue() > other.getValue();
        }
        
        bool DurDot::isLessThan( const IDurDot& other ) const
        {
            return getValue() < other.getValue();
        }
        
        void DurDot::setDurBase( const String& durName )
        {
            auto temp = myDurBaseFactory->createDur( durName );
            if ( temp )
            {
                myDurBase = std::move( temp );
            }
        }
    }
}
