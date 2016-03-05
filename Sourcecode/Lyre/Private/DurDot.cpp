#include "Lyre/Private/DurDot.h"
#include "Lyre/Private/throw.h"
#include "Lyre/Private/DurBaseQuarter.h"
#include <sstream>

namespace Lyre
{
    namespace Private
    {
		IDurBaseFactoryUP DurDot::ourDurBaseFactory = createDurBaseFactory();

        DurDot::DurDot()
        : myDurBase( new DurBaseQuarter{} )
        , myDotCount( 0 )
        {

        }
        
        DurDot::DurDot( const String& durName )
        : myDurBase( nullptr )
        , myDotCount( 0 )
        {
			setDurBase( durName );
        }
        
        DurDot::DurDot(
			const String& durName,
			const int dotCount )
        : myDurBase( nullptr )
        , myDotCount( 0 )
        {
            setDurBase( durName );
            setDotCount( dotCount );
        }
        
        DurDot::~DurDot() {}
        
        IDurDotUP DurDot::clone() const
        {   
			DurDot* newP = new DurDot();
			newP->myDotCount = this->myDotCount;
			newP->myDurBase = this->myDurBase->clone();
			auto ret = IDurDotUP{ newP };
			return std::move( ret );
        }
        
        Rational DurDot::getValue() const
        {
            Rational temp = myDurBase->getValue();
            Rational additional = myDurBase->getValue();
            for ( int i = 0; i < getDotCount(); ++i )
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
        
        int DurDot::getDotCount() const
        {
            return myDotCount;
        }
        
        void DurDot::setDotCount( const int dots )
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
            for ( int i = 0; i < getDotCount(); ++i )
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
            auto temp = ourDurBaseFactory->createDur( durName );
            if ( temp )
            {
                myDurBase = std::move( temp );
            }
        }
    }
}
